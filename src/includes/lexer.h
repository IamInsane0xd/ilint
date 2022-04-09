#include "token.h"

typedef struct token_array
{
	int size;
	token_t** items;
} token_array_t;

typedef struct lexer
{
	char* text;
	int text_length;
	int pos;
	char current_char;
	token_array_t tokens;
	int error;
} lexer_t;

lexer_t* create_lexer(char* text);

int lex(lexer_t* lexer_);

