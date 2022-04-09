#include "includes/token.h"

token_t create_token(int type, int ivalue, char* svalue)
{
	token_t token;

	token.type = type;
	token.ivalue = ivalue;
	token.svalue = svalue;

	return token;
}

