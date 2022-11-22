# 42_push_swap
This project aims to sort data with two stacks but with a limited set of instructions, in as few moves as possible.  

# The set of instructions
To manipulate the stack "a" and the stack "b", 11 operations are possibles:  
- sa : swap a | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.  
- sb : swap b | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.  
- ss : sa and sb at the same time.  

- pa : push a | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
- pb : push b | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  

- ra : rotate a | Shift up all elements of stack a by 1. The first element becomes the last one.  
- rb : rotate b | Shift up all elements of stack b by 1. The first element becomes the last one.  
- rr : ra and rb at the same time.  

- rra : reverse rotate a | Shift down all elements of stack a by 1. The last element becomes the first one.  
- rrb : reverse rotate b | Shift down all elements of stack b by 1. The last element becomes the first one.  
- rrr : rra and rrb at the same time.  

# Expected results
Two programs are expected in this project.  
The first one is the "push_swap" program that will take a list of numbers as input and will output the best set of instructions to sort the list.  

The second one is the "checker" program that will take the same list of numbers as input, apply the set of instructions given by "push_swap" then confirm that the list is correctly sorted.  

# Notes
To reach the highest level of optimization (in number of instructions used), I had to combine two sorting algorithms: Quicksort and Selectsort.  
The most difficult part of this project is to adapt each concept (quicksort, selectsort, etc) with the use of the limited set of instructions.  

# Keywords
Sorting algorithms  
Manipulation of stack
