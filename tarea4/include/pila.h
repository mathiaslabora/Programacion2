/*
  Módulo de definición de 'TPila'.

  Un elemento de tipo TPila almacena una coleccion de elementos de tipo int 
  y ofrece operaciones del TAD Pila.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/
#ifndef PILA_H
#define PILA_H
 
#include "utils.h"

// Define el tipo TPila como un puntero a rep_pila
typedef struct rep_pila *TPila;
 
// Función para crear un elemento de tipo TPila vacío.
TPila crearTPila();

// Función que libera la memoria asignada para la pila.
// Al finalizar la ejecución deja el parámetro 'pila' apuntando a NULL.
void liberarTPila(TPila &pila);

// Agrega un elemento en la pila.
void apilarTPila(TPila &pila, int elem);

// Imprime la pila con el siguiente formato: 
//   Pila: <elem1> <elem2> <elem3> ... <elemn>
// El orden de los elementos es el orden inverso que se obtendría al invocar 
// sucesivamente la función 'desapilar' (elem1 es el primero apilado y elemn es el último apilado)
void imprimirTPila(TPila pila);

// Devuelve la cantidad de elementos en la pila.
nat cantidadTPila(TPila pila);

// Retorna el elemento más reciente de la pila. 
// PRE: cantidadTPila(pila) > 0
int cimaTPila(TPila pila); 

// Remueve el elemento más reciente de la pila.
// PRE: cantidadTPila(pila) > 
void desapilarTPila(TPila &pila);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en pila.cpp 

#endif // PILA_H  
 