# Minishell
Minishell is a minimalistic shell implementation developed as part of the 42 School curriculum. This project serves as an introduction to creating a command-line interpreter similar to the Unix shell. The goal of the project is to deepen understanding of processes, system calls, and overall shell behavior.

## Authors
This project was created by [msmajdor](https://github.com/mariusz-smajdor) and [mwiacek](https://github.com/maciejwiacek).

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Known Issues](#known-issues)
- [Contributing](#contributing)

## Features

Minishell supports the following features:

- Displaying a prompt and waiting for user input.
- Executing commands with arguments (e.g., `ls -la`, `grep "hello"`).
- Input/output redirections (e.g., `ls > file.txt`, `cat < file.txt`).
- Piping commands (e.g., `ls | grep minishell`).
- Handling of basic environment variables (e.g., `$PATH`, `$HOME`).
- Multiple commiands chaining (e.g., `ls -l | grep minishell > result.txt`)
- Signal handling (e.g., `Ctrl+C`, `Ctrl+D`).
- Basic error handling and reporting.

## Installation

To compile and use Minishell, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/minishell.git
    ```
2. Navigate to the project directory:
    ```sh
    cd minishell
    ```
3. Compile the project:
    ```sh
    make
    ```

## Usage

After successfully compiling the project, you can start Minishell by running:

```sh
./minishell
```

Minishell will start with a prompt where you can type commands. It behaves similarly to a standard Unix shell but with limited functionality.

### Example

```sh
$ echo "Hello, Minishell!"
Hello, Minishell!

$ ls -la
total 16
drwxr-xr-x  4 user  staff  128 Aug 28 12:00 .
drwxr-xr-x  9 user  staff  288 Aug 28 11:50 ..
-rw-r--r--  1 user  staff  512 Aug 28 12:00 Makefile
-rwxr-xr-x  1 user  staff  4096 Aug 28 12:00 minishell
```

## Built-in Commands
Minishell includes the following built-in commands:

- cd [directory]: Change the current directory.
- echo [string ...]: Display a line of text.
- env: Display the environment variables.
- exit [status]: Exit the shell with an optional status code.
- export [name[=value]]: Set or export an environment variable.
- unset [name]: Unset an environment variable.

## Known Issues
Limited Error Handling: Some error cases may not be fully handled.
No Support for Advanced Shell Features: Features like job control, advanced redirections, or scripting are not supported.
Memory Management: Memory management is basic and may result in memory leaks under specific conditions.

## Contributing
Contributions are welcome! If you find a bug or have an idea for a feature, feel free to open an issue or submit a pull request. Please ensure that your code follows the project's coding style and includes relevant tests.
