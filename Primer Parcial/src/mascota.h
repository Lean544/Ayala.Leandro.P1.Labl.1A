/*
 * mascota.h
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int idCliente;
	int edad;
	char vacunado;
	int isEmpty;
}eMascota;

#endif /* MASCOTA_H_ */
