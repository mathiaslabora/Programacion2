/*
  Módulo de definición de 'TAGFichaVacunacion'.

  Un elemento de tipo TAGFichaVacunacion es un árbol general que permite representar el esquema de vacunación
  de los perros. 

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
 #ifndef AGFICHAVACUNACION_H
 #define AGFICHAVACUNACION_H
 
 #include "utils.h"

 // Define el tipo TAGFichaVacunacion como un puntero a rep_agFichaVacunacion.
 typedef struct rep_agFichaVacunacion *TAGFichaVacunacion;
 
// Función para crear un nuevo arbol general
// Devuelve un nuevo árbol general vacío
TAGFichaVacunacion crearTAGFichaVacunacion();

// Función para insertar una nueva vacuna en el árbol general, agrega 'codVacuna'
// como primer hijo del nodo que representa la vacuna 'codVacunaPadre'. Si
// codVacunaPadre == '-1', codVacuna se almacena como nodo raíz.
// PRE: La vacuna con cod 'codVacuna' no está en el árbol.
// PRE: Si el árbol es vacío, la primer inserción será con codVacunaPadre = -1
// PRE: Si el árbol no es vacío, la vacuna con codVacunaPadre pertenece al árbol
void insertarVacunaTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion, int codVacunaPadre, int codVacuna);

// Función para imprimir la ficha de vacunación por nivel. Los hermanos
// se imprimen según el orden de creación. 
// La impresión debe tener el siguiente formato:
// Ficha Vacunacion:
// <cod vacuna raiz>
//     <cod vacuna hijo 1 (primer nivel)>
//         <cod vacuna hijo 1 (segundo nivel)>
//         <cod vacuna hijo 2 (segundo nivel)>
//             <cod vacuna hijo 1 (tercer nivel)>
//             ...
//         <cod vacuna hijo 3 (segundo nivel)>
//         ...
//     <cod vacuna hijo 2 (primer nivel)>
//     ...
void imprimirTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion);

// Función para liberar la memoria asignada a una ficha de vacunación.
void liberarTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion);

// Función que determina si una vacuna está en la ficha de vacunación.
// Devuelve true si la vacuna está en el árbol, false en caso contrario.
bool existeVacunaTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion, int codVacuna);

// Funcion para obtener la altura del árbol general.
nat alturaTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion);

// Función para obtener la cantidad de vacunas en la ficha de vacunación.
nat cantidadTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion);

// Función para eliminar una vacuna de la ficha de vacunación.
// En caso de la vacuna tenga hijos, estos también son eliminados.
// PRE: existeVacunaTAGFichaVacunacion(fichaVacunacion, codVacuna) == true
void removerVacunaTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion, int codVacuna);

// Dados dos árboles generales, devuelve true si son iguales. Los árboles se consideran iguales
// si: 
//   1) Todas las vacunas de fv1 están en fv2
//   2) Todas las vacunas de fv2 están en fv1
//   3) Todas las vacunas tienen el mismo padre en ambos árboles
bool igualesTAGFichaVacunacion(TAGFichaVacunacion fv1, TAGFichaVacunacion fv2);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en agFichaVacunacion.cpp 

 #endif // AGFICHAVACUNACION_H
 
 