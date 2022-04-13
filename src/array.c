#include <stdlib.h>

#include "includes/array.h"

void init_array(array_t* array, int start_length, void* first_element)
{
	array->length = start_length;
	array->items = calloc(array->length, sizeof(first_element) * array->length);
	array->items[0] = first_element;
}

void array_append(array_t* array, void* element)
{
	int size = 0;

	for (int i = 0; i < array->length; i++)
		size += sizeof(array->items[i]);

	array->items = realloc(array->items, size + sizeof(element));
	array->items[array->length++] = element;
}
