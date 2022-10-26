/*
 * listar.h
 *
 *  Created on: 26 oct. 2022
 *      Author: ayala
 */

#ifndef LISTAR_H_
#define LISTAR_H_
/**
 * Utiliza ordenar segun los criterios del trabajo y lista el array de personas
 *
 * @param personas-> Array a listar
 * @param TAM-> Tama�o del Array
 * @param tipo-> Array de tipos (se utiliza para comprobar el idTipo del array de personas para poder mostrar
 * la descripcion a la hora de listar)
 * @param tamTipo-> Tama�o del array de Tipos
 * @param color->Array de tipos (se utiliza para comprobar el idColor del array de personas para poder mostrar
 * la descripcion a la hora de listar)
 * @param tamColor-> Tama�o del array de Colores
 * @param cliente->Array de clientes utilizado para mostrar el nombre del due�o en el listado
 * @param tamCliente->Tama�o del array de clientes
 */
void listarMascotas(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);
/**
 * Lista el Array de tipos
 *
 * @param tipo-> Array a listar(Tipos)
 * @param tamTipo-> Tama�o del array de Tipos
 */
void listarTipos (eTipo tipo[],int tamTipo);

/**
 * Lista el Array de Colores
 *
 * @param tipo-> Array a listar(Colores)
 * @param tamColor-> Tama�o del array de Colores
 */
void listarColores(eColor color[],int tamColor);

/**
 * Lista el Array de Clientes
 *
 * @param cliente-> Array a listar(Clientes)
 * @param tamCliente-> Tama�o del array de Clientes
 */
void listarClientes(eCliente cliente[],int tamCliente);
/**
 * Lista el Array de Servicios
 *
 * @param tipo-> Array a listar(Servicios)
 * @param tamServicio-> Tama�o del array de Servicios
 */
void listarServicios(eServicio servicio[],int tamServicio);

/**
 * Lista los trabajos ingresados hasta el momento
 *
 * @param trabajo-> Puntero al array de Trabajos
 * @param TAM-> Tama�o del array de Trabajos y del de mascotas
 * @param mascota-> Array de mascotas mostrar el nombre en el listado
 * @param servicio-> Array de servicios Para mostrar el servicio a realizarle en la lista
 * @param tamServicio-> Tama�o del array de servicios
 */
void listarTrabajos(eTrabajo* trabajo,int TAM,eMascota mascota[],eServicio servicio[],int tamServicio);

/**
 * Lista Las mascotas del color seleccionado
 * @param personas->Array a listar
 * @param TAM->Tama�o del array
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listarColorSeleccionado(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);
/**
 * Lista el porcentaje de mascotas vacunadas
 * @param personas->Array para calcular el porcentaje
 * @param TAM->Tama�o del array
 */
void listarPorcentajeVacunados(eMascota personas[],int TAM);
/**
 * Lista a la/las mascotas de menor edad
 * @param personas->Array para calcular y mostrar
 * @param TAM->Tama�o del array de mascotas
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listarMenorEdad(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);

/**
 * Lista por tipos de mascota
 * @param personas->Array para calcular y mostrar
 * @param TAM->Tama�o del array
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listarPorTipo(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);
/**Lista por un color y un tipo de mascota seleccionado por el usuario
 *
 * @param personas->Array para calcular y mostrar
 * @param TAM->Tama�o del array
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listarPorColorYTipo(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);
/**Lista a las mascotas del color que mas mascotas tiene
 *
 * @param personas->Array para calcular y mostrar
 * @param TAM->Tama�o del array
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listarColorMasCant(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);

/**
 * Submenu para acceder a los otros listados
 * @param personas->Array para calcular y mostrar
 * @param TAM->Tama�o del array
 * @param tipo->Array de tipo para mostrar el tipo de mascota en la lista
 * @param tamTipo->Tama�o del array de Tipos
 * @param color->Array de colores para mostrar el color de mascota en la lista
 * @param tamColor->Tama�o del array de Colores
 * @param cliente->Array de colores para mostrar el nombre del cliente en la lista
 * @param tamCliente->Tama�o del array de clientes
 */
void listadosExtra(eMascota personas[],int TAM,eTipo tipo[],int tamTipo,eColor color[],int tamColor,eCliente cliente[],int tamCliente);
#endif /* LISTAR_H_ */