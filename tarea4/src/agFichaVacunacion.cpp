
#include "../include/agFichaVacunacion.h"

struct rep_agFichaVacunacion {
    int codVacuna;
    TAGFichaVacunacion pH, sH;
};
 
/* Debe ejecutar en O(1) peor caso. */
TAGFichaVacunacion crearTAGFichaVacunacion(){
    TAGFichaVacunacion nuevoArbol = NULL;
    return nuevoArbol;
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad de vacunas en el árbol. */
void insertarVacunaTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion, int codVacunaPadre, int codVacuna){
    if(codVacunaPadre == -1){
        // if (fichaVacunacion != NULL) {
        //     liberarTAGFichaVacunacion(fichaVacunacion);
        // }
        TAGFichaVacunacion nueva = new rep_agFichaVacunacion;
        nueva->codVacuna = codVacuna;
        nueva->pH = NULL;
        nueva->sH = NULL;
        fichaVacunacion = nueva;
    }else if(fichaVacunacion !=NULL){
        if(fichaVacunacion->codVacuna == codVacunaPadre){
            TAGFichaVacunacion nuevaVac = new rep_agFichaVacunacion;
            nuevaVac->codVacuna = codVacuna;
                nuevaVac->sH = fichaVacunacion->pH;
                nuevaVac->pH = NULL;
            fichaVacunacion->pH = nuevaVac;
        }else {
        insertarVacunaTAGFichaVacunacion(fichaVacunacion->pH,codVacunaPadre, codVacuna );
        insertarVacunaTAGFichaVacunacion(fichaVacunacion->sH,codVacunaPadre, codVacuna );
        }
    }

}

void imprimirEspaciosNivel(TAGFichaVacunacion fichaVacunacion, int lvl = 0){
    if(fichaVacunacion!=NULL){
    for (int i=0; i<lvl; i++){
        printf("    ");
    }
    printf("%d\n", fichaVacunacion->codVacuna);
    imprimirEspaciosNivel(fichaVacunacion->pH,lvl+1);
    imprimirEspaciosNivel(fichaVacunacion->sH,lvl);
    }
}


/*Debe ejecutar en O(n) peor caso, donde n es la cantidad de vacunas en el árbol. */
void imprimirTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
        printf("Ficha Vacunacion:\n");
        imprimirEspaciosNivel(fichaVacunacion);
}

/* Debe ejecutar en O(n) peor caso, donde n es la cantidad de vacunas en el árbol. */
// Luego de la función, el puntero fichaVacunacion debe apuntar a NULL.
void liberarTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion){
    if(fichaVacunacion!=NULL){
        liberarTAGFichaVacunacion(fichaVacunacion->pH);
        liberarTAGFichaVacunacion(fichaVacunacion->sH);
        delete fichaVacunacion;
        fichaVacunacion=NULL;
    }
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad de vacunas en el árbol. */
bool existeVacunaTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion, int codVacuna){
    if (fichaVacunacion!=NULL){
        if(fichaVacunacion->codVacuna==codVacuna)return true;
        return existeVacunaTAGFichaVacunacion(fichaVacunacion->pH, codVacuna)||
        existeVacunaTAGFichaVacunacion(fichaVacunacion->sH, codVacuna);
        
    }
    return false;
}
nat maxiAG(nat a, nat b){
    if(a>b)return a;
    else return b;
}
/* Debe ejecutar en O(n) peor caso, siendo n la cantidad de vacunas en el árbol. */
nat alturaTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    if (fichaVacunacion==NULL) return 0;
    return maxiAG(1+alturaTAGFichaVacunacion(fichaVacunacion->pH),alturaTAGFichaVacunacion(fichaVacunacion->sH));
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad de vacunas en el árbol general. */
nat cantidadTAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    if (fichaVacunacion==NULL)return 0;
    return 1+cantidadTAGFichaVacunacion(fichaVacunacion->pH)+cantidadTAGFichaVacunacion(fichaVacunacion->sH);
}

/* Debe ejecutar en O(n) peor caso, donde n es la cantidad de vacunas en el árbol. */
void removerVacunaTAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion, int codVacuna){
    if (fichaVacunacion!=NULL){
        if (fichaVacunacion->sH==NULL && fichaVacunacion->pH==NULL) liberarTAGFichaVacunacion(fichaVacunacion);
        else if(fichaVacunacion->pH!=NULL && fichaVacunacion->pH->codVacuna == codVacuna){
            TAGFichaVacunacion aBorrar = fichaVacunacion->pH;
            fichaVacunacion->pH=aBorrar->sH;
            aBorrar->sH=NULL;
            liberarTAGFichaVacunacion(aBorrar);
        }else if (fichaVacunacion->sH!= NULL && fichaVacunacion->sH->codVacuna == codVacuna){
            TAGFichaVacunacion aBorrar = fichaVacunacion->sH;
            fichaVacunacion->sH=aBorrar->sH;
            aBorrar->sH=NULL;
            liberarTAGFichaVacunacion(aBorrar);
        }else{
            removerVacunaTAGFichaVacunacion(fichaVacunacion->pH, codVacuna);
            removerVacunaTAGFichaVacunacion(fichaVacunacion->sH, codVacuna);
        }
    }
}
bool igualesEstructura(TAGFichaVacunacion a, TAGFichaVacunacion b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    if (a->codVacuna != b->codVacuna) return false;
    return igualesEstructura(a->pH, b->pH) && igualesEstructura(a->sH, b->sH);
}



// bool igualesTAGFichaVacunacion(TAGFichaVacunacion fv1, TAGFichaVacunacion fv2){
//     if(cantidadTAGFichaVacunacion(fv1)!=cantidadTAGFichaVacunacion(fv2))return false;
//     if(fv1 !=NULL ){
//         if(existeVacunaTAGFichaVacunacion(fv2, fv1->codVacuna)){
//             if((igualesTAGFichaVacunacion(fv1->pH, fv2) && igualesTAGFichaVacunacion(fv1->sH, fv2)==true)){
//                 return igualesTAGFichaVacunacion(fv2->pH, fv1) && igualesTAGFichaVacunacion(fv2->sH, fv1);
//             }else return false;
//         }else return false;
//     }
//     return true;

// }

 
 

bool buscarPadre(TAGFichaVacunacion arbol, int codBuscado, int padre, int* padreEncontrado) {
    if (arbol == NULL) return false;
    if (arbol->codVacuna == codBuscado) {
    *padreEncontrado = padre;
    return true;
    }
    return 
    buscarPadre(arbol->pH, codBuscado, arbol->codVacuna, padreEncontrado) ||
    buscarPadre(arbol->sH, codBuscado, padre, padreEncontrado);
}
    
bool verificar(TAGFichaVacunacion origen, TAGFichaVacunacion destino, int padreOrigen) {
    if (origen == NULL) return true;
    int padreDestino = -2;
    if (!buscarPadre(destino, origen->codVacuna, -1, &padreDestino)) return false;
    if (padreDestino != padreOrigen) return false;

    return verificar(origen->pH, destino, origen->codVacuna) &&
    verificar(origen->sH, destino, padreOrigen);
}
/* Debe ejecutar en O(n1 * n2) peor caso, donde n1 es el número de vacunas de fv1 
y n2 es el número de vacunas de fv2. */
bool igualesTAGFichaVacunacion(TAGFichaVacunacion fv1, TAGFichaVacunacion fv2) {
    return verificar(fv1, fv2, -1) && verificar(fv2, fv1, -1);
}
    