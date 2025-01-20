#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int* collection;
	int capacity;
	int size;
}Stack;

Stack* create_stack(int capacity);

void destroy_stack(Stack* stack);

bool is_full(Stack* stack);

bool is_empty(Stack* stack);

bool push(Stack* stack, int item);

bool pop(Stack* stack, int* item);

bool peek(Stack* stack, int* item);

/*
	int* collection --> pointer to dynamically allocated array (of integers in this case)
	int capacity --> size of array
	int size --> number of elements in the array
*/