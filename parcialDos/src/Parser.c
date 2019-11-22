#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"


/*int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros)
{
	int retorno = -1;
	Cachorro* auxCachorro;

	char id[50];
	char nombre[50];
	char dias[50];
	char raza[50];
	char reservado[50];
	char genero[50];


	if(listaCachorros != NULL && pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			auxCachorro = cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
			if(auxCachorro != NULL)
			{
				ll_add(listaCachorros,auxCachorro);
				retorno = 0;
			}
			else
				break;

		}while(!feof(pFile));
	}
	fclose(pFile);
	pFile = NULL;
    return retorno; // OK
}*/

int parser_parserCachorros(char* fileName, LinkedList* listaCachorros)
{
	int retorno = -1;
	Cachorro* auxCachorro;

	char id[50];
	char nombre[50];
	char dias[50];
	char raza[50];
	char reservado[50];
	char genero[50];

	FILE* pFile;


	pFile = fopen(fileName,"r");

	if(listaCachorros != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			auxCachorro = cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
			if(auxCachorro != NULL)
			{
				ll_add(listaCachorros,auxCachorro);
				retorno = 1;
			}
			else
				break;

		}while(!feof(pFile));
	}
	fclose(pFile);
	fileName = NULL;
    return retorno; // OK
}
