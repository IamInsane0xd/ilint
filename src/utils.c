#include <stdio.h>
#include <ctype.h>

#include "includes/utils.h"

int is_string_whitespace(const char* s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char) *s))
			return 0;

		s++;
	}

	return 1;
}

int reverse_int(int n)
{
	int reverse = 0;
	int remainder;

	while (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}

	return reverse;
}

int get_stdin_line(char* buffer)
{
	char c;
	int i = 0;

	while ((c = getc(stdin)) != '\n')
		buffer[i++] = c;

	buffer[i] = '\0';

	return 1;
}

