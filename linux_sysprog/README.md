# Linux system programming

Examples using Linux system calls and libraries. Build and run this section on Linux; some APIs are unavailable on macOS.

## Demos

| Directory | Executable | Demonstration |
| --- | --- | --- |
| [change_group](change_group/) | `cgg` | Change Group: Change group which file belongs to. |
| [child_process](child_process/) | `cp` | Child Process: Fork a child and exit. |
| [affinity](affinity/) | `cpa` | CPU Affinity: Show the number of used CPUs. |
| [file_ops](file_ops/) | `fo` | File Operations: Several file operations like open,create,read,sync,truncate,seek. |
| [file_stat](file_stat/) | `fs` | File Statistics: Print statistics of input file. |
| [find_file](find_file/) | `ff` | Find File: Find a file in a filesystem. |
| [get_alloc_size](get_alloc_size/) | `gs` | Get Allocated Size: Allocate memory and get size of it. |
| [get_dir](get_dir/) | `gd` | Get Directory: Show path to the current directory. |
| [map](map/) | `mp` | Map: Open file and print contents. |
| [multi_signal](multi_signal/) | `msh` | Multi signal handler: Handler for various system signals. |
| [poll](poll/) | `pd` | Poll: Check if stdin and stdout are readable. |
| [print_chars](print_chars/) | `pc` | Print Chars: Print chars from hardcoded string. |
| [writev](writev/) | `wd` | WriteV: Create a file and write bytes to it. |
| [readv](readv/) | `rd` | ReadV: Read file create by WriteV. |
| [rlimits](rlimits/) | `rl` | R limits: Check R limits. |
| [rr_interval](rr_interval/) | `rr` | RR Interval: Get a time quantum . |
| [rr_priority](rr_priority/) | `rrp` | RR Priority: Schedule a priority range. |
| [select](select/) | `sel` | Select: Read a file using blocking. |
| [sighup](sighup/) | `ss` | Send Signal: Send kill a signal. |
| [priority](priority/) | `hp` | Set highest priority: Set priority via scheduler. |
| [sigint](sigint/) | `sh` | Sigint handler: Handle SIGINT. |
| [signal_payload](signal_payload/) | `sp` | Signal payload: Send a signal with payload. |
| [daemon](daemon/) | `sd` | Small Daemon: A tiny daemon. |
| [sort_block](sort_block/) | `sb` | Sort Block: Get number of blocks consumed by file and print tuple (logical block-physical block). |
| [sort_inode](sort_inode/) | `si` | Sort Inode: Get Inode of the file. |
| [stat](stat/) | `st` | Stats: Print malloc stats. |
| [stream](stream/) | `str` | Stream: Write stream to file. |
| [time](time/) | `tm` | Time: Get system time. |

## Build and run

Requires a C compiler, Make, and a Linux environment. From the repository root:

```sh
cd linux_sysprog/<demo-directory>
make
./<executable> <arguments>
```

Use the executable name in the table and inspect the demo source for its required arguments. The repository's root build and smoke-check targets exclude this section. These demos have not been built or run during the macOS review.

## Notes

- Poll: `./pd < some-file` checks redirected input; without redirection, it checks standard input.
- Run ReadV after WriteV, in the same working directory, so the generated file is available.
- Select: `./sel < some-file` checks redirected input; without ready input, it waits up to five seconds.
- Several demos modify files, change process attributes, send signals, or start a daemon. Inspect the source and choose appropriate paths and process IDs before running them.
