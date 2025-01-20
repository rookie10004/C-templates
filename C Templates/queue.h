#pragma once

typedef enum { false, true } boolean;

int enqueue(int a[], int value, int* IN, int OUT, boolean* empty);

int dequeue(int a[], int* value, int IN, int* OUT, boolean* empty);

/*
    int a[] --> Queue array
    int value --> value to save
    int IN --> anchor end
    int OUT --> anchor start
    boolean empty --> boolean for empty or not
*/