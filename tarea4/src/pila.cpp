#include "../include/pila.h"

struct rep_pila_aux {
    int elem;
    rep_pila_aux* sig;
};

struct rep_pila{
    rep_pila_aux* cima;
    int cantidad;
};

/* Debe ejecutar en O(1) peor caso. */
TPila crearTPila(){
    TPila nuevaPila = new rep_pila;
    nuevaPila->cima=NULL;
    nuevaPila->cantidad=0;
    return nuevaPila;
}

/* Debe ejecutar en O(n) peor caso, donde n es la cantidad de elementos en la pila. */
// Luego de la función, el puntero pila debe apuntar a NULL.
void liberarTPila(TPila &pila){
    if(pila != NULL){
        while(pila->cima!=NULL){
            rep_pila_aux* aborrar=pila->cima;
            pila->cima=pila->cima->sig;
            delete aborrar;
            aborrar=NULL;
        }
        delete pila;
        pila=NULL;
        
    }
}

/* Debe ejecutar en O(1) peor caso. */
void apilarTPila(TPila &pila, int elem){
        rep_pila_aux* nuevo = new rep_pila_aux;
        nuevo->elem=elem;
        nuevo->sig=pila->cima;
        pila->cima=nuevo;
        pila->cantidad+=1;
}

void auxImprimir(rep_pila_aux* imp){
    if(imp != NULL){
        auxImprimir(imp->sig);
        printf(" %d", imp->elem);
    }
}
/* Debe ejecutar en O(n) peor caso, donde n es la cantidad de elementos en la pila */
void imprimirTPila(TPila pila){
    TPila auxRecorrer = pila;
    printf("Pila:");
    auxImprimir(auxRecorrer->cima);
    printf("\n");
} 

/* Debe ejecutar en O(1) peor caso. */
nat cantidadTPila(TPila pila){
    return pila->cantidad;
}

/* Debe ejecutar en O(1) peor caso. */
int cimaTPila(TPila pila) {
    return pila->cima->elem;
}

/* Debe ejecutar en O(1) peor caso. */
void desapilarTPila(TPila &pila){
    rep_pila_aux* aborrar = pila->cima;
    pila->cima=pila->cima->sig;
    pila->cantidad-=1;
    delete aborrar;
    aborrar=NULL;
}







 
 