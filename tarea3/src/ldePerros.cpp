#include "../include/ldePerros.h"

struct rep_perros_aux{
    TPerro perro;
    rep_perros_aux* siguiente;
    rep_perros_aux* anterior;
};

struct rep_tldeperros {
    rep_perros_aux* inicio;
    rep_perros_aux* fin;
    int cantidadPerros;
};



/* ********** FUNCIONES NUEVAS TAREA 3 ********** */ 

TPerro removerPrimeroTLDEPerros(TLDEPerros &ldePerros){
    int perro = idTPerro(ldePerros->inicio->perro);
    return removerPerroTLDEPerros(ldePerros, perro);
}

TPerro removerUltimoTLDEPerros(TLDEPerros &ldePerros) {
    int perro = idTPerro(ldePerros->fin->perro);
    return removerPerroTLDEPerros(ldePerros, perro);
}

/* ********** FUNCIONES TAREA 2 ********** */ 


TLDEPerros crearTLDEPerrosVacia(){
    TLDEPerros perros = new rep_tldeperros;
    perros->fin=NULL;
    perros->inicio=NULL;
    perros->cantidadPerros=0;
    return perros;
}

void insertarTLDEPerros(TLDEPerros &ldePerros, TPerro perro){
    if (ldePerros!=NULL && ldePerros->inicio != NULL && ldePerros->fin!=NULL){
        rep_perros_aux* auxRecorr = ldePerros->fin;
        while (auxRecorr->anterior!=NULL && edadTPerro(perro)<=edadTPerro(auxRecorr->perro)){
            auxRecorr=auxRecorr->anterior;
        }
        rep_perros_aux* nuevoTLDE = new rep_perros_aux;
        nuevoTLDE->perro = perro;
        if(auxRecorr == ldePerros->inicio && edadTPerro(perro)<=edadTPerro(auxRecorr->perro)){
            ldePerros->inicio=nuevoTLDE;
            nuevoTLDE->anterior=NULL;
            nuevoTLDE->siguiente=auxRecorr;
            auxRecorr->anterior=nuevoTLDE;
            ldePerros->cantidadPerros++;
        }else {
            nuevoTLDE->siguiente=auxRecorr->siguiente;
            nuevoTLDE->anterior=auxRecorr;
            if (auxRecorr->siguiente != NULL) {
                auxRecorr->siguiente->anterior = nuevoTLDE;
            }
            auxRecorr->siguiente=nuevoTLDE;
            if (auxRecorr == ldePerros->fin) ldePerros->fin=nuevoTLDE;
            ldePerros->cantidadPerros++;
        }
    }else {
        if (ldePerros == NULL) {
            ldePerros = new rep_tldeperros;
            ldePerros->inicio = NULL;
            ldePerros->fin = NULL;
            ldePerros->cantidadPerros = 0;
        }
        rep_perros_aux* nuevoTLDE = new rep_perros_aux;
        nuevoTLDE->perro = perro;
        nuevoTLDE->anterior=NULL;
        nuevoTLDE->siguiente=NULL;
        ldePerros->inicio=nuevoTLDE;
        ldePerros->fin=nuevoTLDE;
        ldePerros->cantidadPerros++;
    }

}
void liberarTLDEPerros(TLDEPerros &ldePerros){
    if (ldePerros != NULL) {
        rep_perros_aux* actual = ldePerros->inicio;
        while (actual != NULL) {
            rep_perros_aux* elim = actual;
            actual = actual->siguiente;
            liberarTPerro(elim->perro);
            delete elim;
            elim=NULL;
        }
        delete ldePerros;
        ldePerros = NULL;
    }
}

void imprimirTLDEPerros(TLDEPerros ldePerros){
    printf("LDE Perros:\n");
    if (ldePerros != NULL) {
        rep_perros_aux* auxRecorrImpr = ldePerros->inicio;
        while (auxRecorrImpr!=NULL){
            imprimirTPerro(auxRecorrImpr->perro);
            auxRecorrImpr=auxRecorrImpr->siguiente;
        }
    }

}

void imprimirInvertidoTLDEPerros(TLDEPerros ldePerros){
    printf("LDE Perros:\n");
    if (ldePerros != NULL) {
        rep_perros_aux* auxRecorrImpr = ldePerros->fin;
        while (auxRecorrImpr!=NULL){
            imprimirTPerro(auxRecorrImpr->perro);
            auxRecorrImpr=auxRecorrImpr->anterior;
        }
    }
}

nat cantidadTLDEPerros(TLDEPerros ldePerros){
    return ldePerros->cantidadPerros;
}

TPerro removerPerroTLDEPerros(TLDEPerros &ldePerros, int id){
    rep_perros_aux* auxRecorrElimPerro = ldePerros->inicio;
    TPerro perro;
    if (ldePerros!=NULL){
        while (auxRecorrElimPerro!=NULL && idTPerro(auxRecorrElimPerro->perro)!=id){
            auxRecorrElimPerro=auxRecorrElimPerro->siguiente;
        }
        perro=auxRecorrElimPerro->perro;
        if(auxRecorrElimPerro->anterior==NULL)ldePerros->inicio = auxRecorrElimPerro->siguiente;   
        else auxRecorrElimPerro->anterior->siguiente = auxRecorrElimPerro->siguiente;

        if(auxRecorrElimPerro->siguiente==NULL) ldePerros->fin=auxRecorrElimPerro->anterior;
        else auxRecorrElimPerro->siguiente->anterior = auxRecorrElimPerro->anterior;
        // auxRecorrElimPerro->anterior->siguiente=auxRecorrElimPerro->siguiente;
        // auxRecorrElimPerro->siguiente->anterior=auxRecorrElimPerro->anterior;
        ldePerros->cantidadPerros--;
        delete auxRecorrElimPerro;
        auxRecorrElimPerro=NULL;
    }
    
    return perro;
}

TPerro obtenerPrimeroTLDEPerros(TLDEPerros ldePerros){
    return ldePerros->inicio->perro;
}

TPerro obtenerUltimoTLDEPerros(TLDEPerros ldePerros){
    return ldePerros->fin->perro;
}

TPerro obtenerNesimoTLDEPerros(TLDEPerros ldePerros, int n){
    rep_perros_aux* auxObtener = ldePerros->inicio;
    for(int i=1; i<=n &&i!=n;i++){
        auxObtener=auxObtener->siguiente;
    }
    return auxObtener->perro;
}

bool existePerroTLDEPerros(TLDEPerros ldePerros, int id){
    rep_perros_aux* auxObtener = ldePerros->inicio;
    while(auxObtener!=NULL && idTPerro(auxObtener->perro)!=id){
        auxObtener=auxObtener->siguiente;
    }
    if (auxObtener==NULL) return false;
    return idTPerro(auxObtener->perro)==id;
}