#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"


int parser_cachorrosParser(FILE* pFile, LinkedList* listaCachorros)
{
	int retorno = -1;
	Cachorro* auxCachorro;

	char ID_Cachorro[50];
	char Nombre[50];
	char Dias[50];
	char Raza[50];
	char Reservado[2];
	char Genero[1];


	if(listaCachorros != NULL && pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);
			auxCachorro = cachorro_newParametros(ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);
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
	pFile = NULL;
    return retorno; // OK
}

