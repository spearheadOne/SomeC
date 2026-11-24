# Basics

C language fundamentals, bit operations, text processing, and sorting.

This section includes examples and exercises adapted from *The C Programming Language* by Brian W. Kernighan and Dennis M. Ritchie (K&R). The implementations retain the book's instructional style, including simple integer functions and fixed input buffers. The command-line wrappers and additional demos are repository adaptations.

## Demos

Paths below are relative to this directory. Run each command from its demo directory after `make`.

| Directory | Executable | Purpose and example |
| --- | --- | --- |
| [basics](basics/) | `base` | Fundamental operations; see command modes below |
| [bit_ops](bit_ops/) | `bitops` | Bit operations on fixed example buffers; see modes below |
| [concat_files](concat_files/) | `concat` | Concatenate files: `./concat one.txt two.txt`; without files, copy standard input |
| [input_counter](input_counter/) | `inputCounter` | Count lines, words, characters, whitespace, and digits: `printf 'one two 123\n' \| ./inputCounter` |
| [keywords](keywords/) | `keywords` | Count `auto`, `break`, `case`, `char`, `const`, `continue`, `static`, `void`: `printf 'auto void auto\n' \| ./keywords` |
| [line_sort](line_sort/) | `lineSort` | Sort input lines: `printf 'zebra\napple\n' \| ./lineSort` |
| [long_line](long_line/) | `longLine` | Print the longest input line: `printf 'a\nlongest\n' \| ./longLine` |
| [sort](sort/) | `sort` | Sort a fixed integer array; see modes below |

### Basics command modes

| Command | Result |
| --- | --- |
| `./base hw` | Print Hello World |
| `./base fc` | Print a Fahrenheit-to-Celsius table |
| `./base bc 7` | Count set bits in an unsigned integer (3 for this input) |
| `./base dy 2024 3 1` | Calculate the day of the year (61 for this date) |
| `./base mn 12` | Print the month name (December) |
| `./base fac` | Print factorials from 0 through 12 |
| `./base ec hello world` | Echo the remaining arguments |

### Bit-operation command modes

| Command | Result |
| --- | --- |
| `./bitops bg` | Read bit 4 of `abcde` (positions start at 0, most significant bit first) |
| `./bitops bs` | Set bit 4 of `abcde` |
| `./bitops bx` | XOR `abcde` and `aeghi`; print the five result bytes in hexadecimal |
| `./bitops br` | Rotate the 40 bits of `aeghi` left by 8 bits, producing `eghia` |

### Sorting command modes

| Command | Algorithm |
| --- | --- |
| `./sort ss` | Shell sort |
| `./sort qs` | Quicksort |
| `./sort cs` | Counting sort |

Each mode sorts the integers 10 through 1 into ascending order.

## Build and run

Requires a C11 compiler and Make on macOS or Linux. For example, from the repository root:

```sh
cd base_staff/basics
make
./base hw
make clean
```

## Notes

- The factorial functions retain `int` arithmetic. The demo stops at 12 to avoid overflowing a 32-bit `int`.
- For interactive text input, finish with Ctrl-D on an empty line to send EOF. Pipes and redirected files send EOF automatically.
- Line Sort uses fixed storage: up to 5,000 stored lines, a 1,000-byte input buffer, and a 10,000-byte allocation buffer. Long Line also uses a 1,000-byte input buffer; longer physical lines are processed in chunks.
- Run `make check` or `make check-sanitize` from the repository root to build and exercise all portable demos.
