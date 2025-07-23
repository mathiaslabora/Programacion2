#include "../include/tablaFichaVacunacion.h"

// Se debe implementar mediante una tabla de dispersión abierta (hash)

struct nodoTabla{
    int id;
    TAGFichaVacunacion ficha;
    nodoTabla* sig;
};

struct rep_tablaFichaVacunacion {
    nodoTabla ** tabla;
    int cantidad;
    int cota;
};

/* La función es O(cantEstimada) peor caso. */
TTablaFichaVacunacion crearTTablaFichaVacunacion(int cantEstimada){
    TTablaFichaVacunacion tablaNueva = new rep_tablaFichaVacunacion();
    tablaNueva->tabla = new nodoTabla*[cantEstimada];
    for (int i = 0; i < cantEstimada; i++) {
        tablaNueva->tabla[i] = NULL;
    }
    tablaNueva->cantidad=0;
    tablaNueva->cota=cantEstimada;
    return tablaNueva;
}

/* La función es O(n + max) peor caso, donde n es la cantidad actual de fichas en la tabla 
y max la cantidad esperada de fichas en la tabla. */
void liberarTTablaFichaVacunacion(TTablaFichaVacunacion &tabla){
    if (tabla==NULL){return;}
    for(int i = 0; i<tabla->cota;i++){
        nodoTabla* actual = tabla->tabla[i];
        while (actual!=NULL){
            liberarTAGFichaVacunacion(actual->ficha);
            nodoTabla* borro=actual;
            actual=actual->sig;
            delete borro;
            borro=NULL;
        }
    }
    delete[] tabla->tabla;
    delete tabla;
    tabla = NULL;
}

nat auxHash (int idPerro, int tamanio){
    return idPerro % tamanio;
}

// Para calcular la posición en la que se debe insertar la asociación en
// la tabla de dispersión abierta se debe utilizar la función de dispersión dada por 
// idPerro % tamanio (tamanio es la cantidad estimada de los elementos de la tabla).
// Por convención se deberá insertar la asociación al comienzo de la lista asociada a esa posición.
/* La función es O(1) peor caso. */
void insertarTTablaFichaVacunacion(TTablaFichaVacunacion &tabla, int idPerro, TAGFichaVacunacion ficha){
    nat posicion = auxHash(idPerro, tabla->cota);
    nodoTabla* nueva = new nodoTabla;
    nueva->ficha= ficha;
    nueva->sig = tabla->tabla[posicion];
    nueva->id = idPerro;
    tabla->tabla[posicion]=nueva;
    tabla->cantidad+=1;
}

// Imprime cada ficha de vacunación de la tabla (idPerro, ficha), en orden creciente de 
// posiciones asociadas en la tabla, en líneas sucesivas (utilizando la función 'imprimirTAGFichaVacunacion')
// En caso de que haya más de una ficha en la misma posición, se deben imprimir por orden
// de ingreso a la tabla, desde la más reciente a la menos.
// La función es O(n + max) peor caso, donde n es la cantidad de fichas en la tabla 
// y max la cantidad esperada de fichas en la tabla.
void imprimirTTablaFichaVacunacion(TTablaFichaVacunacion tabla){
    nodoTabla** auxRecorrer = tabla->tabla;
    int i, cota = tabla->cota;
    for (i=0; i<cota;i++){
        nodoTabla* auxInt = auxRecorrer[i];
        while (auxInt!=NULL){
            printf("Perro ID: %d\n", auxInt->id);
            imprimirTAGFichaVacunacion(auxInt->ficha);
            auxInt=auxInt->sig;
        }
    }
}

/* La función es O(1) promedio. */
bool perteneceTTablaFichaVacunacion(TTablaFichaVacunacion tabla, int idPerro){
    nat posicion = auxHash(idPerro, tabla->cota);
    nodoTabla* recorrPert = tabla->tabla[posicion];
    while (recorrPert!= NULL){
       if (recorrPert->id==idPerro) return true;
       recorrPert=recorrPert->sig;
    }
    return false;
}

/* La función es O(1) promedio. */
TAGFichaVacunacion obtenerFichaTTablaFichaVacunacion(TTablaFichaVacunacion tabla, int idPerro){
    nat posicion = auxHash(idPerro, tabla->cota);
    nodoTabla* recorrPert = tabla->tabla[posicion];
    while (recorrPert!= NULL){
       if (recorrPert->id==idPerro) return recorrPert->ficha;
       recorrPert=recorrPert->sig;
    }
    return NULL;
}

/* La función es O(1) promedio. */
void eliminarDeTTablaFichaVacunacion(TTablaFichaVacunacion &tabla, int idPerro){
    nat posicion = auxHash(idPerro, tabla->cota);
    nodoTabla* recorrPert = tabla->tabla[posicion];
    nodoTabla* anterior = NULL;
    if (posicion >= 0 && posicion <= (nat)tabla->cota){
    while (recorrPert!= NULL){
        if (recorrPert->id==idPerro) {
            if(anterior==NULL){
                tabla->tabla[posicion] = recorrPert->sig;
            }else{
                anterior->sig=recorrPert->sig;
            }
            nodoTabla* aBorrar = recorrPert;
            liberarTAGFichaVacunacion(recorrPert->ficha);
            anterior=recorrPert;
            recorrPert=recorrPert->sig;
            delete aBorrar;
            aBorrar=NULL;
            tabla->cantidad -= 1;

        }else{
        anterior=recorrPert;
        recorrPert=recorrPert->sig;
        }
    }
}
}




