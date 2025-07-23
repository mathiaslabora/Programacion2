#include "../include/colaDePrioridadPerros.h"

// La cola de prioridad debe implementarse con un HEAP. 

// NOTA IMPORTANTE: Para evitar diferencias con las salidas esperadas de los tests: 
// * El filtrado ascendente debe parar cuando se encuentra un elemento igual o más prioritario que el elemento filtrado. 
// * El filtrado descendente debe parar cuando los hijos del elemento filtrado sean igual o menos prioritarios que el. 
// * Si se dan empates de prioridad entre los hijos durante el filtrado descendente y corresponde continuar filtrando, 
// se debe seguir el filtrado hacia la rama izquierda.
struct heapRep {
    TPerro perro;
    int prioridad;
};

struct rep_colaDePrioridadPerros {
    int cantidad;
    int cota;
    heapRep * arrPioridadesPerro;
    int *ids;    
    bool orden;
};

/* El tiempo de ejecución en el peor caso es O(N). */
TColaDePrioridadPerros crearTColaDePrioridadPerros(nat N) {
    TColaDePrioridadPerros nuevo = new rep_colaDePrioridadPerros;
    nuevo->cantidad=0;
    nuevo->cota=N+1;
    nuevo->arrPioridadesPerro = new heapRep[nuevo->cota];
    nuevo->ids=new int[nuevo->cota];
    nuevo->orden=true;
    for(int i = 1; i< nuevo->cota; i++){
        nuevo->ids[i]=0;
    }
    return nuevo;
}

/* El tiempo de ejecución en el peor caso es O(1). */
bool estaVaciaTColaDePrioridadPerros(TColaDePrioridadPerros cp) {
    return cp->cantidad==0;
}

void filtradoAscendente(TColaDePrioridadPerros &cp, int pos) {
       while (pos > 1) {
        bool condicion;
        if (cp->orden) {
            // Heap mínimo: subir si el hijo es menor que el padre
            condicion = cp->arrPioridadesPerro[pos].prioridad < cp->arrPioridadesPerro[pos / 2].prioridad;
        } else {
            // Heap máximo: subir si el hijo es mayor que el padre
            condicion = cp->arrPioridadesPerro[pos].prioridad > cp->arrPioridadesPerro[pos / 2].prioridad;
        }
        if (condicion) {
            // Intercambiar
            heapRep aux = cp->arrPioridadesPerro[pos];
            cp->arrPioridadesPerro[pos] = cp->arrPioridadesPerro[pos / 2];
            cp->arrPioridadesPerro[pos / 2] = aux;

            // Actualizar ids
            int idPerroPos = idTPerro(cp->arrPioridadesPerro[pos].perro);
            int idPerroPadre = idTPerro(cp->arrPioridadesPerro[pos / 2].perro);
            cp->ids[idPerroPos] = cp->arrPioridadesPerro[pos].prioridad;
            cp->ids[idPerroPadre] = cp->arrPioridadesPerro[pos / 2].prioridad;

            pos = pos / 2;
        } else {
            // Si no hay que intercambiar, termina el ciclo
            pos = 1;
        }
    }
}
void filtradoDescendente(TColaDePrioridadPerros &cp, int pos) {
    int hijoIzq = 2 * pos;
    int hijoDer = 2 * pos + 1;
    int mejor = pos;
    if (hijoIzq <= cp->cantidad) {
        if (cp->orden) {
            if (cp->arrPioridadesPerro[hijoIzq].prioridad < cp->arrPioridadesPerro[mejor].prioridad)
                mejor = hijoIzq;
        } else {
            if (cp->arrPioridadesPerro[hijoIzq].prioridad > cp->arrPioridadesPerro[mejor].prioridad)
                mejor = hijoIzq;
        }
    }
    if (hijoDer <= cp->cantidad) {
        if (cp->orden) {
            if (cp->arrPioridadesPerro[hijoDer].prioridad < cp->arrPioridadesPerro[mejor].prioridad)
                mejor = hijoDer;
        } else {
            if (cp->arrPioridadesPerro[hijoDer].prioridad > cp->arrPioridadesPerro[mejor].prioridad)
                mejor = hijoDer;
        }
    }
    if (mejor != pos) {
        heapRep temp = cp->arrPioridadesPerro[pos];
        cp->arrPioridadesPerro[pos] = cp->arrPioridadesPerro[mejor];
        cp->arrPioridadesPerro[mejor] = temp;
        int idPerroPos = idTPerro(cp->arrPioridadesPerro[pos].perro);
        int idPerroMejor = idTPerro(cp->arrPioridadesPerro[mejor].perro);
        cp->ids[idPerroPos] = cp->arrPioridadesPerro[pos].prioridad;
        cp->ids[idPerroMejor] = cp->arrPioridadesPerro[mejor].prioridad;
        filtradoDescendente(cp, mejor);
    }
}
/* El tiempo de ejecución en el peor caso es O(log N) siendp 'N' el parámetro pasado en crearCP. */
void insertarTColaDePrioridadPerros(TColaDePrioridadPerros &cp, TPerro perro) {
    // if (cp->cantidad >= cp->cota) return; 
       cp->cantidad++;
    int i = cp->cantidad;
    cp->arrPioridadesPerro[i].perro = perro;
    cp->arrPioridadesPerro[i].prioridad = vitalidadTPerro(perro);
    cp->ids[idTPerro(perro)] = vitalidadTPerro(perro);
    filtradoAscendente(cp, i);
}

/* El tiempo de ejecución en el peor caso es O(1). */
bool estaTColaDePrioridadPerros(TColaDePrioridadPerros cp, int id) {
    if(id >= 1 && id<cp->cota && cp->ids[id]!=0) {return true;}
    return false;
}

/* El tiempo de ejecución en el peor caso es O(N), siendo 'N' el parámetro
pasado en crearCP. */
void liberarTColaDePrioridadPerros(TColaDePrioridadPerros &cp) {
    if (cp!=NULL){
        for(int i = 1; i<= cp->cantidad; i++){
            liberarTPerro(cp->arrPioridadesPerro[i].perro);
        }
        delete[] cp->arrPioridadesPerro;
        delete[] cp->ids;
        delete cp;
        cp=NULL;
    }
}

/* El tiempo de ejecución en el peor caso es O(1). */
nat prioridadTColaDePrioridadPerros(TColaDePrioridadPerros cp, int id) {
    return cp->ids[id];
}

/* El tiempo de ejecución en el peor caso es O(1). */
TPerro prioritarioTColaDePrioridadPerros(TColaDePrioridadPerros cp) {
    return cp->arrPioridadesPerro[1].perro;
}


/* El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
pasado en crearCP. */
void eliminarPrioritarioTColaDePrioridadPerros(TColaDePrioridadPerros &cp) {
    if (cp != NULL && cp->cantidad > 0) {
    cp->ids[idTPerro(cp->arrPioridadesPerro[1].perro)]=0;
    liberarTPerro(cp->arrPioridadesPerro[1].perro);
    cp->arrPioridadesPerro[1] = cp->arrPioridadesPerro[cp->cantidad];
    cp->cantidad--;
    filtradoDescendente(cp, 1);
    }
}

/* Se pide que el tiempo de ejecución en el peor caso sea O(n*log n), siendo 'n' la cantidad de
elementos de 'cp'. Sin embargo, existe una solución que lo hace en O(n). */
void invertirPrioridadTColaDePrioridadPerros(TColaDePrioridadPerros &cp) {
    cp->orden = !cp->orden;
    if (cp == NULL || cp->cantidad == 0) return;
    for (int i = cp->cantidad / 2; i >= 1; i--) {
        filtradoDescendente(cp, i);
    }
}
