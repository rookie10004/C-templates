#pragma once

#include <stdlib.h>

struct Data
{
	int i;
};

struct Element
{
	struct Data* info;
	struct Element* next
};

struct Element anchor = { 0,0 };

struct Element* insert(struct Data* data, struct Element* element);

void delete(struct Element* element);

void delete_all(struct Element* element);

void display_all(struct Element* a);

/*
	int i --> Data to save
	Data* info --> pointer to the Data
	Element* next --> pointer to the next element
*/