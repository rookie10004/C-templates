#include "singly_linked_list.h"

struct Data
{
	int i;
};

struct Element 
{
	struct Data* info;
	struct Element* next
};

void print_data(struct Data* data)
{
	printf("%d", data->i);
}

struct Element anchor = { 0,0 };

struct Element* insert(struct Data* data, struct Element* element)
{
	struct Element* temp;
	temp = (struct Element*)malloc(sizeof(struct Element));
	temp->info = (struct Data*)malloc(sizeof(struct Data));
	*(temp->info) = *data;
	temp->next = element->next;
	element->next = temp;
	return temp;
}

void delete(struct Element* element)
{
	struct Element* temp;
	if (element->next) {
		temp = element->next;
		element->next = temp->next;
		free(temp->info); 
		free(temp);
	}
}

void delete_all(struct Element* element) 
{
	while (element->next)
	{
		delete(element);
	}
}

void display_all(struct Element* a) 
{
	printf("\nDie Elemente: ");
	for (a = a->next; a != NULL; a = a->next)
		printdaten(a->info);
	printf("\n");
}