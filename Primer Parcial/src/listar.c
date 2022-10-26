/*
 * listar.c
 *
 *  Created on: 26 oct. 2022
 *      Author: ayala
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "cliente.h"
#include "calculos.h"

void listarTipos (eTipo tipo[],int tamTipo){

	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;

	printf("|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Tipo");
	for(int i=0;i<tamTipo;i++){
		printf("|%*d|%*s|\n",anchoColumnasTexto,tipo[i].id,anchoColumnasNumero,tipo[i].descripcion);
		printf("-------------------------------------------\n");
	}

}


void listarMascotas(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){

	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int i;
	int j;
	int x;
	int y;

	ordenar(personas,TAM);

	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
	"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
	anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");

	for(i=0;i<TAM;i++){

		if(personas[i].isEmpty==0){

			for(j=0;j<tamTipo;j++){
				if(personas[i].idTipo==tipo[j].id){
						break;
				}
			}

			for(x=0;x<tamColor;x++){
				if(personas[i].idColor==color[x].id){

					break;
				}
			}
			for(y=0;y<tamCliente;y++){
				if(personas[i].idCliente==cliente[y].id){

					break;
				}
			}

			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
			,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
			,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
			anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
		}
	}

}

void listarColores(eColor color[],int tamColor){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;

	printf("|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Color");
	for(int i=0;i<tamColor;i++){
		printf("|%*d|%*s|\n",anchoColumnasTexto,color[i].id,anchoColumnasNumero,color[i].nombreColor);
		printf("-------------------------------------------\n");
	}


}

void listarClientes(eCliente cliente[],int tamCliente){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;

	printf("|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasTexto,"Sexo");
	for(int i=0;i<tamCliente;i++){
		printf("|%*d|%*s|%*s|\n",anchoColumnasNumero,cliente[i].id,anchoColumnasTexto,cliente[i].nombre,anchoColumnasTexto,cliente[i].sexo);
		printf("-------------------------------------------\n");
	}


}

void listarServicios(eServicio servicio[],int tamServicio){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;

	printf("|%*s|%*s|%*s\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Servicio",anchoColumnasNumero,"Precio");
	for(int i=0;i<tamServicio;i++){
		printf("|%*d|%*s|%*f\n",anchoColumnasTexto,servicio[i].id,anchoColumnasNumero,servicio[i].descripcion,anchoColumnasNumero,servicio[i].precio);
		printf("-------------------------------------------\n");
	}
}

void listarTrabajos(eTrabajo* trabajo,int TAM,eMascota mascota[],eServicio servicio[],int tamServicio){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int i;
	int j;
	int x;

	printf("|%*s|%*s|%*s|%*s\n",anchoColumnasNumero,"Id",anchoColumnasTexto,"Mascota",anchoColumnasTexto,"Servicio",anchoColumnasTexto,"Fecha");
	for(i=0;i<TAM;i++){
		if((trabajo+i)->isEmpty==0){
			for(j=0;j<TAM;j++){
				if((trabajo+i)->idMascota==mascota[j].id){
					break;
				}
			}

			for(x=0;x<tamServicio;x++){
				if((trabajo+i)->idServicio==servicio[x].id){
					break;
				}
			}

			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*d|%*s|%*s|%d/%d/%d|\n",anchoColumnasNumero,(trabajo+i)->id,anchoColumnasTexto,mascota[j].nombre
			,anchoColumnasTexto,servicio[x].descripcion,(trabajo+i)->fecha.anio,(trabajo+i)->fecha.mes,(trabajo+i)->fecha.dia);
		}
	}

}

void listarColorSeleccionado(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){
	int seleccion;
	int retorno;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int j;
	int x;
	int y;

	listarColores(color,tamColor);
	retorno=utn_getNumero(&seleccion,"Que color desea mostrar?","Error",5000,5004,5);
	if(retorno==0){

		for(int i=0;i<TAM;i++){

			if(personas[i].idColor==seleccion && personas[i].isEmpty==0){

				for(j=0;j<tamTipo;j++){
					if(personas[i].idTipo==tipo[j].id){
									break;
						}
				}

				for(x=0;x<tamColor;x++){
					if(personas[i].idColor==color[x].id){

						break;
					}
				}

				for(y=0;y<tamCliente;y++){
					if(personas[i].idCliente==cliente[y].id){

							break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
						,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
				,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
				anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
			}
		}
	}
}

void listarPorcentajeVacunados(eMascota personas[],int TAM){

	int i;
	int contVacunadas=0;
	int contTotal=0;
	float promedio;

	for(i=0;i<TAM;i++){
		if(personas[i].isEmpty==0){
			contTotal= contTotal +1;
		}
	}

	for(i=0;i<TAM;i++){
		if(personas[i].vacunado == 's' && personas[i].isEmpty==0){
			contVacunadas= contVacunadas +1;
		}
	}

	promedio= contVacunadas*100/contTotal;

	printf("El promedio de las mascotas vacunadas es de %f por ciento\n",promedio);
}

void listarMenorEdad(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int i;
	int j;
	int x;
	int y;
	int menor=20;

	for(i=0;i<TAM;i++){
		if(personas[i].edad<menor && personas[i].isEmpty==0){
			menor=personas[i].edad;
		}
	}

	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
	"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
	anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
	for(i=0;i<TAM;i++){

		if(personas[i].isEmpty==0 && personas[i].edad<=menor){

			for(j=0;j<tamTipo;j++){
				if(personas[i].idTipo==tipo[j].id){
								break;
					}
			}

			for(x=0;x<tamColor;x++){
				if(personas[i].idColor==color[x].id){

					break;
				}
			}

			for(y=0;y<tamCliente;y++){
				if(personas[i].idCliente==cliente[y].id){

						break;
				}
			}

			printf("\n----------------------------------------------------------------------------------------------------\n");
			printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
					,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
			,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
			anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
		}
	}
}

void listarPorTipo(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int i;
	int j;
	int x;
	int y;

	printf("Tipo: Ave\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
		"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
		anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
		for(i=0;i<TAM;i++){

			if(personas[i].isEmpty==0 && personas[i].idTipo==1000){

				for(j=0;j<tamTipo;j++){
					if(personas[i].idTipo==tipo[j].id){
									break;
						}
				}

				for(x=0;x<tamColor;x++){
					if(personas[i].idColor==color[x].id){

						break;
					}
				}

				for(y=0;y<tamCliente;y++){
					if(personas[i].idCliente==cliente[y].id){

							break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
						,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
				,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
				anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
			}
		}

		printf("Tipo: Perro\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
		"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
		anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
			for(i=0;i<TAM;i++){

				if(personas[i].isEmpty==0 && personas[i].idTipo==1001){

					for(j=0;j<tamTipo;j++){
						if(personas[i].idTipo==tipo[j].id){
											break;
							}
					}

					for(x=0;x<tamColor;x++){
						if(personas[i].idColor==color[x].id){

							break;
						}
					}

					for(y=0;y<tamCliente;y++){
						if(personas[i].idCliente==cliente[y].id){

								break;
						}
					}

					printf("\n----------------------------------------------------------------------------------------------------\n");
					printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
					,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
					,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
					anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
				}
			}

			printf("Tipo: Roedor\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
			"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
			anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
				for(i=0;i<TAM;i++){

					if(personas[i].isEmpty==0 && personas[i].idTipo==1002){

						for(j=0;j<tamTipo;j++){
							if(personas[i].idTipo==tipo[j].id){
												break;
								}
						}

						for(x=0;x<tamColor;x++){
							if(personas[i].idColor==color[x].id){

								break;
							}
						}

						for(y=0;y<tamCliente;y++){
							if(personas[i].idCliente==cliente[y].id){

									break;
							}
						}

						printf("\n----------------------------------------------------------------------------------------------------\n");
						printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
						,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
						,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
						anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
					}
				}

				printf("Tipo: Gato\n");
				printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
				"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
				anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
					for(i=0;i<TAM;i++){

						if(personas[i].isEmpty==0 && personas[i].idTipo==1003){

							for(j=0;j<tamTipo;j++){
								if(personas[i].idTipo==tipo[j].id){
													break;
									}
							}

							for(x=0;x<tamColor;x++){
								if(personas[i].idColor==color[x].id){

									break;
								}
							}

							for(y=0;y<tamCliente;y++){
								if(personas[i].idCliente==cliente[y].id){

										break;
								}
							}

							printf("\n----------------------------------------------------------------------------------------------------\n");
							printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
							,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
							,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
							anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
						}
					}

					printf("Tipo: Pez\n");
					printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
					"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
					anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
						for(i=0;i<TAM;i++){

							if(personas[i].isEmpty==0 && personas[i].idTipo==1004){

								for(j=0;j<tamTipo;j++){
									if(personas[i].idTipo==tipo[j].id){
														break;
										}
								}

								for(x=0;x<tamColor;x++){
									if(personas[i].idColor==color[x].id){

										break;
									}
								}

								for(y=0;y<tamCliente;y++){
									if(personas[i].idCliente==cliente[y].id){

											break;
									}
								}

								printf("\n----------------------------------------------------------------------------------------------------\n");
								printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
								,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
								,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
								anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
							}
						}

}

void listarPorColorYTipo(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){
	int seleccionColor;
	int seleccionTipo;
	int retornoColor;
	int retornoTipo;
	int anchoColumnasTexto=-20;
	int anchoColumnasNumero=-20;
	int j;
	int x;
	int y;

	listarColores(color,tamColor);
	retornoColor=utn_getNumero(&seleccionColor,"Que color desea mostrar?","Error",5000,5004,5);

	listarTipos(tipo,tamTipo);
	retornoTipo=utn_getNumero(&seleccionTipo,"Que tipo desea mostrar?","Error",1000,1004,5);

	if(retornoColor==0 && retornoTipo==0){

		for(int i=0;i<TAM;i++){

			if(personas[i].idColor==seleccionColor && personas[i].idTipo==seleccionTipo && personas[i].isEmpty==0){

				for(j=0;j<tamTipo;j++){
					if(personas[i].idTipo==tipo[j].id){
									break;
						}
				}

				for(x=0;x<tamColor;x++){
					if(personas[i].idColor==color[x].id){

						break;
					}
				}

				for(y=0;y<tamCliente;y++){
					if(personas[i].idCliente==cliente[y].id){

							break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
						,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
				,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
				anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
			}
		}
	}
}

void listarColorMasCant(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){
	int anchoColumnasTexto=-20;
		int anchoColumnasNumero=-20;
		int i;
		int j;
		int x;
		int y;
		int contNegro=0;
		int contBlanco=0;
		int contRojo=0;
		int contGris=0;
		int contAzul=0;
		int colorMasCant;

		for(i=0;i<TAM;i++){

			if(personas[i].idColor==5000 && personas[i].isEmpty==0){
					contNegro=contNegro+1;
			}else if(personas[i].idColor==5001 && personas[i].isEmpty==0){
					contBlanco=contBlanco+1;
			}else if(personas[i].idColor==5002 && personas[i].isEmpty==0){
					contRojo=contRojo+1;
			}else if(personas[i].idColor==5003 && personas[i].isEmpty==0){
						contGris=contGris+1;
			}else if(personas[i].idColor==5004 && personas[i].isEmpty==0){
						contAzul=contAzul+1;
			}
		}

		if(contNegro>contBlanco && contNegro>contRojo && contNegro>contGris && contNegro>contAzul){
			colorMasCant=5000;
		}else if(contBlanco>contNegro && contBlanco>contRojo && contBlanco>contGris && contBlanco>contAzul){
			colorMasCant=5001;
		}else if(contRojo>contNegro && contRojo>contBlanco && contRojo>contGris && contRojo>contAzul){
			colorMasCant=5002;
		}else if(contGris>contNegro && contGris>contBlanco && contGris > contRojo && contGris>contAzul){
			colorMasCant=5003;
		}else{
			colorMasCant=5004;
		}


		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoColumnasTexto,"Id",anchoColumnasTexto,"Nombre",anchoColumnasNumero,
		"Tipo",anchoColumnasTexto,"Color",anchoColumnasTexto,"Edad",
		anchoColumnasTexto,"Estado Vacunaci�n",anchoColumnasTexto,"Due�o",anchoColumnasTexto,"Sexo");
		for(i=0;i<TAM;i++){

			if(personas[i].isEmpty==0 && personas[i].idColor==colorMasCant){

				for(j=0;j<tamTipo;j++){
					if(personas[i].idTipo==tipo[j].id){
									break;
						}
				}

				for(x=0;x<tamColor;x++){
					if(personas[i].idColor==color[x].id){

						break;
					}
				}

				for(y=0;y<tamCliente;y++){
					if(personas[i].idCliente==cliente[y].id){

							break;
					}
				}

				printf("\n----------------------------------------------------------------------------------------------------\n");
				printf("|%*d|%*s|%*s|%*s|%*d|%*c|%*s|%*s|\n",anchoColumnasTexto,personas[i].id,anchoColumnasNumero,personas[i].nombre
						,anchoColumnasNumero,tipo[j].descripcion,anchoColumnasTexto,color[x].nombreColor
				,anchoColumnasTexto,personas[i].edad,anchoColumnasTexto,personas[i].vacunado,
				anchoColumnasTexto,cliente[y].nombre,anchoColumnasTexto,cliente[y].sexo);
			}
		}
}
void listadosExtra(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente){

	int retorno;
	int menu;

	do{
		retorno=utn_getNumero(&menu,"Que desea listar?\n1.Seleccionar un color y mostrar las mascotas de ese color\n"
			"2.Mostrar el promedio de mascotas vacunadas\n3.Mostrar las mascotas de menor edad\n4.Mascotas Listadas por tipo\n"
			"5.Elegir un color y un tipo y mostrar la cantidad de mascotas\n6.Mostrar el color con mas cantidad de mascotas\n"
			"7.Salir","Error",1,7,5);
		if(retorno==0){
			switch(menu){
			case 1:
				listarColorSeleccionado(personas,TAM,tipo,tamTipo,color,tamColor,cliente,tamCliente);
				break;

			case 2:
				listarPorcentajeVacunados(personas,TAM);
				break;

			case 3:
				listarMenorEdad(personas,TAM,tipo,tamTipo,color,tamColor,cliente,tamCliente);
				break;
			case 4:
				listarPorTipo(personas,TAM,tipo,tamTipo,color,tamColor,cliente,tamCliente);
				break;
			case 5:
				listarPorColorYTipo(personas,TAM,tipo,tamTipo,color,tamColor,cliente,tamCliente);
				break;
			case 6:
				listarColorMasCant(personas,TAM,tipo,tamTipo,color,tamColor,cliente,tamCliente);
				break;
			case 7:
				printf("Volviendo al menu anterior\n");
				break;
			}
		}
	}while(menu !=7);
}

