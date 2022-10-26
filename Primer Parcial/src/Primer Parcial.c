/*
 ============================================================================
 Name        : Primer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "calculos.h"
#define TAM 300

int main(void) {
	setbuf(stdout, NULL);
	int retorno;
	int confirmacion;
	char menu;
	int retornoUno;
	int idMascotas=0;
	int idTrabajos=0;

	eMascota mascotas [TAM];
	eTipo tipos [5];
	eColor colores[5];
	eServicio servicios[3];
	eTrabajo trabajos[TAM];
	eTrabajo * pTrabajos;
	pTrabajos=trabajos;

	if(inicializar(mascotas,TAM,trabajos)==1 && cargaForzada(tipos,colores,servicios,5,5,3)==1){
		do
			{
				retorno = utn_getCaracter(&menu,"Escriba la Respuesta en Mayuscula Por favor\n\nA.Alta de mascota\n"
				"B.Modificar Mascota\nC.Baja Mascota\nD.Listar Mascotas\nE.Listar Tipos\nF.Listar Colores\nG.Listar Servicios\n"
				"H.Alta Trabajo\nI.Listar Trabajos\nJ.Salir","Error",'A','J',2);
				if(retorno == 0){
					switch(menu){

						case 'A':
							if(cargar(mascotas,&idMascotas,tipos,colores,TAM,5,5)==1){
								retornoUno=1;
							}

						break;

						case 'B':
							if(retornoUno==1){
								if(modificar(mascotas,TAM,tipos,5)==1){
									printf("Modificacion Exitosa!\n");
								}
							}else{
								printf("Error hay que ingresar mascotas Primero\n");
							}
						break;

						case 'C':
							if(retornoUno==1){
									if(baja(mascotas,TAM)==1){
										printf("Baja exitosa!\n");
									}
							}else{
								printf("Error hay que ingresar mascotas Primero\n");
							}
						break;

						case 'D':
							if(retornoUno==1){
								listarMascotas(mascotas,TAM,tipos,5,colores,5);
							}else{
								printf("Error hay que ingresar mascotas Primero\n");
							}
						break;

						case 'E':
							listarTipos(tipos,5);

						break;
						case 'F':
							listarColores(colores,5);
						break;
						case 'G':
							listarServicios(servicios,3);
						break;

						case 'H':
							if(retornoUno==1){
								if(ingresarTrabajo(mascotas,TAM,pTrabajos,TAM,servicios,3,colores,5,tipos,5,&idTrabajos)==1){
									printf("Turno Reservado!\n");
								}
							}else{
								printf("Error hay que ingresar mascotas Primero\n");
							}

						break;

						case 'I':
							//void listarTrabajos(eTrabajo* trabajo,int TAM,eMascota mascota[],eServicio servicio[],int tamServicio)
							listarTrabajos(pTrabajos,TAM,mascotas,servicios,3);
						break;

						case 'J':
							utn_getNumero(&confirmacion,"Esta seguro que desea salir?\n1.Si\n2.No\n","Error",1,2,2);
						break;
					}
			}

		}while(confirmacion !=1);
	}else{
		printf("Error al inicializar");
	}
}


