#include <stdio.h>

struct nodo {
    int elem ;
    nodo * sig ;
    };
typedef nodo * lista ;

lista ultimo(lista l) {
    lista aux = l;
    if (l == NULL) {
        return NULL;
    }
    while (aux->sig != NULL) {
        aux = aux->sig;
    }
    return aux;
}

int promedio (lista l){
    lista aux = l;
    int contador=0;
    int resultado=0;
    if (l==NULL){
        return 0;
    }
    resultado=aux->elem;
    contador=1;
    while (aux->sig != NULL){
        aux = aux->sig;
        resultado+=aux->elem;
        contador+=1;
    }
    return resultado/contador;
}
void insOrden (lista l, int x){
    lista aux = l;
    lista nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig=NULL;

    if(aux == NULL|| aux->elem > x){
        nuevo->sig=aux;
        aux=nuevo;
        return;
    }
    while (aux->sig != NULL && aux->sig->elem < x){
        aux=aux->sig;
    }
    nuevo->sig=aux->sig;
    aux->sig=nuevo;
    //return aux;
}

int main() {
    lista l = new nodo{1, NULL};
    l->sig = new nodo{2, NULL};
    l->sig->sig = new nodo{3, NULL};

    lista last = ultimo(l);
    if (last != NULL) {
        printf("El último elemento es: %d\n", last->elem);
    } else {
        printf("La lista está vacía.\n");
    }

    insOrden(l, 5);
    lista last2 = ultimo(l);
    printf("El último elemento es: %d\n", last2->elem);

    int prom = promedio(l);
    printf("El promedio de la lista es: %d\n", prom);

    printf("Aca imprimo una direccion de memoria: %p\n", l);
    printf("Aca imprimo un elemento: %d\n", l->elem);
    printf("Aca imprimo la direccion de memoria del siguiente: %p\n", l->sig);
    // Liberar memoria
    while (l != NULL) {
        lista temp = l;
        l = l->sig;
        delete temp;
    }

    return 0;
}





