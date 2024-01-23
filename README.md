## Push Swap Project

The Push Swap project is a simple algorithm project that involves sorting a set of integer values using two stacks and a set of instructions. The goal is to write a program in C called push_swap that calculates and displays the smallest program, made of Push Swap language instructions, that sorts the given integers.

## Objectives

The main objectives of this project are as follows:

- Develop a sorting algorithm.
- Gain understanding of algorithm complexity.
- Use the C programming language.
- Implement basic algorithms and understand their complexity.

## Common Instructions

- The project must be written in C.
- The code must comply with the Norm, a set of rules for writing clean and consistent code.
- The program should not quit unexpectedly, except for undefined behaviors.
- All allocated memory must be properly freed to avoid memory leaks.
- If a Makefile is required, it should compile the source files with the flags -Wall, -Wextra, and -Werror.
- The Makefile must include the rules $(NAME), all, clean, fclean, and re.
- It is encouraged to create test programs to verify the correctness of the code, although they are not required for submission.
- The project should be submitted to the assigned Git repository.
- If the project allows the use of a personal library (libft), it must be included and compiled separately from the main project.

## Push_swap Program

### Description

- The program should be named push_swap.
- It should take a list of integers as arguments and sort them using the provided instructions.
- The program must display the smallest list of instructions possible to sort the integers, with the smallest number being at the top.
- Instructions must be separated by a newline character ('\n').
- The goal is to sort the stack with the lowest possible number of operations.
- If no parameters are specified, the program should not display anything and give the prompt back.
- In case of an error, the program should display "Error" followed by a newline character on the standard error.

### Usage

    ./push_swap [list of integers]

Examples

    $ ./push_swap 2 1 3 6 5 8
    sa
    pb
    pb
    pb
    sa
    pa
    pa
    pa

    $ ./push_swap 0 one 2 3
    Error

To test N element:

    $ ARG=$(ruby -e "puts (-1000..1000).to_a.sample(N).join(' ')") && ./push_swap $ARG
    
    => Example:(to test 100 elements)
    
    $ ARG=$(ruby -e "puts (-1000..1000).to_a.sample(100).join(' ')") && ./push_swap $ARG

## Checker Program (Bonus)

### Description

- The program should be named checker.
- It should take a list of integers as arguments and wait for instructions on the standard input.
- The program should execute the instructions on the stack received as an argument.
- After executing the instructions, if stack a is sorted and stack b is empty, the program should display "OK" followed by a newline character on the standard output.
- In all other cases, the program should display "KO" followed by a newline character on the standard output.
- In case of an error, the program should display "Error" followed by a newline character on the standard error.

### Usage

    ./checker [list of integers]

### Examples

    $ ./checker 3 2 1 0
    rra
    pb
    sa
    rra
    pa
    OK

    $ ./checker 3 2 1 0
    sa
    rra
    pb
    KO

    $ ./checker 3 2 one 0
    Error

    $ ./checker "" 1
    Error

Note: The provided examples assume the existence of a checker program named "checker_OS". The exact behavior of the checker program is not required, but it should perform the same functionality outlined above.

## Conclusion

The Push Swap project aims to develop a sorting algorithm and gain an understanding of algorithm complexity. By implementing the push_swap and checker programs, you will demonstrate your ability to write clean and efficient code in C and handle various error cases. Good luck with your implementation!

