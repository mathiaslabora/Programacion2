#include "../include/refugio.h"

struct rep_refugio {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TPerro refugiados[MAX_PERROS];
    int tope;
    /****** Fin de parte Parte 5.1 *****/
};

TRefugio crearTRefugio() {
    TRefugio refugio = new rep_refugio;
    refugio->tope = 0;
    return refugio;
}

void liberarTRefugio(TRefugio& refugio) {    
    for (int i = 0; i<= refugio->tope-1; i++)
        liberarTPerro(refugio->refugiados[i]);
    refugio->tope = 0;
    delete refugio;
    refugio = NULL;
}

void desplazarArrUnLugar (TRefugio& refugio, int desde){
    for (int i = refugio->tope - 1; i >= desde; i--) {
        refugio->refugiados[i + 1] = refugio->refugiados[i];
    }
}

void agregarEnTRefugio(TRefugio& refugio, TPerro perro) { 
    if (refugio->tope == 0) {
        refugio->refugiados[0] = perro;
        refugio->tope++;
        return;
    } else if (refugio->tope == MAX_PERROS) {
        return;
    }

    int i = 0;
    while (i < refugio->tope &&
           compararTFechas(fechaIngresoTPerro(refugio->refugiados[i]), fechaIngresoTPerro(perro)) < 0) {
        i++;
    }
    while (i < refugio->tope && 
           compararTFechas(fechaIngresoTPerro(refugio->refugiados[i]), fechaIngresoTPerro(perro)) == 0) {
        i++;
    }
    desplazarArrUnLugar(refugio, i);
    refugio->refugiados[i] = perro;
    refugio->tope++;
}

void imprimirTRefugio(TRefugio refugio) {
    for (int i = 0; i < refugio->tope; i++) {
        imprimirTPerro(refugio->refugiados[i]);
    }
}

bool estaEnTRefugio(TRefugio refugio, int id) {
    for (int i = 0; i < refugio->tope; i++) {
        if (idTPerro(refugio->refugiados[i]) == id) {
            return true;
        }
    }
    return false;
}

TPerro obtenerDeTRefugio(TRefugio refugio, int id) {
    for (int i = 0; i < refugio->tope; i++) {
        if (idTPerro(refugio->refugiados[i]) == id) {
            return refugio->refugiados[i];
        }
    }
    return NULL;
}

bool ingresaronPerrosFechaTRefugio(TRefugio refugio, TFecha fecha) {
    int inicio = 0;
    int fin = refugio->tope - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (compararTFechas(fechaIngresoTPerro(refugio->refugiados[medio]), fecha) == 0) {
            return true;
        } else if (compararTFechas(fechaIngresoTPerro(refugio->refugiados[medio]), fecha) < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return false;
}

void imprimirPerrosFechaTRefugio(TRefugio refugio, TFecha fecha) {
    if (refugio->tope == 0) return;
    for (int i = 0; i <=refugio->tope - 1; i++) {
        if (compararTFechas(fechaIngresoTPerro(refugio->refugiados[i]), fecha) == 0) {
            imprimirTPerro(refugio->refugiados[i]);
        }
    }
}

void removerDeTRefugio(TRefugio& refugio, int id) {
    int i = 0;
    while (i <= refugio->tope && idTPerro(refugio->refugiados[i]) != id) {
        i++;
    }
    if (i == refugio->tope) {
        return;
    }
    liberarTPerro(refugio->refugiados[i]);
    for (int j = i; j < refugio->tope - 1; j++) {
        refugio->refugiados[j] = refugio->refugiados[j + 1];
    }
    refugio->tope--;
}





