*This project has been created as part of the 42 curriculum by adchebbi.*

# Pipex

## Description

Pipex is a project that consists of reproducing the behavior of the UNIX pipe mechanism in C. The program takes two shell commands and connects them through a pipe, redirecting input from a file and output to another file.

The goal is to gain a deep understanding of how processes work (`fork`), file descriptor redirection (`dup2`), program execution (`execve`), and inter-process communication via `pipe`.

The program reproduces the behavior of:

```bash
< file1 cmd1 | cmd2 > file2
```

## Instructions

### Compilation

```bash
make        # Compiles libft then the pipex binary
make clean  # Removes object files (.o)
make fclean # Removes object files and the binary
make re     # Fully recompiles the project
```

The project compiles with `cc` and the flags `-Wall -Wextra -Werror`.

### Usage

```bash
./pipex file1 "cmd1" "cmd2" file2
```

The program takes 4 arguments:
- `file1` : input file (redirected to stdin of cmd1)
- `cmd1` : first shell command with its parameters
- `cmd2` : second shell command with its parameters
- `file2` : output file (receives stdout of cmd2)

### Examples

```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# Equivalent to: < infile grep a1 | wc -w > outfile
```

## Resources

### Classic references

- `man 2 pipe` — pipe creation
- `man 2 fork` — child process creation
- `man 2 dup2` — file descriptor duplication
- `man 2 execve` — program execution
- `man 2 wait` / `man 2 waitpid` — waiting for process termination
- `man 2 access` — file permission checking
- [Pipes in C (tutorial)](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
- [Communicating between processes (using pipes) in C](https://youtu.be/Mqb2dVRe0uo?si=A28mciZjL201lclp)

### AI usage

AI (Claude) was used for:
- Writing this README.md file.
- Validating the implementation logic.
- Tracking project progress and development steps.
