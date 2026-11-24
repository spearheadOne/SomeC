# Data structures

Core data structures implemented in C. Each executable uses fixed integer examples and requires no arguments or input.

## Demos

| Directory | Executable | Demonstration |
| --- | --- | --- |
| [linked_list](linked_list/) | `ll` | Insert and remove elements in a singly linked list |
| [double_linked_list](double_linked_list/) | `dll` | Insert before/after elements and remove from a doubly linked list |
| [circular_list](circular_list/) | `cll` | Traverse and clear a circular linked list |
| [chained_hashtable](chained_hashtable/) | `cht` | Insert, look up, and remove integers, including a hash collision |
| [set](set/) | `st` | Insert integers, suppress duplicates, and remove a member |
| [stack](stack/) | `st` | Push and pop in last-in, first-out order: 2, 1, 0 |
| [queue](queue/) | `qu` | Enqueue and dequeue in first-in, first-out order: 0, 1, 2 |

## Build and run

Requires a C11 compiler and Make on macOS or Linux. From the repository root:

```sh
cd data_structures/circular_list
make
./cll
make clean
```

Use the executable listed for each directory; Set and Stack both produce `st` in their own directories.

## Notes

- Containers store pointers to payloads. The demos use integers with automatic storage and a `NULL` destruction callback; container cleanup frees the nodes.
- Run `make check` or `make check-sanitize` from the repository root to build and exercise all portable demos.
