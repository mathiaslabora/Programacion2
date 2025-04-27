#include "../include/perro.h"
#include "../include/fecha.h"

struct rep_perro {
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
    int id_perro;
    char nombre[MAX_NOMBRE];
    nat edad;
    nat vitalidad;
    char descripcion[MAX_DESCRIPCION];
    TFecha fechaIngreso;
    /****** Fin de parte Parte 4.1 *****/
};

TPerro crearTPerro(int id, const char nombre[MAX_NOMBRE], nat edad, nat vitalidad, const char descripcion[MAX_DESCRIPCION], TFecha fechaIngreso) {
    TPerro perro = new rep_perro;
    perro->id_perro = id;
    strcpy(perro->nombre, nombre);  
    perro->edad = edad;
    perro->vitalidad = vitalidad;
    strcpy(perro->descripcion, descripcion);
    perro->fechaIngreso = fechaIngreso;
    return perro; 
}

void liberarTPerro(TPerro &perro) {
    liberarTFecha(perro->fechaIngreso);
    delete perro; 
    perro = NULL;
}

int idTPerro(TPerro perro) {
    return perro->id_perro; 
}

char* nombreTPerro(TPerro perro) {
    return perro->nombre;
}

nat edadTPerro(TPerro perro) {
    return perro->edad;
}

nat vitalidadTPerro(TPerro perro) {
    return perro->vitalidad; 
}

char* descripcionTPerro(TPerro perro) {
    return perro->descripcion; 
}

TFecha fechaIngresoTPerro(TPerro perro) {
    return perro->fechaIngreso; 
}

void imprimirTPerro(TPerro perro) {
    printf("Perro %d\n", perro->id_perro);
    printf("Nombre: %s\n", perro->nombre);
    printf("Edad: %d\n", perro->edad);
    printf("Descripcion: %s\n", perro->descripcion);
    printf("Fecha de ingreso: ");
    imprimirTFecha(perro->fechaIngreso);
    printf("Vitalidad: %d\n", perro->vitalidad);
}

TPerro copiarTPerro(TPerro perro) {
    TPerro perroCopia = new rep_perro;
    perroCopia->id_perro = perro->id_perro;
    strcpy(perroCopia->nombre, perro->nombre);
    perroCopia->edad = perro->edad;
    perroCopia->vitalidad = perro->vitalidad;
    strcpy(perroCopia->descripcion, perro->descripcion);
    perroCopia->fechaIngreso = copiarTFecha(perro->fechaIngreso);
    return perroCopia;
}

void actualizarEdadTPerro(TPerro &perro, nat nuevaEdad) {
    perro->edad = nuevaEdad;
}

void actualizarVitalidadTPerro(TPerro &perro, nat nuevaVitalidad) {
    perro->vitalidad = nuevaVitalidad;
}
