#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include "Cachorros.h"
//int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros);
int parser_parserCachorros(char* fileName, LinkedList* listaCachorros);

#endif // PARSER_H_INCLUDED
