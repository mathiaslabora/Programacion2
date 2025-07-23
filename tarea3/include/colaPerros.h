/*
  Módulo de definición de 'TColaPerros'.

  Un elemento de tipo TColaPerros almacena una coleccion de
  elementos de tipo TPerro y ofrece operaciones del TAD Cola.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/
#ifndef COLAPERROS_H
#define COLAPERROS_H

#include "perro.h"
 
// Define el tipo TColaPerros como un puntero a rep_colaPerros
typedef struct rep_colaPerros *TColaPerros;
 
// Función para crear un elemento de tipo TColaPerros vacío.
TColaPerros crearTColaPerros();

// Función que libera la memoria asignada para la cola de perros.
void liberarTColaPerros(TColaPerros &colaPerros);

// Agrega un perro a la cola de perros.
void encolarTColaPerros(TColaPerros &colaPerros, TPerro perro);

// Imprime la cola de perros con el siguiente formato: 
//   Cola de Perros:
//   <imprimir imprimirTPerro en cada perro>
// El orden de impresión es el que resultaría de desencolar
// sucesivamente los perros e imprimirlos (orden de llegada).
void imprimirTColaPerros(TColaPerros colaPerros);

// Devuelve la cantidad de perros en la cola de perros.
nat cantidadTColaPerros(TColaPerros colaPerros);

// Retorna el perro más antiguo de la cola. 
// PRE: cantidadTColaPerros(colaPerros) > 0
TPerro frenteTColaPerros(TColaPerros colaPerros);

// Remueve el perro más antiguo de la cola.
// PRE: cantidadTColaPerros(colaPerros) > 0
void desencolarTColaPerros(TColaPerros &colaPerros);
 
// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en colaPerros.cpp 


#endif // COLAPERROS_H  
 