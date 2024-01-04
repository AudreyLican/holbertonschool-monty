# C - Stacks, Queues - LIFO, FIFO

This project is focused on implementing stacks and queues using LIFO (Last In, First Out) and FIFO (First In, First Out) concepts in C programming. It's an academic project done by Audrey Lican and Nicolas Taillepierre under the guidance of Julien Barbier.

## Description

The goal of this project is to understand and implement stacks and queues using a doubly linked list. We'll explore the operations specific to each data structure and understand their use cases. Additionally, we'll delve into the Monty language, interpreting Monty byte codes to perform stack operations.

### Learning Objectives

- Understand what LIFO and FIFO mean.
- Learn when and why to use a stack or a queue.
- Explore common implementations and use cases of stacks and queues.
- Proper usage of global variables.

## Requirements

- Allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 20.04 LTS using gcc with the options `-Wall -Werror -Wextra -pedantic`.
- All files should end with a new line.
- Code should use the Betty style for checks.
- A maximum of one global variable is allowed.
- No more than 5 functions per file.
- Allowed to use the C standard library.
- Function prototypes should be included in the header file `monty.h`.
- All header files should have include guards.

## Installation

Clone the repository:

```bash
git clone [repository link]
```

Compile the code:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage

```bash
./monty [file]
```

- `file`: Path to the file containing Monty byte codes.

### Data Structures

The main data structures used in this project are:

```c
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```


## Monty Byte Code Files

Monty files have a `.m` extension and contain one instruction per line. The program reads these instructions and performs operations on the stack accordingly.

## Error Handling

The program handles various errors like file opening failures, invalid instructions, and memory allocation issues, printing appropriate error messages to stderr.

## Tasks

1. **Implement push and pall opcodes.**
2. **Implement pint opcode.**
3. **Implement pop opcode.**
4. **Implement swap opcode.**
5. **Implement add opcode.**
6. **Implement nop opcode.**

...and more.

## Authors

[Audrey "Luffy" Lican](https://github.com/AudreyLican)
[Nicolas Taillepierre](https://github.com/TaillepierreN)
