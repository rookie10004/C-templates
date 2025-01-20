#include "doubly_linked_list.h"

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

struct Element* insert(struct Data* data, struct Element* element)
{
	struct Element* temp;
	temp = (struct Element*)malloc(sizeof(struct Element));
	temp->info = (struct Data*)malloc(sizeof(struct Data));
	temp->next = element->next;
	if (temp->next != NULL)
	{
		temp->next->prev = temp;
	}
	element->next = temp; temp->prev = element;
	*(temp->info) = *data;
	return temp;
}

void delete(struct Element* element) 
{
	if (element == NULL)
	{
		return;
	}
	if (element->prev != NULL)
	{
		element->prev->next = element->next;
	}
	if (element->next != NULL)
	{
		element->next->prev = element->prev;
	}
	free(element->info); 
	free(element);
}

int equal(struct Data* data1, struct Data* data2)
{
	if (data1->i == data2->i)
	{
		return 1;
	}
	return 0;
}


struct element* search(struct Data* data, struct Element* a)
{
	for (a = a->next; (NULL != a) && !equal(a->info, data); a = a->next)
		;
	return a;
}

void display_all(struct Element* a)
{
	printf("\nDie Elemente: ");
	for (a = a->next; a != NULL; a = a->next)
	{
		printdaten(a->info);
	}
	printf("\n");
}

void delete_all(struct Element* a) 
{
	while (a->next)
	{
		delete(a->next);
	}
}
