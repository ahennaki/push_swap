# push_swap
    The push swap project is a very simple and very easy algorithmic project.
    The data should be sorted.
    You have a set of integer values, two stacks, and a set of instructions at your disposal.
    Manipulate both stacks.
    What is your purpose? Write a program in C called push_swap that computes and prints.
    On standard output, a minimal program consisting of push-swap language instructions,
    Sorts the integers received as arguments.
    
Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity.
Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point.
The learning objectives of this project are rigor, use of C, and use of basic algorithms.
Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially
because from one integers configuration to another, the most efficient sorting solution can
differ.

## The rules

• You have 2 stacks named a and b.

• At the beginning:

        ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
        
        ◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

## Test

        $>make

        To test 10 elements:
        
        $>ARG=$(ruby -e "puts (-1000..1000).to_a.sample(10).join(' ')") && ./ $ARG

        To test 100:

        $>ARG=$(ruby -e "puts (-1000..1000).to_a.sample(100).join(' ')") && ./push_swap $ARG

        To test 500:

        $>ARG=$(ruby -e "puts (-1000..1000).to_a.sample(500).join(' ')") && ./push_swap $ARG

        To calculate the number of moves or instructions:

        $>ARG=$(ruby -e "puts (-1000..1000).to_a.sample(500).join(' ')") && ./push_swap $ARG | wc -l

## BONUS: The "checker" program

• Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.

• It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.

• If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.

• In every other case, it must display "KO" followed by a ’\n’ on the standard output.

• In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

        $>./checker 3 2 1 0
        rra
        pb
        sa
        rra
        pa
        OK
        $>./checker 3 2 1 0
        sa
        rra
        pb
        KO
        $>./checker 3 2 one 0
        Error
        $>./checker "" 1
        Error
        $>
