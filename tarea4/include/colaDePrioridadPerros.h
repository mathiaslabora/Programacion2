/*
Módulo de definición de 'TColaDePrioridadPerros'.

Los elementos de tipo 'TColaDePrioridadPerros' son colas de prioridad cuyos
elementos son de tipo 'TPerro' y cuya prioridad se define por la vitalidad del perro.

Los perros son únicos, por lo que no es posible que haya dos perros con el
mismo id.
Se asume que los ids de los perros están acotados entre 1 y N, siendo N el
tamaño de la cola.

El criterio para establecer la prioridad entre perros es, de manera
predeterminada, que un perro es prioritario ante otro si su vitalidad es menor que la vitalidad del otro perro.
Este criterio se puede modificar, haciendo que el perro prioritario sea el de mayor vitalidad.

Si la 'TColaDePrioridadPerros' no es vacía hay un perro considerado el
prioritaria, según el criterio de prioridad. Si hay más de un perro con la
misma vitalidad, cualquiera de ellos es el prioritario.


Laboratorio de Programación 2.
InCo-FIng-UDELAR
*/

#ifndef _CP_H
#define _CP_H

#include "utils.h"
#include "perro.h"

//   Representación de 'TColaDePrioridadPerros'
//   Se debe definir en colaDePrioridadPerros.cpp
//   struct _rep_colaDePrioridadPerros;
//   Declaración del tipo 'TColaDePrioridadPerros'
typedef struct rep_colaDePrioridadPerros *TColaDePrioridadPerros;
 
//   Devuelve una 'TColaDePrioridadPerros' vacía (sin elementos) que puede
//   contener hasta N perros.
//   La prioridad entre dos perros se define por el que tenga menor vitalidad
TColaDePrioridadPerros crearTColaDePrioridadPerros(nat N);

//   Devuelve 'true' si y solo si en 'cp' no hay elementos.
bool estaVaciaTColaDePrioridadPerros(TColaDePrioridadPerros cp);

//   Inserta 'perro' en 'cp'.
//   PRE: !estaEnCP(perro, cp)
//   PRE: 1 <= idPerro <= N, siendo 'N' el parámetro pasado en crearCP.
void insertarTColaDePrioridadPerros(TColaDePrioridadPerros &cp, TPerro perro);

//   Devuelve 'true' si y solo si el perro con identificador 'id' es un elemento de 'cp'.
bool estaTColaDePrioridadPerros(TColaDePrioridadPerros cp, int id);

//   Libera la memoria asignada a 'cp' y a cada uno de sus elementos.
//   Es decir, libera la memoria asociada a todos los perros que estén en la cola.
void liberarTColaDePrioridadPerros(TColaDePrioridadPerros &cp);

//   Devuelve el valor de prioridad (la vitalidad) asociado al perro con identificador 'id'.
//   Precondición: estaEnCp(id, cp).
nat prioridadTColaDePrioridadPerros(TColaDePrioridadPerros cp, int id);

//   Devuelve el perro prioritario de 'cp'.
//   PRE: !estaVaciaCP(cp).
TPerro prioritarioTColaDePrioridadPerros(TColaDePrioridadPerros cp);

//   Elimina de 'cp' el perro prioritario y libera la memoria asociada.
//   Si estaVacioCP(cp) la operación no tiene efecto.
void eliminarPrioritarioTColaDePrioridadPerros(TColaDePrioridadPerros &cp);

//   Modifica el criterio de prioridad: si el prioritario era el perro de menor vitalidad,
//   entonces pasa a ser el perro de mayor prioridad, y viceversa.
//   Debe modificar la cola de forma de que se respete el nuevo criterio de prioridad.
void invertirPrioridadTColaDePrioridadPerros(TColaDePrioridadPerros &cp);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en colaDePrioridadPerros.cpp 

#endif
 