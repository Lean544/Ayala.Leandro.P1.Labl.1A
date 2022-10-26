/*
 * calculos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: ayala
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

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
 * @param tamUno-> Tamaño del array de Tipos
 * @param tamDos-> Tamaño del array de Colores
 * @param tamTres->Tamaño del array de Servicios
 * @return
 */
int cargaForzada(eTipo cosas[],eColor cosasC[],eServicio cosasS[],int tamUno,int tamDos,int tamTres);

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
 * Se usa para cargar una fecha (año,mes y dia) haciendo las comprobaciones
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
 * @param ids-> Contador de id´s autoincrementales
 * @param tipo-> Array de tipos para comprobar que el tipo de mascota ingresado sea correcto
 * @param color-> Array de colores para comprobar que el tipo de mascota ingresado sea correcto
 * @param TAM -> Tamaño del array de personas
 * @param tamTipo -> Tamaño del array de tipos
 * @param tamColor -> Tamaño del array de colores
 * @return
 */
int cargar(eMascota personas[],int* ids,eTipo tipo[],eColor color[],int TAM,int tamTipo,int tamColor);

/**
 * Utiliza buscarPorId para poder localizar la posicion a modificar en el array de personas
 * (en este caso solo permite modificar el tipo y el estado de vacunacion),retorna 1 si todo sale bien
 *
 * @param personas-> Array que se modificara la posicion(si se encuentra)
 * @param TAM-> Tamaño del array
 * @param tipo-> Array de tipos para verificar que la modificacion este dentro de los parametros
 * @param tamTipos-> Tamaño del array de tipos
 * @return
 */
int modificar(eMascota personas[],int TAM,eTipo tipo[],int tamTipos);

/**
 * Utiliza buscarPorId para poder localizar la posicion a dar de baja en el array de personas
 * cambiando la variable isEmpty de 0 a 1, retorna 1 si todo sale bien
 *
 * @param personas-> Array en el que se dara de baja la posicion (si se encuentra)
 * @param TAM-> Tamaño del array
 * @return
 */
int baja(eMascota personas[],int TAM);

/**
 * Ordena el array de personas segun el criterio del trabajo
 * (en este caso lo hace por tipo y nombre)
 *
 * @param personas-> Array a ordenar
 * @param TAM-> Tamaño del Array
 * @return
 */
int ordenar(eMascota personas[],int TAM);

/**
 * Utiliza ordenar segun los criterios del trabajo y lista el array de personas
 *
 * @param personas-> Array a listar
 * @param TAM-> Tamaño del Array
 * @param tipo-> Array de tipos (se utiliza para comprobar el idTipo del array de personas para poder mostrar
 * la descripcion a la hora de listar)
 * @param tamTipo-> Tamaño del array de Tipos
 * @param color->Array de tipos (se utiliza para comprobar el idColor del array de personas para poder mostrar
 * la descripcion a la hora de listar)
 * @param tamColor-> Tamaño del array de Colores
 */
void listarMascotas(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor);
/**
 * Lista el Array de tipos
 *
 * @param tipo-> Array a listar(Tipos)
 * @param tamTipo-> Tamaño del array de Tipos
 */
void listarTipos (eTipo tipo[],int tamTipo);

/**
 * Lista el Array de Colores
 *
 * @param tipo-> Array a listar(Colores)
 * @param tamColor-> Tamaño del array de Colores
 */
void listarColores(eColor color[],int tamColor);

/**
 * Lista el Array de Servicios
 *
 * @param tipo-> Array a listar(Servicios)
 * @param tamServicio-> Tamaño del array de Servicios
 */
void listarServicios(eServicio servicio[],int tamServicio);

/**
 * Utiliza buscarTrabajoLibre para encontrar una posicion libre y luego lista las mascotas ingresadas
 * para luego tomar los datos
 *
 * @param sujetos-> Array de mascotas para listarlo
 * @param tamSujetos-> Tamaño del array de mascotas
 * @param trabajo-> Puntero al array de trabajos a cargar
 * @param tamTrabajo-> Tamaño del array de trabajos
 * @param servicios-> Array de servicios para comprobar que el servicio ingresado sea el correcto
 * @param tamServicios-> Tamaño del array de servicios
 * @param color-> Array de colores para el listado de mascotas
 * @param tamColor-> Tamaño del array de colores
 * @param tipo-> Array de Tipos para el listado de mascotas
 * @param tamTipo-> Tamaño del array de Tipos
 * @param contIdTrabajo-> Contador del id de los Trabajos (autoIncremental)
 * @return
 */
int ingresarTrabajo(eMascota sujetos[],int tamSujetos,eTrabajo* trabajo,int tamTrabajo,eServicio servicios[],int tamServicios,
eColor color[],int tamColor,eTipo tipo[],int tamTipo,int* contIdTrabajo);

/**
 * Lista los trabajos ingresados hasta el momento
 *
 * @param trabajo-> Puntero al array de Trabajos
 * @param TAM-> Tamaño del array de Trabajos y del de mascotas
 * @param mascota-> Array de mascotas mostrar el nombre en el listado
 * @param servicio-> Array de servicios Para mostrar el servicio a realizarle en la lista
 * @param tamServicio-> Tamaño del array de servicios
 */
void listarTrabajos(eTrabajo* trabajo,int TAM,eMascota mascota[],eServicio servicio[],int tamServicio);
#endif /* CALCULOS_H_ */
