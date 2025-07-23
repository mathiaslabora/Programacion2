#include <stdio.h>

struct nodoAB{
    unsigned int elem;
    nodoAB *izq, *der;
};
typedef nodoAB * AB;


//(a)
AB arbolVacio (){
    AB arbolAB = new nodoAB;
    arbolAB->der=NULL;
    arbolAB->izq=NULL;
    arbolAB->elem=0;
    return arbolAB;
}


//(b)
AB consArbol(unsigned int a, AB arb1, AB arb2){
    AB nuevoArbol = arbolVacio();
    nuevoArbol->elem = a;
    if (arb1 == NULL||arb2==NULL||arb1->elem < arb2->elem){
        nuevoArbol->izq=arb1;
        nuevoArbol->der=arb2;
    }else {
        nuevoArbol->izq=arb2;
        nuevoArbol->der=arb1;
    }    
    return nuevoArbol;
}

//(c)
unsigned int contarElems(AB arbolAB){
    if (arbolAB != NULL){
    return 1 + contarElems(arbolAB->izq) + contarElems(arbolAB->der);
    }
    return 0;
}

void imprimirABOrd(AB arbolAB){
    if (arbolAB!=NULL){
    imprimirABOrd(arbolAB->izq);
    printf("%d\n", arbolAB->elem);
    imprimirABOrd(arbolAB->der);
    }
}

//(4)
int contarHojas(AB arbolAB){
    if (arbolAB == NULL) {
        return 0;
    }
    if (arbolAB->izq == NULL && arbolAB->der == NULL) {
        return 1;
    }
    return contarHojas(arbolAB->izq) + contarHojas(arbolAB->der);
}

int maximo (int arb1, int arb2){
    if (arb1>arb2){
        return arb1;
    }
    return arb2;
}

int altura (AB arbolAB){
    if(arbolAB!=NULL){
        return 1+ maximo(altura(arbolAB->izq), altura(arbolAB->der));
    }
    return 0;
}



AB copiarArbol (AB arbol){
    if (arbol == NULL) {
        return NULL;
    }
    AB nuevoArbol = new nodoAB;
    nuevoArbol->elem = arbol->elem;
    nuevoArbol->izq = copiarArbol(arbol->izq);
    nuevoArbol->der = copiarArbol(arbol->der);
    return nuevoArbol;
}

AB copiarSubArbol(AB t, int x) { 
    if (t == NULL) return NULL;

    AB retAB = NULL;

    if (t->elem == x) { 
        retAB = copiarArbol(t); 
    } else {
        copiarSubArbol(t->izq, x);
        copiarSubArbol(t->der, x);
    }

    return retAB;
}


int main(){

    AB n1 = consArbol(10, NULL, NULL);
    AB n2 = consArbol(5, NULL, NULL);
    AB n3 = consArbol(20, NULL, NULL);
    AB n4 = consArbol(70, NULL, NULL);
    AB arbol = consArbol(15, n1, n2);
    arbol = consArbol(25, arbol, n3);
    arbol = consArbol(80, arbol, n4);

    unsigned int cantArbol = contarElems(arbol);
    printf("Cantidad elementos del arbol: %d\n", cantArbol);
    printf("Imprimo elementos del arbol:\n");

    imprimirABOrd(arbol);

    int cantHojas = contarHojas(arbol);
    printf("Cantidad de hojas: %d\n", cantHojas);
    int alto = altura(arbol);
    printf("Altura arbol: %d\n", alto);

    AB arbol2 = copiarArbol(arbol);
    // printf("Arbol 2:\n");
    // imprimirABOrd(arbol2);

    AB arbolSubCopia = copiarSubArbol(arbol, 80);
    imprimirABOrd(arbolSubCopia);

    return 0;
}