#pragma once

#include <stdlib.h>

struct Data
{
	int i;
};

struct Element
{
	struct Element* prev;
	struct Data* info;
	struct Element* next;
};

struct Element* insert(struct Data* data, struct Element* element);

void delete(struct Element* element);

int equal(struct Data* data1, struct Data* data2);

struct element* search(struct Data* data, struct Element* a);

void display_all(struct Element* a);

void delete_all(struct Element* a);

/*
	int i --> Data to save
	Element* prev --> pointer to the previous element
	Data* info --> pointer to the Data
	Element* next --> pointer to the next element
*/