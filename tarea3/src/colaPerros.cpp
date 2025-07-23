#include "../include/colaPerros.h"

struct rep_colaPerros_aux{
    TPerro perro;
    rep_colaPerros_aux* sig;
};

struct rep_colaPerros {
    rep_colaPerros_aux* inicio;
    rep_colaPerros_aux* fin;
    int cantidad;
};

/* Debe ejecutar en O(1) peor caso. */
TColaPerros crearTColaPerros(){
    TColaPerros nuevaCola= new rep_colaPerros;
    nuevaCola->inicio=nuevaCola->fin=NULL;
    nuevaCola->cantidad=0;
    return nuevaCola;
}

/* Debe ejecutar en O(n) peor caso, donde n es la cantidad de perros 
en la cola.*/
// Debe liberar toda la memoria asociada a la cola, incluidos sus perros.
// Luego de la función, el puntero colaPerros debe apuntar a NULL.
void liberarTColaPerros(TColaPerros &colaPerros){
    if(colaPerros != NULL){
        while(colaPerros->inicio!=NULL){
            rep_colaPerros_aux* aborrar=colaPerros->inicio;
            liberarTPerro(colaPerros->inicio->perro);
            colaPerros->inicio=colaPerros->inicio->sig;
            delete aborrar;
            aborrar=NULL;
        }
        delete colaPerros;
        colaPerros=NULL;
        
    }
}

/* Debe ejecutar en O(1) peor caso. */
// El resultado comparte memoria con el perro pasado por parámetro. 
void encolarTColaPerros(TColaPerros &colaPerros, TPerro perro){
    rep_colaPerros_aux* nuevo = new rep_colaPerros_aux;
    nuevo->perro = perro;
    nuevo->sig = NULL;

    if (colaPerros->fin == NULL) {
        colaPerros->inicio = nuevo;
        colaPerros->fin = nuevo;
    } else {
        colaPerros->fin->sig = nuevo;
        colaPerros->fin = nuevo;
    }
    colaPerros->cantidad+=1;
}
void imprimirAux(rep_colaPerros_aux* aux){
    if(aux!=NULL){
        imprimirTPerro(aux->perro);
        imprimirAux(aux->sig);
    }
}
/* Debe ejecutar en O(n) peor caso, donde n es el número de perros en la cola */
void imprimirTColaPerros(TColaPerros colaPerros){
    TColaPerros auxRecorrer = colaPerros;
    printf("Cola de Perros:\n");
    imprimirAux(auxRecorrer->inicio);
}

/* Debe ejecutar en O(1) peor caso. */
nat cantidadTColaPerros(TColaPerros colaPerros){
    return colaPerros->cantidad;
}

/* Debe ejecutar en O(1) peor caso. */
TPerro frenteTColaPerros(TColaPerros colaPerros) {
    return colaPerros->inicio->perro;
}

/* Debe ejecutar en O(1) peor caso. */
void desencolarTColaPerros(TColaPerros &colaPerros) {
    if (colaPerros != NULL){
    rep_colaPerros_aux* aborrar = colaPerros->inicio;
    colaPerros->inicio = aborrar->sig;
    if (colaPerros->inicio == NULL) {
        colaPerros->fin = NULL;
    }

    colaPerros->cantidad -= 1;
    liberarTPerro(aborrar->perro);
    delete aborrar;
    aborrar=NULL;
    }
}
