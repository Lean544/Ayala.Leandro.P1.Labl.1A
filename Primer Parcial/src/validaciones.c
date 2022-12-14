/*
 * validaciones.c
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char* cadena,int largo)
{
	int retorno=-1;
	//int size;
	//char* pNombre;

	fflush(stdin);
	fgets(cadena,largo,stdin);
	(*(cadena+strlen(cadena)-1))='\0';

	/*size=strlen(cadena);
	printf("%d\n",size);
	pNombre=malloc(size*sizeof(char));

	if(pNombre==NULL)
	{
		printf("Error al asignar la memoria\n");
	}else
	{

		strcpy(pNombre,cadena);
		free(pNombre);
	}*/

	return retorno;
}

int esNumerica(char*cadena){
	int retorno=1;
	int i;

	if((*(cadena+0))=='-')
	{
		i=1;
	}else
	{
		i=0;
	}

	for(;(*(cadena+i))!='\0';i++)
	{
		if((*(cadena+i))>'9'||(*(cadena+i))<'0'){
			retorno=0;
			break;
		}
	}

	return retorno;
}

int esAlfabetica(char cadena[]){
	int retorno=1;
	int i;

	for(i=0;*(cadena+i)!='\0';i++)
	{
		if(((*(cadena+i))>'z'||(*(cadena+i))<'a') && ((*(cadena+i))>'Z'||(*(cadena+i))<'A')){
			retorno=0;
			break;
		}
	}

	return retorno;
}

int esCodigo(char*cadena){
	int retorno=1;
	int i;

	for(i=0;(*(cadena+i))!='\0';i++)
	{
		if(((*(cadena+i))>'z'||(*(cadena+i))<'a') && ((*(cadena+i))>'Z'||(*(cadena+i))<'A') &&
		((*(cadena+i))>'9'||(*(cadena+i))<'0')){
					retorno=0;
					break;
		}
	}

	return retorno;
}

int getInt(int* pResultado){
		int retorno=-1;
		char buffer[4096];



		if(myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
		{
			retorno=0;
			*pResultado=atoi(buffer);
		}

		return retorno;
	}

int getFloat(int* pResultado)
{
	int retorno=-1;
	char buffer[4096];



	if(myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atof(buffer);
	}

	return retorno;
}

int getShort(short* pResultado)
{
	int retorno=-1;
	char buffer[4096];



	if(myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int getCadena(char pResultado[])
{
	int retorno=-1;
	char buffer[51];



	if(myGets(buffer,sizeof(buffer)) && esAlfabetica(buffer))
	{
		retorno=0;

		strcpy(pResultado,buffer);


	}

	return retorno;
}

int getCodigo(char pResultado[])
{
	int retorno=-1;
	char buffer[51];



	if(myGets(buffer,sizeof(buffer)) && esCodigo(buffer))
	{

		retorno=0;
		strcpy(pResultado,buffer);


	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,
char* mensajeError,int minimo,int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}

	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje,
char* mensajeError,float minimo,float maximo, int reintentos)
{
	int retorno=-1;

	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}


	return retorno;
}

int utn_getNumeroCorto(short* pResultado, char* mensaje,
char* mensajeError,float minimo,float maximo, int reintentos)
{
	int retorno=-1;

	short buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getShort(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}


	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,
char* mensajeError,char minimo,char maximo, int reintentos)
{
	int retorno=-1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL &&
	mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s\n",mensaje);
			scanf("%s",&buffer);

			if(buffer>=minimo && buffer<=maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}

	return retorno;
}

int utn_getCadena(char pResultado[],char* mensaje,char* mensajeError,int largo,int reintentos){
	int retorno;
	char buffer[largo];

	if(pResultado != NULL && mensaje != NULL &&
	mensajeError != NULL && largo>0 && reintentos>0)
	{
		do{
			printf("%s\n",mensaje);


			if(getCadena(buffer)==0)
			{

				//strcpy(*pResultado,buffer);
				strcpy(pResultado,buffer);

				retorno = 0;
				break;
			}else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}


	return retorno;
}

int utn_getCodigo(char pResultado[],char* mensaje,char* mensajeError,int largo,int reintentos){
	int retorno;
	char buffer[largo];

	if(pResultado != NULL && mensaje != NULL &&
	mensajeError != NULL && largo>0 && reintentos>0)
	{
		do{
			printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);

			if(getCodigo(buffer)==0 && strlen(buffer)<=largo)
			{
				//*pResultado = buffer;
				strcpy(pResultado,buffer);
				retorno = 0;
				break;
			}else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}


	return retorno;
}
