/*
 ============================================================================
 Name        : parcialDos.c
 Author      : Brian Pavon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"
#include "Parser.h"
#include "utn.h"


int main(void)
{
	int option;
	int flag = 0;

	LinkedList* pAarrayPuppyList;
	pAarrayPuppyList = ll_newLinkedList();
	do{

	    printf(	 "Menu:\n\n"
				 "1. Cargar archivo\n"
				 "2. Imprimir lista\n"
				 "3. Filtrar menores de 45 dias(generar archivo)\n"
				 "4. Filtrar machos(generar archivo)\n"
				 "5. Generar listado de callejeros\n"
				 "6. Salir\n");

	    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,6,2);

	        switch(option)
	        {
	            case 1:

	                if(flag == 0)
	                {
	                    if(parser_parserCachorros("cachorros.csv",pAarrayPuppyList)==1)
	                    {
	                        printf("Lista cargada con exito\n");
	                        flag = 1;
	                        system("pause");
	                    }
	                }
	                else
	                    {
	                        if(flag == 1)
	                        {
	                            printf("Ya se cargaron los archivos\n");
	                            system("pause");
	                        }
	                    }

	                break;
	            case 2:
	                if(flag == 1)
	                {
	                	cachorro_imprimirTodosLosCachorros(pAarrayPuppyList);
	                }
	                else
	                {
	                	printf("Debe cargar un archivo primero\n");
	                }
	            	break;
	            case 3:

	            	break;

	            case 4:

	                break;

	            case 5:


	                break;

	        }
	    }while(option != 6);
	return EXIT_SUCCESS;
}
