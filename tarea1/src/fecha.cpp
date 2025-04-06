#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat d;
    nat m;
    nat a;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->d=dia;
    nuevaFecha->m=mes;
    nuevaFecha->a=anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->d, fecha->m, fecha->a);
    /****** Fin de parte Parte 3.5 *****/
}

TFecha copiarTFecha(TFecha fecha) {
    TFecha copia = new rep_fecha;
    copia->d=fecha->d;
    copia->m=fecha->m;
    copia->a=fecha->a;
    return copia;
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/
static bool esBisiesto(nat anio){
    //Retorno sin necesidad de if si es true o no.
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}
static nat diasMes(nat mes, nat anio) {
    nat res = 31;
    if (mes == 2) {
        if (esBisiesto(anio)) {
            res = 29;
        } else {
            res = 28;
        }
    }else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        res = 30;
    }
    return res;
}

void aumentarTFecha(TFecha &fecha, nat dias) {
   fecha->d += dias;
   while (fecha->d > diasMes(fecha->m, fecha->a)) {
       fecha->d -= diasMes(fecha->m, fecha->a);
       fecha->m++; 
       if (fecha->m > 12) {
           fecha->m = 1;
           fecha->a++;
       }
    }
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if (fecha1->a > fecha2->a ||
        (fecha1->a == fecha2->a && fecha1->m > fecha2->m) ||
        (fecha1->a == fecha2->a && fecha1->m == fecha2->m && fecha1->d > fecha2->d)){
        res = 1;
    }else if(fecha1->a == fecha2->a && fecha1->m == fecha2->m &&
        fecha1->d == fecha2->d){
        res = 0;
    }else{
        res = -1;
    };
    /****** Fin de parte Parte 3.10 *****/
    return res;
}
