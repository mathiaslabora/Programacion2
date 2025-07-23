#include "../include/persona.h"


struct perr_adopt {
    TPerro perrosAdopt[MAX_PERROS_PERSONA];
    int tope;
};  
struct rep_persona {
    int ci;
    char nombre[MAX_NOMBRE_PERSONA];
    char apellido[MAX_APELLIDO_PERSONA];
    TFecha fechaNac;
    perr_adopt * arrPerros;
};

TPersona crearTPersona(int ci, const char nombre[MAX_NOMBRE_PERSONA], const char apellido[MAX_APELLIDO_PERSONA], nat diaNac, nat mesNac, nat anioNac){
    TPersona persona = new rep_persona;
    persona -> ci = ci;
    strcpy(persona -> nombre, nombre);
    strcpy(persona -> apellido, apellido);
    TFecha tFechaNac = crearTFecha(diaNac, mesNac, anioNac);
    persona->fechaNac = tFechaNac;
    persona->arrPerros = new perr_adopt; 
    persona->arrPerros->perrosAdopt[0]=NULL;
    persona->arrPerros->tope=0;
    return persona;
}

void imprimirTPersona(TPersona persona){
    printf("Persona %s %s\n", persona->nombre, persona->apellido);
    printf("CI: %d\n", persona->ci);
    printf("Fecha de Nacimiento: ");
    imprimirTFecha(persona->fechaNac);
    printf("Perros adoptados:\n");
    for (int i=0; persona->arrPerros!= NULL 
        && i<= persona->arrPerros->tope-1 
        && persona->arrPerros->perrosAdopt[i]!= NULL ; i++){
        imprimirTPerro(persona->arrPerros->perrosAdopt[i]);
    }
}

void liberarTPersona(TPersona &persona){
    if (persona != NULL) {
        if (persona->fechaNac!=NULL)
            liberarTFecha(persona->fechaNac);
            //Siguiente linea?
    for (int i=0; persona->arrPerros!=NULL 
        // && persona->arrPerros->tope>0
        && i<= persona->arrPerros->tope-1
        && persona->arrPerros->perrosAdopt[i]!=NULL; i++){
        liberarTPerro(persona->arrPerros->perrosAdopt[i]);    
    }
    persona->arrPerros->tope=0;
    delete persona->arrPerros;
    persona->arrPerros=NULL;
    delete persona;
    persona = NULL;
    }
}

int ciTPersona(TPersona persona){
    return persona->ci;
}

char* nombreTPersona(TPersona persona){
    return persona->nombre;
}

char* apellidoTPersona(TPersona persona){
    return persona->apellido;
}

TFecha fechaNacimientoTPersona(TPersona persona){
    return persona->fechaNac;
}

void agregarPerroTPersona(TPersona &persona, TPerro perro){
    if(persona!=NULL && persona->arrPerros!=NULL && persona->arrPerros->tope < MAX_PERROS_PERSONA){
        int insertar=persona->arrPerros->tope;
        persona->arrPerros->perrosAdopt[insertar]=copiarTPerro(perro);
        persona->arrPerros->tope++;
    }
}

bool pertenecePerroTPersona(TPersona persona, int idPerro){
    if (persona != NULL && persona->arrPerros != NULL) {
        for (int i = 0; i<=persona->arrPerros->tope-1;i++){
            if (persona->arrPerros->perrosAdopt[i]!= NULL && idTPerro(persona->arrPerros->perrosAdopt[i])==idPerro)
            return true;
        }
    }   
    return false;
}

int cantidadPerrosTPersona(TPersona persona){
    return persona->arrPerros->tope; 
}

TPersona copiarTPersona(TPersona persona){
    TPersona copia = new rep_persona;
    copia->ci = persona->ci;
    strcpy(copia-> nombre, persona->nombre);
    strcpy(copia ->apellido, persona->apellido);
    copia->fechaNac = copiarTFecha(persona->fechaNac);
    copia->arrPerros = new perr_adopt;
    copia->arrPerros->tope = persona->arrPerros->tope;
    for (int i = 0;i <= persona->arrPerros->tope-1 && persona->arrPerros->perrosAdopt[i]!=NULL ; i++) {
        copia->arrPerros->perrosAdopt[i] = copiarTPerro(persona->arrPerros->perrosAdopt[i]);
    }
    return copia;
}
