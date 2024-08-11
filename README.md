# Simple Shell Project

## Overview

This project is an implementation of a simple Unix shell in C. The shell provides a command-line interface for users to interact with the operating system by executing commands. It supports basic shell functionalities such as executing built-in commands, handling external programs, and managing input/output redirection.

## Features

- **Command Execution**: Execute built-in and external commands.
- **Input/Output Redirection**: Support for redirecting input and output using `>`, `<`, and `>>`.
- **Pipelining**: Ability to chain commands using the `|` operator.
- **Environment Variables**: Access and modify environment variables.
- **Signal Handling**: Handle signals like `Ctrl+C` to terminate processes gracefully.
- **Error Handling**: Provide meaningful error messages for invalid commands and syntax errors.

## Built-in Commands

The shell supports the following built-in commands:

- `cd [directory]`: Change the current directory.
- `exit [status]`: Exit the shell with an optional status code.
- `env`: Display the current environment variables.
- `setenv [variable] [value]`: Set an environment variable.
- `unsetenv [variable]`: Unset an environment variable.
