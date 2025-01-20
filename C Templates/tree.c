#include "tree.h"

#define LEFT 0
#define RIGHT 1

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

void print_daten(struct Data* data) 
{
	if (data)
	{
		printf("%data", data->i);
	}
	else
	{
		printf("_");
	}
}

struct Element* append_leaf(struct Data* data, struct Element* element, int pos)
{
	struct Element* temp;
	temp = (struct Element*)malloc(sizeof(struct Element));
	temp->info = (struct Data*)malloc(sizeof(struct Data));
	*(temp->info) = *data; 
	temp->left = temp->right = NULL;
	if (pos == LEFT)
	{
		element->left = temp;
	}
	else
	{
		element->right = temp;
	}
	return temp;
}

void delete_leaf(struct Element* element, int pos) 
{
	if ((pos == LEFT) && (element->left))
	{
		free(element->left->info);
		free(element->left); 
		element->left = NULL;
	}
	if ((pos == RIGHT) && (element->right)) 
	{
		free(element->right->info);
		free(element->right);
		element->right = NULL;
	}
}

void delete_subtree(struct Element* element, int pos) 
{
	if (element == NULL)
	{
		return;
	}
	if (pos == LEFT) {

		delete_subtree(element->left, LEFT);
		delete_subtree(element->left, RIGHT);
	}
	else 
	{
		delete_subtree(element->right, LEFT);
		delete_subtree(element->right, RIGHT);
	}
	delete_leaf(element, pos);
}

void traverse0(struct Element* element) 
{
	if (element != NULL) 
	{
		printdaten(element->info);
		traverse0(element->left);
		traverse0(element->right);
	}
}

void traverse1(struct Element* element)
{
	if (element != NULL) 
	{
		traverse1(element->left);
		printdaten(element->info);
		traverse1(element->right);
	}
}

void traverse2(struct Element* element) 
{
	if (element != NULL) 
	{
		traverse2(element->left);
		traverse2(element->right);
		printdaten(element->info);
	}
}

// search in unsorted tree
struct Element* search_element(struct Element* element, struct Data* data) 
{
	struct Element* temp;
	if (element == NULL)
	{
		return NULL;
	}
	if (element->info->i == data->i)
	{
		return element; 
	}
	if ((temp = search_element(element->left, data)) != NULL)
	{
		return temp;
	}
	return(search_element(element->right, data));
}

// search in sorted tree
struct Element* search_sorted(struct Element* element, struct Data* data) 
{
	if (element == NULL)
	{
		return NULL;
	}
	if (element->info->i == data->i)
	{
		return element;
	}
	if (data->i < element->info->i)
	{
		return search_sorted(element->left, data);
	}
	else
	{
		return search_sorted(element->right, data); 
	}
}

struct Element* insert(struct Element* element, struct Data* data) 
{
	struct Element* temp;
	if (element == NULL) 
	{ 
		temp = (struct Element*)malloc(sizeof * temp);
		temp->info = (struct Data*)malloc(sizeof * data);
		*(temp->info) = *data; 
		temp->left = temp->right = NULL;
		return temp;
	}
	if (data->i < element->info->i) 
	{
		temp = insert(element->left, data);
		if (element->left == NULL)
		{
			element->left = temp;
		}
	}
	else 
	{ 
		temp = insert(element->right, data);
		if (element->right == NULL)
		{
			element->right = temp;
		}
	}
	return temp;
}

