#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"



int parser_parserCachorros(char* fileName, LinkedList* listaComputers)
{
	int retorno = -1;
	eComputer* auxComputer;

    char id[4096];
	char descripcion[4096];
	char precio[4096];
	char idTipo[4096];

	FILE* pFile;

	pFile = fopen(fileName,"r");

	if(listaComputers != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			auxCachorro = cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
			if(auxCachorro != NULL)
			{
				ll_add(listaComputers,auxCachorro);
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




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int saveArchivo(char* path , LinkedList* listaComputers)
{
    Cachorro* auxCachorro;
    int retorno = -1;
    int i;

    int id;
    char nombre[50];
    int dias;
    char raza[50];
    char reservado[3];
    char genero[2];

    FILE* pFile;
    pFile = fopen(path,"wb");

	if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,dias,raza,reservado,genero\n");
        for(i=0; i<ll_len(listaComputers); i++)
        {
            auxCachorro = ll_get(listaComputers,i);

            cachorro_getId(auxCachorro,&id);
            cachorro_getNombre(auxCachorro,nombre);
            cachorro_getDias(auxCachorro,&dias);
            cachorro_getRaza(auxCachorro,raza);
            cachorro_getReservado(auxCachorro,reservado);
            cachorro_getGenero(auxCachorro,genero);
            fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",id,nombre,dias,raza,reservado,genero);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}
