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

# The rules

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

# Implementation

After parsing the elements enter as argument, they should be integers and not duplicated, we stock these elements in the stack a.

        The stack a is a lincked list that contain:
        typedef struct s_list
        {
        	int				content;
        	int				index;
        	int				pos;
        	int				tpos;
        	int				cost_a;
        	int				cost_b;
        	struct s_list	*next;
        }	t_list;

First, you have to index the elements, it will be like a sort of virtual sort each element takes its order as an index.

        For example:
            if we enter the elements: [1] [4] [5] [2] [8] [10] [3]
            the indexes should be:     1   4   5   2   6   7    3

The idea is to push the elements from stack a to the stack b except 3 elements. if the elements are more than 6 we are going to try to leave the 
three of the largest elements, not necessarily the largest, but which will be their index bigger than size_a/2, if it is we do a rotate of a then we continue. And if there is 6 element or less we just leave the 3 last elements in stack.

        For example:
        1:  stack a: [1] [4] [5] [2] [8] [10] [3]
            in stack a we have 7 elements, so we take the first element wich is [1] his index is 1 and 1 < size_a/2.
            we push the element in the top of b.
            stack b: [1]
            stack a: [4] [5] [2] [8] [10] [3]
            Now we have just 6 elements in the stack a so we push the three first elements to stck b. 
            stack b: [2] [5] [4] [1]
            stack a: [8] [10] [3]
        2:  stack a: [10] [2] [3] [8] [4] [1] [5]
            [10] his index is 7 and 7 > size_a/2
            so we do "ra" then we continue.
            stack a: [2] [3] [8] [4] [1] [5] [10]
            [2] his index is 2 and 2 < size_a/2 so we push [2] in the top of b.
            stack b: [2]
            stack a: [3] [8] [4] [1] [5] [10]
            Now we have just 6 elements in the stack a so we push the three first elements to stck b. 
            stack b: [4] [8] [3] [2]
            stack a: [1] [5] [10]

