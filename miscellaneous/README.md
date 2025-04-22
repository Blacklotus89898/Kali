# GDB Cheat Sheet

## Starting GDB
- `gdb <program>`: Start GDB with the specified program.
- `gdb <program> <core>`: Debug a core dump.
- `gdb -p <pid>`: Attach to a running process.

## Running Programs
- `run [args]`: Start the program with optional arguments.
- `start`: Begin execution and stop at `main`.
- `continue` / `c`: Resume execution.
- `kill`: Stop the program.

## Breakpoints
- `break <location>` / `b <location>`: Set a breakpoint at a function, line, or address.
- `break <file>:<line>`: Set a breakpoint at a specific file and line.
- `info breakpoints` / `i b`: List all breakpoints.
- `delete <num>` / `d <num>`: Remove a specific breakpoint.
- `disable <num>`: Disable a breakpoint.
- `enable <num>`: Enable a breakpoint.

## Stepping
- `step` / `s`: Step into the next line or function.
- `next` / `n`: Step over the next line or function.
- `finish`: Run until the current function returns.
- `until <location>`: Run until a specific location.

## Examining Code
- `list` / `l`: Show source code around the current line.
- `list <function>`: Show source code for a function.
- `disassemble`: Show assembly code for the current function.

## Examining Variables
- `print <expr>` / `p <expr>`: Print the value of an expression.
- `display <expr>`: Automatically print an expression after each step.
- `info locals`: Show local variables.
- `info args`: Show function arguments.
- `set variable <var> = <value>`: Change the value of a variable.

## Memory Inspection
- `x/<nfu> <address>`: Examine memory at an address.
    - `n`: Number of units.
    - `f`: Format (e.g., `x` for hex, `d` for decimal, `s` for string).
    - `u`: Unit size (e.g., `b` for byte, `w` for word).

## Threads
- `info threads`: List all threads.
- `thread <num>`: Switch to a specific thread.
- `bt` / `backtrace`: Show the call stack for the current thread.

## Call Stack
- `backtrace` / `bt`: Show the call stack.
- `frame <num>`: Switch to a specific stack frame.
- `info frame`: Show details about the current frame.

## Signals
- `info signals`: List signal handling settings.
- `handle <signal> <action>`: Set how GDB handles a signal (e.g., `nostop`, `pass`).

## Miscellaneous
- `help`: Show help for GDB commands.
- `quit` / `q`: Exit GDB.
- `set args <args>`: Set command-line arguments for the program.
- `info registers`: Show CPU register values.
- `info sharedlibrary`: List loaded shared libraries.

## TUI Mode
- `layout src`: Show source code in TUI mode.
- `layout asm`: Show assembly in TUI mode.
- `layout regs`: Show registers in TUI mode.

## Scripting
- `source <file>`: Execute commands from a file.
- `define <command>`: Create a custom command.
