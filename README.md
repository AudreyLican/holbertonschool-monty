# Monty - Stacks, Queues - LIFO, FIFO

This is a project for Holberton School, which aims to implement an interpreter for Monty ByteCodes files. Monty is a scripting language that relies on a unique stack data structure with specific instructions to manipulate it. This interpreter will allow you to execute Monty programs that use stack and queue operations.

## Table of Contents
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Compilation & Output](#compilation--output)
- [The Monty Language](#the-monty-language)
- [Tasks](#tasks)
    - [Task 0: push, pall](#task-0-push-pall)
    - [Task 1: pint](#task-1-pint)
    - [Task 2: pop](#task-2-pop)
    - [Task 3: swap](#task-3-swap)
    - [Task 4: add](#task-4-add)
    - [Task 5: nop](#task-5-nop)
- [Authors](#authors)

## Learning Objectives
By completing this project, you will gain knowledge in the following areas:
- Understanding the concepts of LIFO (Last In, First Out) and FIFO (First In, First Out).
- Implementing stack and queue data structures.
- Recognizing common implementations of stacks and queues.
- Identifying the most common use cases for stacks and queues.
- Properly using global variables in C.

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All code files will be compiled on Ubuntu 20.04 LTS using gcc, with the options `-Wall -Werror -Wextra -pedantic`.
- All code files should end with a new line.
- You must include a `README.md` file at the root of the project folder.
- Your code should adhere to the Betty style, which will be checked using `betty-style.pl` and `betty-doc.pl`.
- You are allowed to use a maximum of one global variable.
- Each code file should contain no more than 5 functions.
- You can use the C standard library.
- The prototypes of all your functions should be included in your header file named `monty.h`.
- Don't forget to push your header file.
- All header files should be include guarded.

### GitHub
- There should be one project repository per group. Cloning, forking, or using a project repository with the same name before the second deadline will result in a 0% score.

### Data Structures
Please use the following data structures for this project:
```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output
Your code will be compiled using the following command:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
- Any output should be printed to `stdout`.
- Any error messages should be printed to `stderr`.

## The Monty Language
Monty 0.98 is a scripting language that is compiled into Monty byte codes. These byte code files typically have the `.m` extension. The language uses a unique stack data structure, with specific instructions to manipulate it. Here are some key points about Monty byte code files:
- Each line in the file contains one instruction.
- Instructions can have any number of spaces before or after the opcode and its argument.
- Blank lines (empty or consisting of spaces only) are ignored.
- Additional text after the opcode or its required argument is not considered.
- Monty programs can contain comments starting with `#`, which are ignored.

### Example Monty Byte Code File:
```bash
push 0
push 1
push 2
  push 3
                   pall
push 4
    push 5
      push 6
pall
```

## Tasks
### Task 0: push, pall (mandatory)
Implement the `push` and `pall` opcodes.

**The `push` Opcode:**
- The `push` opcode pushes an element onto the stack.
- Usage: `push <int>` (where `<int>` is an integer).
- If `<int>` is not an integer or if no argument is given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with status `EXIT_FAILURE`.

**The `pall` Opcode:**
- The `pall` opcode prints all the values on the stack, starting from the top of the stack.
- Usage: `pall`
- If the stack is empty, don't print anything.

### Task 1: pint (mandatory)
Implement the `pint` opcode.

**The `pint` Opcode:**
- The `pint` opcode prints the value at the top of the stack, followed by a new line.
- Usage: `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with status `EXIT_FAILURE`.

### Task 2: pop (mandatory)
Implement the `pop` opcode.

**The `pop` Opcode:**
- The `pop` opcode removes the top element of the stack.
- Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with status `EXIT_FAILURE`.

### Task 3: swap (mandatory)
Implement the `swap` opcode.

**The `swap` Opcode:**
- The `swap` opcode swaps the top two elements of the stack.
- Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with status `EXIT_FAILURE`.

### Task 4: add (mandatory)
Implement the `add` opcode.

**The `add` Opcode:**
- The `add` opcode adds the top two elements of the stack.
- Usage: `add`
- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with status `EXIT_FAILURE`.
- The result should be stored in the second top element of the stack, and the top element should be removed.

### Task 5: nop (mandatory)
Implement the nop opcode.

The nop Opcode:

The nop opcode does nothing.
Usage: nop
Authors
Julien Barbier
Team members: Audrey Lican, Nicolas Taillepierre