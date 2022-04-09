#define EOF (-1)
#define START 0
#define INT 1
#define PLUS 2
#define MINUS 3
#define STAR 4
#define SLASH 5


typedef struct token
{
	int type;
	int ivalue;
	char* svalue;
} token_t;

token_t create_token(int type, int ivalue, char* svalue);

