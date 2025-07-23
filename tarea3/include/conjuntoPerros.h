/*
  Módulo de definición de 'TConjuntoPerros'.

  Un elemento de tipo TConjuntoPerros es un conjunto acotado que almacena ids de perros.

  El conjunto es acotado, y además, la cantidad máxima de elementos define el rango de identificadores que almacena
  Es decir, los identificadores almacenados por el conjunto
  cumplen 0 <= id < cantMax
  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef CONJUNTOPERROS_H
#define CONJUNTOPERROS_H

#include "utils.h"

// Definición de tipo TConjuntoPerros como un puntero a rep_conjuntoperros
typedef struct rep_conjuntoperros* TConjuntoPerros;

// Función para crear un nuevo conjunto de perros.
// Devuelve un conjunto vacío.
TConjuntoPerros crearTConjuntoPerros(int cantMax);

// Procedimiento para insertar el identificador "id" en el conjunto de perros "c".
// Si "id" no pertenece al rango válido de ids del conjunto "c" la función no hace nada.
// Si "id" ya pertenece al conjunto, la función no hace nada.
void insertarTConjuntoPerros(TConjuntoPerros &c, int id); 

// Procedimiento para imprimir el conjunto de perros.
// Imprime los ids de los perros del conjunto ordenado de menor a mayor.
// Deben imprimirse solamente los elementos, separados por un espacio 
// (sin espacio después del último), con un salto de línea al final.
// Ejemplo: si el conjunto "c" tiene los elementos 7, 42, 29 y 75 la impresión debe ser "7 29 42 75" 
// y finalmente un salto de línea.
void imprimirTConjuntoPerros(TConjuntoPerros c);

// Procedimiento para liberar la memoria asignada a un conjunto de perros.
// Luego de la ejecución deja 'c' apuntando a NULL;
void liberarTConjuntoPerros(TConjuntoPerros &c);

// Función para determinar si un conjunto de perros es vacío
// Devuelve true si el conjunto es vacío, false en otro caso
bool esVacioTConjuntoPerros(TConjuntoPerros c);

// Función que retorna la cantidad de elementos del conjunto de perros "c".
int cardinalTConjuntoPerros(TConjuntoPerros c);

// Función que retorna la cantidad máxima de elementos del conjunto de perros "c".
int cantMaxTConjuntoPerros(TConjuntoPerros c);

// Función para determinar si el identificador "id" pertenece al conjunto "c"
// Devuelve true si pertenece, false en otro caso
bool perteneceTConjuntoPerros(TConjuntoPerros c, int id);

// Procedimiento para borrar al "id" del conjunto de perros "c"
// Si "id" no pertenece al conjunto "c" o al rango válido, la función no hace nada
void borrarDeTConjuntoPerros(TConjuntoPerros &c, int id);

// Función que retorna la unión entre los conjuntos de perros "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
TConjuntoPerros unionTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2);

// Función que retorna la intersección entre los conjuntos de perros "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
TConjuntoPerros interseccionTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2);

// Función que retorna la diferencia entre los conjuntos de perros "c1" y "c2". (c1 - c2)
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
TConjuntoPerros diferenciaTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en conjuntoPerros.cpp 

#endif  // CONJUNTOPERROS_H
