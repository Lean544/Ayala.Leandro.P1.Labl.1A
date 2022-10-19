/*
 * calculos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int inicializar (eMascota personas[],int len);

int cargaForzada(eTipo cosas[],eColor cosasC[],eServicio cosasS[],int tamUno,int tamDos,int tamTres);

int buscarLibre(eMascota personas[],int len,int* libre);

int buscarPorId(eMascota personas[],int TAM,int buscar,int* retornoPos);

int cargar(eMascota personas[],int* ids,eTipo tipo[],eColor color[],int TAM,int tamTipo,int tamColor);

int modificar(eMascota personas[],int TAM,eTipo tipo[],int tamTipos);

int baja(eMascota personas[],int TAM);

int ordenar(eMascota personas[],int TAM);

void listarMascotas(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor);
#endif /* CALCULOS_H_ */
