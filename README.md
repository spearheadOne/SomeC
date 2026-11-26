# Some C

Small C programs for learning language fundamentals, data structures, encryption, and system programming.

The [Basics examples](base_staff/README.md) include adaptations of examples and exercises from *The C Programming Language* by Brian W. Kernighan and Dennis M. Ritchie (K&R). These are learning implementations; fixes address build and runtime errors while retaining the examples' instructional style.

## Examples

| Section | Contents | Platform |
| --- | --- | --- |
| [Basics](base_staff/README.md) | Language fundamentals, bit operations, text processing, sorting | macOS and Linux |
| [Data structures](data_structures/README.md) | Lists, hash table, set, stack, queue | macOS and Linux |
| [Encryption](encryption/README.md) | Educational DES and RSA examples | macOS and Linux |
| [Linux system programming](linux_sysprog/README.md) | Linux system calls, processes, signals, files, scheduling | Linux |
| [Graphics](grapihcs/README.md) | SDL3 software framebuffer and pixel animation | SDL3 required; defaults to macOS/Homebrew paths |

## Build and run

You need a C11 compiler and Make. On macOS, install Apple's Command Line Tools with `xcode-select --install` if they are missing.

From the repository root:

```sh
make                          # Build all 16 portable demos
make check                    # Build and run the portable smoke checks (Python 3)
make check-sanitize           # Repeat with address and undefined-behavior sanitizers
make clean                    # Remove portable build outputs
```

The root targets exclude `linux_sysprog` and Graphics. Build the SDL3 demo separately using the [Graphics instructions](grapihcs/README.md). Each section README lists executable names, arguments, and sample inputs. To build one demo:

```sh
cd data_structures/circular_list
make
./cll
```

Use `make CC=clang` or `make CC=gcc` to select a compiler. Apple's `gcc` command invokes Clang. The portable demos are checked on macOS; Linux system-programming demos require a separate Linux environment.

## Verification

The smoke checks build fresh copies in a temporary directory, exercise every documented portable command mode, and verify representative output. They include piped input, empty input, missing arguments, FIFO/LIFO ordering, and DES/RSA known results and round trips. They do not build or run Linux system-programming examples or the SDL3 graphics demo.
