# Graphics

Graphics demos in C using SDL3. Pixels are drawn into a software framebuffer, then uploaded to an SDL texture for display.

[Back to the main README](../README.md)

## Demos

| Directory | Executable | Demonstration |
| --- | --- | --- |
| [framebuffer](framebuffer/) | `framebuffer` | Animate a green pixel moving across the center of a dark background |

### Framebuffer

The demo uses a 320 × 200 array of 32-bit pixels and displays it in a 1280 × 800 window. Nearest-neighbor scaling keeps the enlarged pixels sharp.

Each frame clears the buffer, draws the next pixel, uploads the buffer to a streaming SDL texture, and renders it. The loop targets approximately 60 frames per second. The pixel wraps back to the left edge after reaching the right edge.

Close the window to exit. No command-line arguments are required.

## Requirements

- A C11 compiler and Make.
- SDL3 headers and libraries; SDL2 is not compatible with this demo.
- A graphical desktop session to display the window.

On macOS with Homebrew:

```sh
brew install sdl3
```

The Makefile uses `gcc`. On macOS, Apple's `gcc` command invokes Clang.

## Build and run

From the repository root:

```sh
cd grapihcs/framebuffer
make
./framebuffer
```

The Makefile defaults to SDL3 at `/opt/homebrew/opt/sdl3`. For another installation, set `SDL3_PREFIX` to the directory containing SDL3's `include` and `lib` directories. For example, on a Mac with Homebrew installed elsewhere:

```sh
make clean
make SDL3_PREFIX="$(brew --prefix sdl3)"
./framebuffer
```

The same override can be used for SDL3 installed on another platform. The default paths are configured for macOS with Homebrew.

To remove the executable and generated object and dependency files:

```sh
make clean
```

## Notes

- Build this demo separately. The repository's root `make`, `make clean`, `make check`, and `make check-sanitize` targets currently cover the 16 Basics, Data structures, and Encryption demos and exclude Graphics.
- The directory is currently named `grapihcs`; the commands and links above use that existing spelling.
