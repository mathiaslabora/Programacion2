/*
Módulo de definición de 'TTablaFichaVacunacion'.

Laboratorio de Programación 2.
InCo-FIng-UDELAR
*/
#ifndef TABLA_FICHA_VACUNACION_H
#define TABLA_FICHA_VACUNACION_H

#include "utils.h"
#include "agFichaVacunacion.h"

//  Definición de tipo TTablaFichaVacunacion como un puntero a rep_tablaFichaVacunacion
typedef struct rep_tablaFichaVacunacion *TTablaFichaVacunacion;

//  Función para crear una nueva Tabla vacía de fichas de vacunación, 
//  en la que se estima que se insertarán max entradas.
TTablaFichaVacunacion crearTTablaFichaVacunacion(int max);

//  Función para liberar la memoria asignada a una TTablaFichaVacunacion.
void liberarTTablaFichaVacunacion(TTablaFichaVacunacion &tabla);

//  Función para insertar una asociación (idPerro, ficha) en la tabla de fichas de vacunación.
//  La función asocia el id de un perro con su ficha de vacunación.
//  PRE: !perteneceTTablaFichaVacunacion(tabla, ficha)
void insertarTTablaFichaVacunacion(TTablaFichaVacunacion &tabla, int idPerro, TAGFichaVacunacion ficha);

//  Función para imprimir todas las asociaciones de la TTablaFichaVacunacion "tabla".
void imprimirTTablaFichaVacunacion(TTablaFichaVacunacion tabla);

//  Función para verificar si en una TTablaFichaVacunacion "tabla" 
//  existe una asociación que representa la ficha de vacunación del perro de id idPerro.
//  Devuelve true si existe, false en caso contrario.
bool perteneceTTablaFichaVacunacion(TTablaFichaVacunacion tabla, int idPerro);

//  Función para obtener la ficha de vacunación asociada 
//  al perro de id idPerro de la TTablaFichaVacunacion "tabla".
//  PRE: perteneceTTablaFichaVacunacion(tabla, idPerro)
TAGFichaVacunacion obtenerFichaTTablaFichaVacunacion(TTablaFichaVacunacion tabla, int idPerro);

//  Función para eliminar a la asociación que de idPerro con su respectiva
//  ficha de vacunación en la TTablaFichaVacunacion "tabla".
//  También libera la memoria asociada a la ficha de vacunación del perro.
//  PRE: perteneceTTablaFichaVacunacion(tabla, ficha)
void eliminarDeTTablaFichaVacunacion(TTablaFichaVacunacion &tabla, int idPerro);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en tablaFichaVacunacion.cpp 

#endif  // TABLA_FICHA_VACUNACION_H