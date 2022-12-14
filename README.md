# 42_push_swap
Push Swap is a program to sort a list of numbers with two stacks but with a limited set of instructions, in as few moves as possible.  

## The set of instructions
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

## Example
This example sorts the integers of stack "a" with 12 instructions, but some optimizations are still possible to do better.  
![Screenshot 2022-11-22 at 18-34-32 push_swap fr pdf](https://user-images.githubusercontent.com/52746061/203382812-451de35e-686f-4523-915b-57374debcd0f.png)  

## Expected Results
Two programs are expected in this project.  
The first one is the "push_swap" program that takes the list of numbers as input, determines the best use of instructions to sort the list then outputs them in the terminal.  
![Screenshot 2022-11-25 at 14-42-26 push_swap fr pdf](https://user-images.githubusercontent.com/52746061/203998124-0b01c0b3-105c-4670-be5d-62507c4684d4.png)

The second one is the "checker" program that takes the same list of numbers as input, reads and applies the instructions received by the terminal then finally confirms that the list is correctly sorted (OK) or not... (KO).  
![Screenshot 2022-11-25 at 14-44-05 push_swap fr pdf](https://user-images.githubusercontent.com/52746061/203998260-3ced866c-1cd8-458f-a6ca-bf0aef01c1a1.png)

Both programs can be combined to check automatically the result.  
![Screenshot 2022-11-25 at 14-45-13 push_swap fr pdf](https://user-images.githubusercontent.com/52746061/203998468-267ae17d-b55e-4314-b51d-a96911c414a6.png)

## Install

Create or update both programs ("push_swap" and "checker") from sources.

```
make
```

## Reinstall

Recompile completely both programs.

```
make re
```

## Clean

Delete object files created during installation.

```
make clean
```

## Uninstall

Delete object files but also both compiled programs.  
It will not affect the source code.

```
make fclean
```

## Usage

```
./push_swap 125 -1 65535 -42 [...]

./checker 125 -1 65535 -42 [...] -v -c -h [...]
 
./checker -v -c -h [...] 125 -1 65535 -42 [...]

./checker [...] 125 -v -1 65535 -c [...] -h -42 [...]

ARG="[...] 125 -1 65535 -42 [...] -v -c -d [...]"; ./push_swap $ARG | ./checker $ARG

ARG="`ruby -e "puts (0...500).to_a.shuffle.join(' ')"` -c -n -d [...]"; ./push_swap $ARG | ./checker $ARG
```

## MAN (complete user manual)

```
./checker -h
```

## Screenshot
![Capture d?????cran du 2022-11-25 15-34-57](https://user-images.githubusercontent.com/52746061/204007178-2c6e46e7-257e-49a3-9040-2525b4c9369f.png)

## Notes
In addition to the many searchs and retries to find the best algorithm, another difficult part of this project is to adapt each sorting concept using only the limited set of instructions.  
To reach the highest level of optimization required (in term of number of instructions used), I had to combine two sorting algorithms: Quicksort and Insertsort.  

## Keywords
Manipulation of stack  
Sorting algorithms  
Algorithms Complexity (Big O Notation)  
