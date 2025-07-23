
#include "../include/abbPersonas.h"

struct rep_abbPersonas {
    int cedula;
    TPersona persona;
    TABBPersonas izq, der;
};

TABBPersonas crearTABBPersonasVacio(){
    TABBPersonas arbolPersonas = NULL;
    return arbolPersonas;
}
nat maximo(nat a, nat b){
    if(a>b)return a;
    else return b;
}

void insertarTPersonaTABBPersonas(TABBPersonas &abbPersonas, TPersona persona){
    if(abbPersonas==NULL){//Implemento la funcion aportada en clase teorica FING
        abbPersonas = new rep_abbPersonas;
        abbPersonas->cedula = ciTPersona(persona);
        abbPersonas->persona = persona;
        abbPersonas->izq = NULL;
        abbPersonas->der = NULL;
    }else if(ciTPersona(persona) < abbPersonas->cedula){
        insertarTPersonaTABBPersonas(abbPersonas->izq, persona);
    }else if(ciTPersona(persona) > abbPersonas->cedula){
        insertarTPersonaTABBPersonas(abbPersonas->der, persona);
    }
}

void imprimirTABBPersonas(TABBPersonas abbPersonas){
    //Utilizo inOrder-enOrden dictado en clase teorica FING
    if(abbPersonas!=NULL){
        imprimirTABBPersonas(abbPersonas->izq);
        imprimirTPersona(abbPersonas->persona);
        imprimirTABBPersonas(abbPersonas->der);
    } 
}


void liberarTABBPersonas(TABBPersonas &abbPersonas){
    if(abbPersonas!=NULL){//utilizo postOrder
        liberarTABBPersonas(abbPersonas->izq);
        liberarTABBPersonas(abbPersonas->der);
        liberarTPersona(abbPersonas->persona);
        delete abbPersonas;
        abbPersonas=NULL;
    } 
}

bool existeTPersonaTABBPersonas(TABBPersonas abbPersonas, int ciPersona){
    //Por recomendacion del teorico utilizo busqueda iterativa
    TABBPersonas auxRecorrABB = abbPersonas;
    while(auxRecorrABB!=NULL && auxRecorrABB->cedula!=ciPersona){
        if (ciPersona > auxRecorrABB->cedula ){
            auxRecorrABB=auxRecorrABB->der; 
        }else{
            auxRecorrABB=auxRecorrABB->izq;
        }
    }
    return auxRecorrABB!=NULL && auxRecorrABB->cedula==ciPersona;
}

TPersona obtenerTPersonaTABBPersonas(TABBPersonas abbPersonas, int ciPersona){
    TABBPersonas auxRecorrABB = abbPersonas;
    while(auxRecorrABB!=NULL && auxRecorrABB->cedula!=ciPersona){
        if (ciPersona > auxRecorrABB->cedula ){
            auxRecorrABB=auxRecorrABB->der; 
        }else{
            auxRecorrABB=auxRecorrABB->izq;
        }
    }
    return auxRecorrABB->persona;
}

nat alturaTABBPersonas(TABBPersonas abbPersonas){
    if(abbPersonas==NULL){
        return 0;
    }else{
        return 1 + maximo(alturaTABBPersonas(abbPersonas->izq),  alturaTABBPersonas(abbPersonas->der));
    }
}

TPersona maxCITPersonaTABBPersonas(TABBPersonas abbPersonas){
    if (abbPersonas->der == NULL) {
        return abbPersonas->persona;
    }
    return maxCITPersonaTABBPersonas(abbPersonas->der);
}

TABBPersonas maxABBP (TABBPersonas abbPersonas){
    if(abbPersonas==NULL) return NULL;
    else {
        while (abbPersonas->der!=NULL){
            abbPersonas=abbPersonas->der;
        }
        return abbPersonas;
    }

}

void removerTPersonaTABBPersonas(TABBPersonas &abbPersonas, int ciPersona){
    if(abbPersonas!=NULL){
        if(ciPersona < abbPersonas->cedula){
            removerTPersonaTABBPersonas(abbPersonas->izq, ciPersona);
        }else if (ciPersona > abbPersonas->cedula){
            removerTPersonaTABBPersonas(abbPersonas->der, ciPersona);
        }else{
            if(abbPersonas->der == NULL){
                TABBPersonas aElim = abbPersonas;
                liberarTPersona(abbPersonas->persona);
                abbPersonas=abbPersonas->izq;
                delete aElim;
                aElim = NULL;
            }else if(abbPersonas->izq == NULL){
                TABBPersonas aElim = abbPersonas;
                liberarTPersona(abbPersonas->persona);
                abbPersonas=abbPersonas->der;
                delete aElim;
                aElim = NULL;
            }else{
                TABBPersonas removerIgual=maxABBP(abbPersonas->izq);
                liberarTPersona(abbPersonas->persona);
                abbPersonas->cedula = removerIgual->cedula;
                abbPersonas->persona = copiarTPersona(removerIgual->persona);
                removerTPersonaTABBPersonas(abbPersonas->izq, removerIgual->cedula);
            }
        }
    }
}

int cantidadTABBPersonas(TABBPersonas abbPersonas){
    if(abbPersonas==NULL){
        return 0;
    }else{
        return 1 + cantidadTABBPersonas(abbPersonas->izq) +  cantidadTABBPersonas(abbPersonas->der);
    }
}

TABBPersonas auxRecorrNesima(TABBPersonas abbPersonas, int &cont, int n){
    if(abbPersonas!=NULL){
        TABBPersonas resIzq = auxRecorrNesima(abbPersonas->izq, cont, n);
        if(resIzq!=NULL)return resIzq;
        if (cont == n) return abbPersonas;
        cont++;
        TABBPersonas resDer = auxRecorrNesima(abbPersonas->der, cont, n);
        if(resDer!=NULL)return resDer;   
    }
    return NULL;
}
TPersona obtenerNesimaPersonaTABBPersonas(TABBPersonas abbPersonas, int n){
    int contador = 1;
    TABBPersonas puntPersona = auxRecorrNesima(abbPersonas, contador, n);
    return puntPersona->persona;
}

TABBPersonas filtradoAux (TABBPersonas abbPersonas,TABBPersonas &abbPersonasCopia, TFecha fecha, int criterio){
    if(abbPersonas!=NULL){
        filtradoAux(abbPersonas->izq,abbPersonasCopia, fecha, criterio);
    
            if(criterio < 0 && compararTFechas(fechaNacimientoTPersona(abbPersonas->persona),fecha)==-1){
                TPersona copiaPer = copiarTPersona(abbPersonas->persona);
                insertarTPersonaTABBPersonas(abbPersonasCopia, copiaPer);               
            }else if(criterio == 0 && compararTFechas(fechaNacimientoTPersona(abbPersonas->persona),fecha)==0) {
                TPersona copiaPer = copiarTPersona(abbPersonas->persona);
                insertarTPersonaTABBPersonas(abbPersonasCopia, copiaPer);
            }else if(criterio > 0 && compararTFechas(fechaNacimientoTPersona(abbPersonas->persona),fecha)==1)
                {
                TPersona copiaPer = copiarTPersona(abbPersonas->persona);
                insertarTPersonaTABBPersonas(abbPersonasCopia, copiaPer);
            }
        filtradoAux(abbPersonas->der,abbPersonasCopia, fecha, criterio);

        }
        return NULL;
}


TABBPersonas filtradoPorFechaDeNacimientoTABBPersonas(TABBPersonas abbPersonas, TFecha fecha, int criterio){
    TABBPersonas copiaABB = crearTABBPersonasVacio();
    filtradoAux(abbPersonas, copiaABB, fecha, criterio);
    return copiaABB;
}