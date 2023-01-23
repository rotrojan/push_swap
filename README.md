# push_swap
This 42 project is about sorting data on a stack with a limited set of instructions using the lowest possible number of actions.

## Description
Two stacks named `a` and `b`. At the beginning, the stack `a` contains a random amount of negative and / or positive numbers which cannot be duplicated and the stack `b` is empty.
The goal is to sort in ascending order numbers into stack `a` using the following operations:
- `sa` (swap a): swap the first two elements at the top of stack `a`. Do nothing if there is only one or no elements.
- `sb` (swap b): swap the first two elements at the top of stack `b`. Do nothing if there is only one or no elements.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push a): take the first element at the top of `b` and put it at the top of `a`. Do nothing if b is empty.
- `pb` (push b): take the first element at the top of `a` and put it at the top of `b`. Do nothing if a is empty.
- `ra` (rotate a): shift up all elements of stack `a` by 1. The first element becomes the last one.
- `rb` (rotate b): shift up all elements of stack `b` by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` (reverse rotate a): shift down all elements of stack `a` by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): shift down all elements of stack `b` by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Implementation

Depending on the size of the list to sort, different algorithms are used:
- For a list of 270 numbers or less, a modified insertion sort is used: you can find a deeper explaination on this algorithm [here](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a).
The complexity of this algorithm is O(n²).
- For a list bigger than 270, a radix sort is used. This algorith is particularly suited to the two-stack paradigm (more details [here](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)).
The complexity of this algorithm is O(nb) with 'b' being the number of digit in the binary representation of the biggest number in 'n'.

A perfect sort is also used for lists of 3 or less, and a little variation is used for lists of 4 or 5).
## Usage

```sh
./push_swap [list of shuffled numbers ...]
```
Example: `./push_swap 5 9 7 2 6`

You can generate a shuffled list of numbers going from 1 to n with the following command: `seq [n] | sort -R | xargs`

Example: 
```sh
./push_swap $(seq 100 | sort -R | xargs)
```

To check if the operations correctly sort the list, use the `checker`.
Example:
```sh
NUMBERS=$(seq 100 | sort -R | xargs)
./push_swap $NUMBERS | ./checker $NUMBERS
```
### ⚠️ `zsh` users ⚠️
`zsh` automatically splits arguments on white spaces, causing `./push_swap` and `./checker` to fail. To prevent this behaviour, use the `(z)` modifier.
Example:
```sh
NUMBERS=$(seq 100 | sort -R | xargs)
./push_swap ${(z)NUMBERS} | ./checker ${(z)NUMBERS}
```

A special thanks to [Emmanuel Ruaud](https://github.com/o-reo) and his [visualizer](https://github.com/o-reo/push_swap_visualizer) which made the implementation so much easier.
