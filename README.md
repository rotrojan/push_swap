# push_swap
This 42 project is about sorting data on a stack with a limited set of instructions using the lowest possible number of actions.

## Usage

```
./push_swap [list of shuffled numbers ...]
```
Example: `./push_swap 5 9 7 2 6`

You can generate a shuffled list of numbers goin from 1 to n with the following command: `seq [n] | sort -R | xargs`

Example: `./push_swap $(seq 100 | sort -R | xargs)`

To check if the operations correctly sort the list, use the `checker`.
Example:
```
INSTRUCTIONS=(./push_swap $(seq 100 | sort -R | xargs))
```
