/*
 * calculos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "cliente.h"
/**
 * Inicializa los campos isEmpty de las posiciones del array en 1
 *
 * @param personas-> Primer array a "iniciar"
 * @param len-> Largo de los dos Arrays (en este caso)
 * @param trabajos-> Segundo array a "iniciar"
 * @return
 */
int inicializar (eMascota personas[],int len,eTrabajo trabajos[]);

/**
 * HardCodea uno o mas arrays dependiendo de las necesidades del programa
 *
 * @param cosas-> Primer Array a cargar(Tipos)
 * @param cosasC-> Segundo Array a cargar(Colores)
 * @param cosasS-> Tercer Array a cargar(Servicios)
 * @param cosasCl->Cuarto array a cargar (clientes)
 * @param tamUno-> Tama�o del array de Tipos
 * @param tamDos-> Tama�o del array de Colores
 * @param tamTres->Tama�o del array de Servicios
 * @return
 */
/**
 *
 * @param cosas-> Primer Array a cargar(Tipos)
 * @param cosasC-> Segundo Array a cargar(Colores)
 * @param cosasS-> Tercer Array a cargar(Servicios)
 * @param cosasCl->Cuarto array a cargar (clientes)
 * @param trabajo->Quinto array a cargar(trabajos)
 * @param mascota->Sexto array a cargar (mascotas)
 * @param tamUno-> Tama�o del array de Tipos
 * @param tamDos-> Tama�o del array de Colores
 * @param tamTres->Tama�o del array de Servicios
 * @param tamCuatro->Tama�o del array de clientes
 * @param tamCinco->Tama�o del Array de mascotas y trabajos
 * @return
 */
int cargaForzada(eTipo cosas[],eColor cosasC[],eServicio cosasS[],eCliente cosasCl[],eTrabajo trabajo[],eMascota mascota[],int tamUno,int tamDos,int tamTres,int tamCuatro,int tamCinco);
/**
 * Busca la primer posicion libre del array de mascotas,cuando la encuentra corta y retorna 1
 *
 * @param personas->Array en el que se va a buscar
 * @param len-> Largo del Array
 * @param libre-> Variable en la que se retorna la posicion vacia
 * @return
 */
int buscarLibre(eMascota personas[],int len,int* libre);

/**
 * Busca la primer posicion libre del array de trabajo,cuando la encuentra corta y retorna 1
 *
 * @param trabajo->Array en el que se va a buscar
 * @param len-> Largo del Array
 * @param libre-> Variable en la que se retorna la posicion vacia
 * @return
 */
int buscarTrabajoLibre(eTrabajo trabajo[],int len,int* libre);

/**
 * Busca en el array de mascotas el id ingresado, si lo encuentra retorna 1 y su posicion
 *
 * @param personas->Array en el que se va a buscar
 * @param TAM-> Largo del Array
 * @param buscar->Id que se va a buscar en el array
 * @param retornoPos->Variable en la que se retorna la posicion si se encuentra
 * @return
 */
int buscarPorId(eMascota personas[],int TAM,int buscar,int* retornoPos);
/**
 * Se usa para cargar una fecha (a�o,mes y dia) haciendo las comprobaciones
 *  para que no se exceda de los dias del mes seleccionado usando flags, si todo sale bien
 *  retorna 1
 *
 * @param trabajo-> Array en el que se carga la fecha
 * @param pos-> Posicion en la que se carga
 * @return
 */
int cargarFecha(eTrabajo* trabajo,int pos);

/**
 *Toma los datos correspondientes de lo que se necesite dependiendo del trabajo, retorna 1 si todo sale bien
 *
 * @param personas-> Array en el que se va a cargar los datos
 * @param ids-> Contador de id�s autoincrementales
 * @param tipo-> Array de tipos para comprobar que el tipo de mascota ingresado sea correcto
 * @param color-> Array de colores para comprobar que el tipo de mascota ingresado sea correcto
 * @param cliente->Array de clientes para comprobar que se cargue bien el id del cliente
 * @param TAM -> Tama�o del array de personas
 * @param tamTipo -> Tama�o del array de tipos
 * @param tamColor -> Tama�o del array de colores
 * @param tamCliente->Tama�o del array de clientes
 * @return
 */

int cargar(eMascota personas[],int* ids,eTipo tipo[],eColor color[],eCliente cliente[],int TAM,int tamTipo,int tamColor,int tamCliente);
/**
 * Utiliza buscarPorId para poder localizar la posicion a modificar en el array de personas
 * (en este caso solo permite modificar el tipo y el estado de vacunacion),retorna 1 si todo sale bien
 *
 * @param personas-> Array que se modificara la posicion(si se encuentra)
 * @param TAM-> Tama�o del array
 * @param tipo-> Array de tipos para verificar que la modificacion este dentro de los parametros
 * @param tamTipos-> Tama�o del array de tipos
 * @return
 */
int modificar(eMascota personas[],int TAM,eTipo tipo[],int tamTipos);

/**
 * Utiliza buscarPorId para poder localizar la posicion a dar de baja en el array de personas
 * cambiando la variable isEmpty de 0 a 1, retorna 1 si todo sale bien
 *
 * @param personas-> Array en el que se dara de baja la posicion (si se encuentra)
 * @param TAM-> Tama�o del array
 * @return
 */
int baja(eMascota personas[],int TAM);

/**
 * Ordena el array de personas segun el criterio del trabajo
 * (en este caso lo hace por tipo y nombre)
 *
 * @param personas-> Array a ordenar
 * @param TAM-> Tama�o del Array
 * @return
 */
int ordenar(eMascota personas[],int TAM);

/**
 * Utiliza buscarTrabajoLibre para encontrar una posicion libre y luego lista las mascotas ingresadas
 * para luego tomar los datos
 *
 * @param sujetos-> Array de mascotas para listarlo
 * @param tamSujetos-> Tama�o del array de mascotas
 * @param trabajo-> Puntero al array de trabajos a cargar
 * @param tamTrabajo-> Tama�o del array de trabajos
 * @param servicios-> Array de servicios para comprobar que el servicio ingresado sea el correcto
 * @param tamServicios-> Tama�o del array de servicios
 * @param color-> Array de colores para el listado de mascotas
 * @param tamColor-> Tama�o del array de colores
 * @param tipo-> Array de Tipos para el listado de mascotas
 * @param tamTipo-> Tama�o del array de Tipos
 * @param clientes-> Array de clientes para poder listar las mascotas
 * @param tamClientes-> Tama�o del array de clientes
 * @param contIdTrabajo-> Contador del id de los Trabajos (autoIncremental)
 * @return
 */
int ingresarTrabajo(eMascota sujetos[],int tamSujetos,eTrabajo* trabajo,int tamTrabajo,eServicio servicios[],int tamServicios,
		eColor color[],int tamColor,eTipo tipo[],int tamTipo,eCliente clientes[],int tamClientes,int* contIdTrabajo);

#endif /* CALCULOS_H_ */
