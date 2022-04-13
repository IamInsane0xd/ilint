#pragma once

typedef struct
{
	int length;
	void** items;
} array_t;

void init_array(array_t* array, int start_length, void* first_element);

void array_append(array_t* array, void* element);
