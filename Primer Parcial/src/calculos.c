/*
 * calculos.c
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "listar.h"

int cargaForzada(eTipo cosas[],eColor cosasC[],eServicio cosasS[],eCliente cosasCl[],eTrabajo trabajo[],eMascota mascota[],int tamUno,int tamDos,int tamTres,int tamCuatro,int tamCinco){
	int retorno=0;
	int retornoUno=0;
	int retornoDos=0;
	int retornoTres=0;
	int retornoCuatro=0;
	int i;
	int cont=0;
	eTipo auxTipos[]={{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};
	eColor auxColores[]={{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};
	eServicio auxServicios[]={{20000,"Corte",450},{20001,"Desparasitado",800},{20002,"Castrado",600}};
	eCliente auxClientes[]={{200,"Veronica","Mujer"},{201,"Cristian","Hombre"},{202,"Rocio","Mujer"},{203,"Julio","Hombre"},{204,"Mara","Mujer"}};
	eTrabajo auxTrabajos[]={{125,140,20001,{2023,7,15},0},{126,141,20002,{2024,1,1},0},{127,142,20000,{2022,10,8},0}};
	eMascota auxMascotas[]={{140,"Maximo",1001,5002,200,15,'n',0},{141,"Adolfin",1003,5003,201,10,'s',0},{142,"Eugenio",1004,5000,202,9,'n',0}};

	for(i=0;i<tamUno;i++){
		cosas[i]=auxTipos[i];
		retornoUno=1;
	}
	for(i=0;i<tamDos;i++){
		cosasC[i]=auxColores[i];
		retornoDos=1;
	}
	for (i=0;i<tamTres;i++){
		cosasS[i]=auxServicios[i];
		retornoTres=1;
	}
	for(i=0;i<tamCuatro;i++){
		cosasCl[i]=auxClientes[i];
		retornoCuatro=1;
	}
	for(i=0;i<tamCinco;i++){
		if(cont<3){
			trabajo[i]=auxTrabajos[cont];
			cont=cont+1;
		}else{
			break;
		}
	}
	cont=0;
	for(i=0;i<tamCinco;i++){
		if(cont<=3){
			mascota[i]=auxMascotas[cont];
			cont=cont+1;
		}else{
			break;
		}
	}

	if(retornoUno==1 && retornoDos ==1 && retornoTres ==1 && retornoCuatro==1){
		retorno=1;
	}


	return retorno;
}

int inicializar (eMascota personas[],int len,eTrabajo trabajos[]){
	int retorno=0;
	int i;

	if(personas != NULL && len > 0){
		for(i=0;i<len;i++){
			personas[i].isEmpty=1;
			trabajos[i].isEmpty=1;
			retorno=1;
		}
	}

	return retorno;
}

int buscarLibre(eMascota personas[],int len,int* libre){
	int retorno=-1;
	int i;

	for(i=0;i<len;i++){
		if(personas[i].isEmpty==1){
			retorno=1;
			*libre=i;
			break;
		}

	}
	return retorno;
}

int buscarTrabajoLibre(eTrabajo* trabajo,int len,int* libre){
	int retorno=-1;
	int i;

	for(i=0;i<len;i++){
		if((trabajo+i)->isEmpty==1){
			retorno=1;
			*libre=i;
			break;
		}

	}
	return retorno;
}

int buscarPorId(eMascota personas[],int TAM,int buscar,int* retornoPos){
	int retorno=0;

	for(int i=0;i<TAM;i++){
		if(buscar==personas[i].id){
			*retornoPos=i;
			retorno=1;
			break;
		}
	}
	return retorno;
}

int cargarFecha(eTrabajo* trabajo,int pos){

	int retorno=0;
	int flagDia=0;
	int flagMes=0;
	int flagAnio=0;

	do{
		utn_getNumero(&(trabajo+pos)->fecha.anio,"Que a�o desea tener el turno?(hasta 2024)","Error",2022,2024,5);
		if((trabajo+pos)->fecha.anio>=2022 && (trabajo+pos)->fecha.anio <=2024){
			flagAnio=1;
		}
	}while(flagAnio!=1);

	do{
		utn_getNumero(&(trabajo+pos)->fecha.mes,"Que mes desea tener el turno?","Error",1,12,5);
		if((trabajo+pos)->fecha.mes >= 1 && (trabajo+pos)->fecha.mes <= 12){
			flagMes=1;

		}
	}while(flagMes!=1);

	do{
		utn_getNumero(&(trabajo+pos)->fecha.dia,"Que dia desea tener el turno?","Error",1,31,5);
		if(((trabajo+pos)->fecha.mes==2 && (trabajo+pos)->fecha.dia <=28) ||
		((trabajo+pos)->fecha.mes==4 && (trabajo+pos)->fecha.dia<=30) ||
		((trabajo+pos)->fecha.mes==6 && (trabajo+pos)->fecha.dia<=30) ||
		((trabajo+pos)->fecha.mes==9 && (trabajo+pos)->fecha.dia<=30) ||
		((trabajo+pos)->fecha.mes==11 && (trabajo+pos)->fecha.dia<=30)){
			flagDia=1;
		}else if(((trabajo+pos)->fecha.mes==1 && (trabajo+pos)->fecha.dia <31) || ((trabajo+pos)->fecha.mes==3 && (trabajo+pos)->fecha.dia <31) ||
		((trabajo+pos)->fecha.mes==5 && (trabajo+pos)->fecha.dia <31) ||
		((trabajo+pos)->fecha.mes==7 && (trabajo+pos)->fecha.dia<=31) ||
		((trabajo+pos)->fecha.mes==8 && (trabajo+pos)->fecha.dia<=31) ||
		((trabajo+pos)->fecha.mes==10 && (trabajo+pos)->fecha.dia<=31) ||
		((trabajo+pos)->fecha.mes==12 && (trabajo+pos)->fecha.dia<=31)){
			flagDia=1;
		}
	}while(flagDia!=1);

	if(flagAnio == 1 && flagMes == 1 && flagDia == 1){
		retorno=1;
	}

	return retorno;
}

int cargar(eMascota personas[],int* ids,eTipo tipo[],eColor color[],eCliente cliente[],int TAM,int tamTipo,int tamColor,int tamCliente){
	int retorno=0;
	int pos;
	int i;
	int flagComprobar=0;
	int flagCliente;

	if(personas!=NULL && tipo!=NULL && color !=NULL && *ids > -1 && TAM > 0){
		if(buscarLibre(personas,TAM,&pos)==1){

			utn_getCadena(personas[pos].nombre,"Ingrese El nombre de la mascota","error",20,5);

			printf("Lista de Tipos:\n");
			listarTipos(tipo,tamTipo);

			do{
				utn_getNumero(&personas[pos].idTipo,"Ingrese el id del tipo de mascota","Error",1000,1004,5);
				for(i=0;i<tamTipo;i++){
					if(personas[pos].idTipo==tipo[i].id){
						flagComprobar=1;
					}
				}
			}while(flagComprobar==0);

			printf("Lista de Colores:\n");
			listarColores(color,tamColor);

			do{
				flagComprobar=0;
				utn_getNumero(&personas[pos].idColor,"Ingrese el id del color de la mascota","Error",5000,5004,5);
				for(i=0;i<tamTipo;i++){
					if(personas[pos].idColor==color[i].id){
						flagComprobar=1;
					}
				}
			}while(flagComprobar==0);


			utn_getNumero(&personas[pos].edad,"Ingrese la edad de la mascota","error",0,20,5);

			do{
				flagComprobar=0;
				utn_getCaracter(&personas[pos].vacunado,"Esta vacunada la mascota? s/n","Error",'n','s',5);

				if(personas[pos].vacunado=='s' || personas[pos].vacunado == 'n'){
					flagComprobar=1;
				}else{
					printf("Error Respuesta Invalida\n");
				}
			}while(flagComprobar==0);

			do{
				printf("Lista de clientes:\n");
				listarClientes(cliente,tamCliente);

				utn_getNumero(&personas[pos].idCliente,"Ingrese el id del cliente","Error",200,204,6);

				for(i=0;i<tamCliente;i++){
					if(personas[pos].idCliente==cliente[i].id){
						flagCliente=1;
						break;
					}
				}
			}while(flagCliente !=1);

			*ids= *ids+1;

			personas[pos].id=*ids;
			personas[pos].isEmpty=0;
			retorno=1;

			printf("Id Asignado a la mascota:%d\n",personas[pos].id);
		}


	}



	return retorno;
}

int modificar(eMascota personas[],int TAM,eTipo tipo[],int tamTipos){
	int retorno=0;
	int idBuscar;
	int pos;
	int menu;
	int i;
	int flagComprobar;

	utn_getNumero(&idBuscar,"Ingrese el id de la mascota a buscar","Error",1,TAM,5);

	if(buscarPorId(personas,TAM,idBuscar,&pos)==1){

		utn_getNumero(&menu,"Que desea modificar?\n 1.Tipo de Mascota\n2.Estado de vacunacion\n","Error",1,2,5);

		switch(menu){

			case 1:

				printf("Lista de Tipos:\n");

				for(i=0;i<tamTipos;i++){

					printf("Id->%d, Tipo:%s\n",tipo[i].id,tipo[i].descripcion);
				}

				do{
					utn_getNumero(&personas[pos].idTipo,"Ingrese el id del tipo de mascota","Error",1000,1004,5);
					for(i=0;i<tamTipos;i++){
						if(personas[pos].idTipo==tipo[i].id){
							flagComprobar=1;
							retorno=1;
						}
					}
				}while(flagComprobar==0);
				break;

			case 2:
				do{
					flagComprobar=0;
					utn_getCaracter(&personas[pos].vacunado,"Esta vacunada la mascota? s/n","Error",'n','s',5);

					if(personas[pos].vacunado=='s' || personas[pos].vacunado == 'n'){
							flagComprobar=1;
							retorno=1;
					}else{
						printf("Error Respuesta Invalida\n");
					}
				}while(flagComprobar==0);

				break;
			}


	}


	return retorno;
}

int baja(eMascota personas[],int TAM){
	int retorno=0;
	int idBuscar;
	int pos;

	utn_getNumero(&idBuscar,"Ingrese el id de la mascota a dar de baja","Error",1,TAM,5);

		if(buscarPorId(personas,TAM,idBuscar,&pos)==1){
			printf("Se procedera a dar de baja a la mascota\n");
			personas[pos].isEmpty=1;
			retorno=1;
		}


	return retorno;
}

int ordenar(eMascota personas[],int TAM){
	int flagCambio;
	int i;
	int retorno=0;
	eMascota auxMascota;

	do{
		flagCambio = 0;
		for(i = 0; i < TAM-1; i++){
			if((personas[i].idTipo > personas[i+1].idTipo && stricmp ( personas[i].nombre,personas[i+1].nombre ) > 0) && personas[i].isEmpty==0){

				auxMascota=personas[i];
				personas[i]=personas[i+1];
				personas[i+1]=auxMascota;
				retorno=1;
				flagCambio = 1;
			}
		}
	}while(flagCambio == 1);



	return retorno;
}

int ingresarTrabajo(eMascota sujetos[],int tamSujetos,eTrabajo* trabajo,int tamTrabajo,eServicio servicios[],int tamServicios,
		eColor color[],int tamColor,eTipo tipo[],int tamTipo,eCliente clientes[],int tamClientes,int* contIdTrabajo){
	int retorno=0;
	int flagId=0;
	int flagFecha=0;
	int flagServicio=0;
	int pos;
	int buscar;
	int posTrabajo;

	if(buscarTrabajoLibre(trabajo,tamTrabajo,&posTrabajo)==1){
		printf("Mascotas Ingresadas:\n");
		listarMascotas(sujetos,tamSujetos,tipo,tamTipo,color,tamColor,clientes,tamClientes);

		do{
			utn_getNumero(&buscar,"Ingrese la id de la mascota","Error",1,tamSujetos,5);

			if(buscarPorId(sujetos,tamSujetos,buscar,&pos)==1){
				flagId=1;
				(trabajo+posTrabajo)->idMascota=buscar;
				printf("Se ha encontrado a la mascota!\n");
			}else{
				printf("Error mascota no registrada!\n");
			}

		}while(flagId!=1);

		do{

			utn_getNumero(&(trabajo+posTrabajo)->idServicio,"�Que servicio desea hacerle?\n20000.Corte:450$\n"
				"20001.Desparasitado:$800\n20002.Castrado:$600","Error",20000,20002,5);
			for(int i=0;i<tamServicios;i++){
				if((trabajo+posTrabajo)->idServicio == servicios[i].id){
					flagServicio=1;
					break;
				}
			}
		}while(flagServicio!=1);

		if(cargarFecha(trabajo,posTrabajo)==1){
			flagFecha=1;
		}

		if(flagId==1 && flagFecha==1){
			(trabajo+posTrabajo)->isEmpty=0;
			*contIdTrabajo = *contIdTrabajo + 1;
			(trabajo+posTrabajo)->id=*contIdTrabajo;
			retorno=1;
		}
	}
	return retorno;
}


//el array de clientes se hardcodea
