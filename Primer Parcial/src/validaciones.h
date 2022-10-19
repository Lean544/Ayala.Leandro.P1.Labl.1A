/*
 * validaciones.h
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

//Se usa para conseguir un numero
int getInt(int* pResultado);

//Se usa para conseguir un numero flotante
int getFloat(int* pResultado);

//Se usa para conseguir una cadena de caracteres
int getCadena(char pResultado[]);

//Se usa para conseguir un codigo alfanumerico
int getCodigo(char pResultado[]);

//Se encarga de recibir los datos ingresados por teclado cuidando de que
//no se pase del limite
int myGets(char* cadena,int largo);

/**
 * Recibe una cadena de caracteres y comprueba que sea numerica
 * @param cadena-> cadena a comprobar
 */
int esNumerica(char*cadena);


/**
 * Recibe una cadena de caracteres y comprueba que sea alfabetica
 * @param cadena-> cadena a comprobar
 */
int esAlfabetica(char cadena[]);

//Recibe una cadena de caracteres alfanumerica
/**
 * Recibe una cadena de caracteres y comprueba que sea alfabetica
 * @param cadena-> cadena a comprobar
 */
int esCodigo(char*cadena);

/**
 * Se utiliza para conseguir un numero, devuelve -1 si falla y 0 si sale bien
 * @param pResultado-> variable donde se va a escribir el numero
 * @param mensaje-> mensaje a mostrar
 * @param mensajeError-> mensaje a mostrar en caso de error
 * @param minimo-> numero minimo que se puede ingresar
 * @param maximo-> numero maximo que se puede ingresar
 * @param reintentos->numero de reintentos (se va restando a medida que se falla)
 */
int utn_getNumero(int* pResultado, char* mensaje,
char* mensajeError,int minimo,int maximo, int reintentos);

/**
 * Se utiliza para conseguir un numero flotante, devuelve -1 si falla y 0 si sale bien
 * @param pResultado-> variable donde se va a escribir el numero
 * @param mensaje-> mensaje a mostrar
 * @param mensajeError-> mensaje a mostrar en caso de error
 * @param minimo-> numero minimo que se puede ingresar
 * @param maximo-> numero maximo que se puede ingresar
 * @param reintentos->numero de reintentos (se va restando a medida que se falla)
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje,
char* mensajeError,float minimo,float maximo, int reintentos);

/**
 * Se utiliza para conseguir un caracter, devuelve -1 si falla y 0 si sale bien
 * @param pResultado-> variable donde se va a escribir el caracter
 * @param mensaje-> mensaje a mostrar
 * @param mensajeError-> mensaje a mostrar en caso de error
 * @param minimo-> letra minima que se puede ingresar
 * @param maximo-> letra maxima que se puede ingresar
 * @param reintentos->numero de reintentos (se va restando a medida que se falla)
 */
int utn_getCaracter(char* pResultado, char* mensaje,
char* mensajeError,char minimo,char maximo, int reintentos);

/**
 * Se utiliza para conseguir una cadena de caracteres, devuelve -1 si falla y 0 si sale bien
 * @param pResultado-> array donde se pondra la cadena
 * @param mensaje-> mensaje a mostrar
 * @param mensajeError-> mensaje a mostrar en caso de error
 * @param largo-> el maximo de caracteres que puede tener la cadena
 * @param reintentos->numero de reintentos (se va restando a medida que se falla)
 */
int utn_getCadena(char pResultado[],char* mensaje,char* mensajeError
,int largo,int reintentos);

/**
 * Se utiliza para conseguir un codigo alfanumerico, devuelve -1 si falla y 0 si sale bien
 * @param pResultado-> array donde se pondra la cadena
 * @param mensaje-> mensaje a mostrar
 * @param mensajeError-> mensaje a mostrar en caso de error
 * @param largo-> el maximo de caracteres que puede tener la cadena
 * @param reintentos->numero de reintentos (se va restando a medida que se falla)
 */
int utn_getCodigo(char pResultado[],char* mensaje,
char* mensajeError,int largo,int reintentos);

/**
 * Se utiliza para tomar los datos usando todas las funciones anteriores, devuelve -1 si falla y 0 si sale bien

 * @param id->numero de id (autoIncremental pero se puede cambiar para adaptarse a la situacion)
 */

#endif /* VALIDACIONES_H_ */
