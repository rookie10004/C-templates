#include "stack.h"

typedef struct
{
	int* collection;
	int capacity;
	int size;
}Stack;

Stack* create_stack(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL)
	{
		return NULL;
	}
	stack->collection = malloc(sizeof(int) * capacity);
	if (stack->collection == NULL)
	{
		free(stack);
		return NULL;
	}
	stack->capacity = capacity;
	stack->size = 0;
}

void destroy_stack(Stack* stack)
{
	free(stack->collection);
	free(stack);
}

bool is_full(Stack* stack)
{
	return stack->capacity == stack->size;
}

bool is_empty(Stack* stack)
{
	return stack->size == 0;
}

bool push(Stack* stack, int item)
{
	if (is_full(stack))
	{
		return false;
	}
	stack->collection[stack->size] = item;
	stack->size++;
	return true;
}

bool pop(Stack* stack, int* item)
{
	if (is_empty(stack))
	{
		return false;
	}
	stack->size--;
	*item = stack->collection[stack->size];
	return true;
}

bool peek(Stack* stack, int* item)
{
	if (is_empty(stack))
	{
		return false;
	}
	*item = stack->collection[stack->size - 1];
	return true;
}