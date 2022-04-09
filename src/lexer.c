#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "includes/lexer.h"
#include "includes/utils.h"

lexer_t* create_lexer(char* text)
{
	lexer_t* lexer;

	lexer->text = text;
	lexer->text_length = strlen(text);
	lexer->error = 0;

	token_array_t tokens = {1, calloc(1, sizeof(token_t*))};
	token_t token = create_token(START, 0, "start");

	lexer->tokens = tokens;
	lexer->tokens.items[0] = &token;

	return lexer;
}

int append_token(lexer_t* lexer, token_t token)
{
	lexer->tokens.size++;
	lexer->tokens.items = realloc(lexer->tokens.items, sizeof(token_t) * lexer->tokens.size);
	lexer->tokens.items[lexer->tokens.size - 1] = &token;

	printf("<value: %i, string: %s>\n", lexer->tokens.items[lexer->tokens.size - 1]->ivalue, lexer->tokens.items[lexer->tokens.size - 1]->svalue);

	return 1;
}

int advance(lexer_t* lexer)
{
	lexer->current_char = lexer->text[lexer->pos];
	lexer->pos++;
	return 1;
}

int lex_int(lexer_t* lexer)
{
	int length = 1;
	int value = atoi(&lexer->current_char);

	while (isdigit(lexer->current_char))
	{
		advance(lexer);

		value += atoi(&lexer->current_char) * pow(10, length);
		length++;

		if (lexer->pos > lexer->text_length - 1)
			break;
	}

	value = reverse_int(value);

	token_t token = create_token(INT, value, "int");
	append_token(lexer, token);

	if (lexer->pos <= lexer->text_length - 1)
		lexer->pos--;

	return 1;
}

int lex(lexer_t* lexer)
{
	lexer->pos = 0;

	for (;;)
	{
		if (lexer->pos > lexer->text_length - 1)
		{
			token_t token = create_token(EOF, 0, "eof");
			append_token(lexer, token);
			break;
		}

		advance(lexer);

		while (is_string_whitespace(&lexer->current_char))
			advance(lexer);

		switch (lexer->current_char)
		{
			case '1': case '2': case '3':
			case '4': case '5': case '6':
			case '7': case '8': case '9':
			case '0':
				lex_int(lexer);
				break;

			case '+':
			{
				token_t token = create_token(PLUS, 0, "+");
				append_token(lexer, token);
				break;
			}

			case '-':
			{
				token_t token = create_token(MINUS, 0, "-");
				append_token(lexer, token);
				break;
			}

			case '*':
			{
				token_t token = create_token(START, 0, "*");
				append_token(lexer, token);
				break;
			}

			case '/':
			{
				token_t token = create_token(SLASH, 0, "/");
				append_token(lexer, token);
				break;
			}

			default:
				printf("Error: unrecognized character '%c' (1:%i)\n", lexer->current_char, lexer->pos);
				lexer->error = 1;
				return 0;
		}
	}

	return 1;
}

