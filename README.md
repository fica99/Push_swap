# Push_swap

Sorting algorithm using only two stacks

## Description

The *Push_swap* project is a very simple and highly effective algorithm project: data will need to be sorted.
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

Write 2 programs in C:
* The first, named *checker* which takes integer arguments and reads instructions onthe standard output. Once read, checker executes them and displays *OK* if integers are sorted. Otherwise, it will display *KO*.

* The second one called *push_swap* which calculates and displays on the standard output the smallest progam using *Push_swap* instruction language that sorts integer arguments received.

Easy?

The idea is simple, You have two stacks called *Stack A* and *Stack B*. Stack A is given a random list of unorganized numbers. You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest. There are only a few moves you’re allowed to used to manipulate the stacks that we’re going to call “Actions”. The main goal of this project is to organize Stack A in as few actions as possible.

## Push_swap instructions

* *sa* : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

* *sb* : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

* *ss* : *sa* and *sb* at the same time.

* *pa* : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

* *pb* : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

* *ra* : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

* *rb* : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

* *rr* : *ra* and *rb* at the same time.

* *rra* : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

* *rrb* : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

* *rrr* : *rra* and *rrb* at the same time.

## Usage

### Compilation

```
git clone https://github.com/fica99/Push_swap
cd Push_swap
make
```

### Example

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Debug option for checker -v that can display the stack’s status after each operation

## Tester

```
./test.sh -full 0 500 10
```
