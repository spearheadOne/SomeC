#!/usr/bin/env python3
"""Build and run all portable demos in a temporary directory (Python 3)."""
import argparse
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
DEMOS = {
    'base_staff/basics': 'base',
    'base_staff/bit_ops': 'bitops',
    'base_staff/concat_files': 'concat',
    'base_staff/input_counter': 'inputCounter',
    'base_staff/keywords': 'keywords',
    'base_staff/line_sort': 'lineSort',
    'base_staff/long_line': 'longLine',
    'base_staff/sort': 'sort',
    'data_structures/linked_list': 'll',
    'data_structures/double_linked_list': 'dll',
    'data_structures/circular_list': 'cll',
    'data_structures/chained_hashtable': 'cht',
    'data_structures/set': 'st',
    'data_structures/stack': 'st',
    'data_structures/queue': 'qu',
    'encryption': 'enc',
}


def run(args, cwd, data='', code=0):
    result = subprocess.run(args, cwd=cwd, input=data, text=True,
                            capture_output=True, timeout=15)
    if result.returncode != code or result.stderr:
        raise AssertionError(f'{cwd}: {args}\nexit {result.returncode}\n'
                             f'{result.stdout}{result.stderr}')
    return result.stdout


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sanitize', action='store_true',
                        help='enable address and undefined-behavior sanitizers')
    args = parser.parse_args()
    count = 0
    with tempfile.TemporaryDirectory(prefix='somec-smoke-') as temp:
        root = Path(temp)
        for directory in DEMOS:
            src = ROOT / directory
            dst = root / directory
            dst.mkdir(parents=True)
            for path in src.iterdir():
                if path.suffix in ('.c', '.h') or path.name == 'Makefile':
                    shutil.copy2(path, dst / path.name)
            flags = os.environ.get('CFLAGS', '-std=c11 -Wall -Wextra -Werror -g')
            ldflags = os.environ.get('LDFLAGS', '')
            if args.sanitize:
                flags += ' -fsanitize=address,undefined -fno-omit-frame-pointer'
                ldflags += ' -fsanitize=address,undefined'
            run(['make', f'CFLAGS={flags}', f'LDFLAGS={ldflags}'], dst)
            print(f'Built {directory}', flush=True)

        def check(directory, arguments=(), data='', expected=()):
            nonlocal count
            output = run([f'./{DEMOS[directory]}', *arguments], root / directory, data)
            for text in expected:
                assert text in output, (directory, arguments, text, output)
            count += 1
            return output

        base = 'base_staff/basics'
        for arguments, expected in [
            (['hw'], ['hello world']),
            (['fc'], ['Farenheit-Celsius table', '300']),
            (['bc', '7'], ['is:  3']),
            (['dy', '2024', '3', '1'], ['is 61 day']),
            (['mn', '12'], ['December']),
            (['fac'], ['Factorial of 10 is 3628800', 'Factorial of 12 is 479001600']),
            (['ec', 'hello', 'world'], ['arguments hello world']),
        ]:
            check(base, arguments, expected=expected)
        bits = 'base_staff/bit_ops'
        for mode, expected in [('bg', "'abcde' 0"), ('bs', "'abcde' 1"),
                               ('bx', 'XOR bytes: 00 07 04 0c 0c'), ('br', 'Rotated eghia')]:
            check(bits, [mode], expected=[expected])
        check('base_staff/concat_files', data='hello\nworld\n', expected=['hello\nworld\n'])
        files = root / 'base_staff/concat_files'
        (files / 'one.txt').write_text('one\n')
        (files / 'two.txt').write_text('two\n')
        check('base_staff/concat_files', ['one.txt', 'two.txt'], expected=['one\ntwo\n'])
        check('base_staff/input_counter', data='one  two 123\n',
              expected=['Number of lines 1 Number of words 3 Number of chars 13'])
        check('base_staff/keywords', data='auto void static auto\n',
              expected=['   2 auto', '   1 void', '   1 static'])
        check('base_staff/keywords', data='auto', expected=['   1 auto'])
        check('base_staff/line_sort', data='zebra\napple\nlast',
              expected=['After sort\napple\nlast\nzebra\n'])
        check('base_staff/line_sort', data='\nz\na\n', expected=['After sort\n\na\nz\n'])
        check('base_staff/long_line', data='a\nlongest\nb\n', expected=['longest'])
        check('base_staff/long_line', data='last', expected=['last'])
        for mode in ['ss', 'qs', 'cs']:
            output = check('base_staff/sort', [mode])
            assert list(map(int, output.splitlines()[-1].split()[-10:])) == list(range(1, 11))
        check('data_structures/linked_list', expected=['size 3', 'size 4', 'Head elem 2', 'Tail elem 0', 'New next of head 3', 'destroyed'])
        check('data_structures/double_linked_list', expected=['size 3', 'size 4', 'Head elem 0', 'Tail elem 2', 'destroyed'])
        check('data_structures/circular_list', expected=['size 3', 'Head elem 0', 'Next of head 1', 'Next next of head 2', 'destroyed'])
        check('data_structures/chained_hashtable', expected=['size 3', 'Removed 5; size 2', 'destroyed'])
        check('data_structures/set', expected=['Set size 2', 'Removed 1; size 1', 'destroyed'])
        check('data_structures/stack', expected=['Stack head 2', 'Stack size 3', 'Removed 2\nRemoved 1\nRemoved 0'])
        check('data_structures/queue', expected=['Queue size 3', 'Removed 0\nRemoved 1\nRemoved 2'])
        check('encryption', expected=['85 e8 13 54 0f 0a b4 05', 'DES round trip passed', '65 -> 2790 -> 65'])
        for directory in ['base_staff/input_counter', 'base_staff/keywords',
                          'base_staff/line_sort', 'base_staff/long_line']:
            check(directory)
        # Invalid invocations must fail cleanly, without a crash or sanitizer report.
        for directory, arguments in [(base, []), (base, ['bc']), (base, ['dy', '2024', '13', '1']),
                                     (base, ['dy', '2023', '2', '29']), (base, ['unknown']),
                                     (bits, []), (bits, ['unknown']),
                                     ('base_staff/sort', []), ('base_staff/sort', ['unknown'])]:
            result = subprocess.run([f'./{DEMOS[directory]}', *arguments],
                                    cwd=root / directory, capture_output=True, text=True, timeout=5)
            assert result.returncode == 1 and result.stderr, result
            assert 'Sanitizer' not in result.stderr and 'runtime error:' not in result.stderr, result.stderr
            count += 1
    print(f'Passed: {len(DEMOS)} builds, {count} runs' + (' with sanitizers' if args.sanitize else ''))


if __name__ == '__main__':
    main()
