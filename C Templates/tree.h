#pragma once

#include <stdlib.h>

struct Data
{
	int i;
};

struct Element
{
	struct Element* left;
	struct Data* info;
	struct Element* right;
};


void print_daten(struct Data* data);

struct Element* append_leaf(struct Data* data, struct Element* element, int pos);

void delete_leaf(struct Element* element, int pos);

void delete_subtree(struct Element* element, int pos);

void traverse0(struct Element* element);

void traverse1(struct Element* element);

void traverse2(struct Element* element);

struct Element* search_element(struct Element* element, struct Data* data);

struct Element* search_sorted(struct Element* element, struct Data* data);

struct Element* insert(struct Element* element, struct Data* data);

/*
	int i --> Data to save
	Element* left --> pointer to left node of tree
	Data* info --> pointer to the Data
	Element* right --> pointer to right node of tree
*/