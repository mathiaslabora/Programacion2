/*
  Módulo de definición de 'TRefugio'.

  Los elementos de tipo TRefugio almacenan la información necesaria para almacenar un refugio. Además,
  proveen funciones para operar sobre él. 

  Una elemento de tipo TRefugio debe mantener:

    - Un elemento de tipo ABBPersonas para registrar las personas asociadas al refugio.
    - Un elemento de tipo lseAdopciones para listar todas las adopciones realizadas.
    - Un elemento de tipo ldePerros para llevar constancia de los perros que son o fueron parte del refugio.
    - Un elemento de tipo agFichaVacunacion para indicar una ficha de vacunación completa para los perros.
    - Un elemento de tipo conjuntoPerros, para indicar los perros que fueron adoptados.
    - Un elemento de tipo colaPerros, para representar el orden de los paseos.
    - Un elemento de tipo tablaFichaVacunacion, para almacenar y acceder a las fichas de vacunación de los perros.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/
#ifndef TREFUGIO_H
#define TREFUGIO_H

#include <string.h>

#include "abbPersonas.h"
#include "lseAdopciones.h"
#include "ldePerros.h"
#include "agFichaVacunacion.h"
#include "conjuntoPerros.h"
#include "colaPerros.h"
#include "colaDePrioridadPerros.h"
#include "tablaFichaVacunacion.h"

//  Constante para definir la cantidad máxima de perros en el refugio. 
const int MAX_PERROS_REFUGIO = 200;

// Define el tipo TRefugio como un puntero a rep_refugio
typedef struct rep_refugio *TRefugio;

// Crea una instancia de refugio y crea las estructuras auxiliares necesarias, 
// siendo 'cantEstimada' la cantidad estimada de perros a almacenar.
TRefugio crearTRefugio(int cantEstimada);

// Libera el refugio y toda la memoria utilizada por sus estructuras.
// Libera la memoria de todos los perros del refugio y todas las personas registradas.
// Luego de su ejecución, la variable refugio apunta a NULL.
void liberarTRefugio(TRefugio &refugio);

// Función para agregar una vacuna al esquema de vacunas del refugio.
// Actualiza la ficha de vacunación ingresando la nueva vacuna.
// PRE: La vacuna con cod 'codVacuna' no está en la ficha de vacunación.
// PRE: Si la ficha del perro es vacía (primer vacuna), codVacunaPadre = -1
// PRE: Si la ficha del perro no es vacía, la vacuna con codVacunaPadre ya se encuentra en la ficha
void agregarVacunaTRefugio(TRefugio refugio, int codVacunaPadre, int codVacuna);

// Función para imprimir el esquema de vacunas del refugio según la función imprimirTAGFichaVacunacion.
void imprimirEsquemaVacunacionTRefugio(TRefugio refugio);

// Realiza las acciones necesarias para registrar una persona en el refugio:
//   - Inserta la persona en el árbol de personas.
// PRE: no existe una persona con ci 'ciPersona' registrada en el refugio
// POST: la persona ingresada en el refugio no comparte memoria con el parámetro 'persona'
void registrarPersonaTRefugio(TRefugio &refugio, TPersona persona);

// Imprime las personas del refugio. El formato y orden de impresión es aquel indicado 
// por la función imprimirTABBPersonas.
void imprimirPersonasTRefugio(TRefugio refugio);

// Realiza las acciones necesarias para ingresar un perro al refugio:
//   - Inserta el perro en la lista de perros.
//   - Inserta el perro en la cola de paseos.
// PRE: no existe un perro con id 'idPerro' en el refugio
// POST: el perro agregado en el refugio no comparte memoria con el parámetro 'perro'
void ingresarPerroTRefugio(TRefugio &refugio, TPerro perro);

// Imprime la cola de paseos con la función imprimirTColaPerros.
void imprimirColaPaseosTRefugio(TRefugio refugio);

// Imprime la lista de perros manejada por el refugio (tanto adoptados como 
// no adoptados). Si cachorrosPrimero == true, imprime
// los perros en orden ascendente de edad. En caso contrario los imprime en orden
// descendente. 
// El formato de impresión es el indicado por la función 'imprimirTLDEPerros'.
void imprimirPerrosTRefugio(TRefugio refugio, bool cachorrosPrimero);

// Función que simula las acciones realizadas al pasear los perros
// Desencola 'cantidad' de perros de la cola de paseos. Para cada uno de ellos imprime:
// Paseando perro: <id_perro> <nombre_perro>
// Luego vuelve a encolar cada perro en el mismo orden en que fueron desencolados.
// PRE: 'cantidad' es menor igual a la cantidad de perros en la cola de perros
void pasearPerrosTRefugio(TRefugio &refugio, nat cantidad);

// Dada una persona de id 'idPersona' y un perro de id 'idPerro', realiza las acciones necesarias para 
// adoptar a un perro:
//   - Inserta una nueva adopción en la lista de adopciones para la fecha, perro y persona.
//   - Remueve el perro de la cola de paseos.
//   - Agrega el perro en los perros adoptados de la persona.
//   - Agrega al perro en el conjuntoPerros de perros adoptados.
// PRE: La persona de ci 'ciPersona' está registrada en el refugio
// PRE: El perro de id 'idPerro' pertenece al refugio y no ha sido adoptado.
// PRE: la persona adoptante no ha superado el límite de perros que puede adoptar.
void adoptarPerroTRefugio(TRefugio &refugio, int idPerro, int ciPersona, TFecha fecha);

// Imprime la lista de adopciones según el formato de la función 'imprimirTLSEAdopciones'
void imprimirAdopcionesTRefugio(TRefugio refugio);

// Función para vacunar un perro.
// Actualiza la ficha de vacunación ingresando la vacuna administrada.
// Si es la primera vacuna administrada al perro de id 'idPerro' crea una ficha de vacunación 
// con la vacuna 'codVacuna' y asocia al perro con la ficha creada en la tabla. 
// Incrementa la vitalidad del perro en 1.
// PRE: el perro pertenece al refugio
// PRE: La vacuna con cod 'codVacuna' no está en la ficha de vacunación.
// PRE: Si la ficha del perro es vacía (primer vacuna), codVacunaPadre = -1
// PRE: Si la ficha del perro no es vacía, la vacuna con codVacunaPadre ya se encuentra en su ficha
void vacunarPerroTRefugio(TRefugio refugio, int idPerro, int codVacunaPadre, int codVacuna);

// Imprime la ficha de vacunción del perro dado por idPerro, según el formato
// dado por imprimirTAGFichaVacunacion.
// PRE: el perro pertenece al refugio.
void imprimirFichaVacunacionPerroTRefugio(TRefugio refugio, int idPerro); 

// Función para obtener los perros sin ficha de vacunación completa.
// Recorre todos los perros del refugio (ignorando aquellos que fueron adoptados) y 
// devuelve aquellos sin una ficha de vacunación completa.
// Los perros son retornados en una cola de prioridad en orden de vitalidad (el perro de menor vitalidad es el más prioritario).
// Si dos perros tienen la misma vitalidad, se insertan en el mismo orden que aparecen
// en la lista de perros del refugio.
// POST: los perros en la cola de prioridad no comparten memoria con los perros del refugio. 
TColaDePrioridadPerros obtenerPerrosSinVacunacionTRefugio(TRefugio &refugio);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para 
// la implementación solicitada se encuentran en refugio.cpp 

#endif  // TREFUGIO_H