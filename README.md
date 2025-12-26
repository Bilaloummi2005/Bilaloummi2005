_This project has been created as part of the 42 curriculum by  `<boummi>`_

# Description
push_swap is an algorithmic project whose objective is to sort a stack of integers using a limited set of operations, following strict constraints on speed and efficiency.

The program receives a list of integers as input and must output a sequence of operations that will sort the numbers in ascending order. These operations manipulate two stacks — A and B — using only the allowed moves:
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

The challenge lies in:

- Designing an efficient sorting strategy adapted to the number of elements.

- Minimizing the number of operations.

- Ensuring full compliance with input validation, memory management, and edge-case handling

# Instructions
This section explains how to compile, install, and execute the project.

### Compilation

The project uses a Makefile with the following rules:

```bash
make        # compiles the project
make bonus  # compile the checker
make clean  # removes object files
make fclean # removes object files and executables
make re     # full recompile of the project
```
### Installation

No installation is required.
The executable is generated directly in the project directory.

### Execution

To run the program, you need to give it a list of integers  as argument:

```bash
./push_swap 2 1 3 6 5 8
```
The program will output a sequence of operations that sorts the list.

If you built a checker program, you can use:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
./checker 2 1 3 6 5 8
```

# Resources
### Documentation & References
- 42 subject PDF (push_swap)
- Algorithm references:
    - Sorting algorithms overview
    - Turk algorithm
### Articles
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
### AI Usage Disclosure
#### AI tools (ChatGPT) were used only for:
- Clarifying project rules and algorithms at a high level
- Getting help structuring this README file
- Understanding how to read Valgrind leak summaries

#### AI was not used to:
- Generate code added directly to the final project
- Implement algorithms
- Write any part of the final source files
#### All code, logic, and structure of the project were written manually.

### Features
- Efficient sorting for small data sets (≤5 elements)
- Optimized algorithm (e.g., radix sort or chunk sorting) for large input sizes
- Input parsing and validation (duplicates, non-numbers, integer limits)
- Error handling and memory cleanup
- Uses two stacks implemented via linked lists

### Usage Examples
```bash
./push_swap 3 2 1
sa
rra
```
```bash
./push_swap 3 2 1 | ./checker 3 2 1
OK
```
