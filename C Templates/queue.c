#include "queue.h"

typedef enum { false, true } boolean;

#define size 5

int enqueue(int a[], int value, int* IN, int OUT, boolean* empty)
{
    if (*IN == OUT && !*empty)
    {
        return -1;
    }
    else
    {
        a[*IN] = value;
        *IN = (*IN + 1) % size;
        *empty = false;
        return 0;
    }
}

int dequeue(int a[], int* value, int IN, int* OUT, boolean* empty)
{
    if (*empty)
    {
        return -1;
    }
    else
    {
        *value = a[*OUT];
        *OUT = (*OUT + 1) % size;
        if (IN == *OUT)
        {
            *empty = true;
        }
        return 0;
    }
}
