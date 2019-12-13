#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "LinkedList.h"
//int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros);
int parser_parserComputer(char* fileName, LinkedList* listaComputers);
int saveArchivo(char* path , LinkedList* listaComputers);

#endif // parser_H_INCLUDED
