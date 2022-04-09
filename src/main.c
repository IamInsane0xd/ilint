#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "includes/lexer.h"
#include "includes/utils.h"

int main()
{
	for (;;)
	{
		char text[1024];

		printf("? ");
		scanf("%s", text);

		if (is_string_whitespace(text))
			continue;

		lexer_t* lexer = create_lexer(text);
		lex(lexer);

		printf("length: %i\n", lexer->tokens.size);
	}

	return 0;
}

