#include "../include/refugio.h"

struct rep_refugio {
    TRefugio siguiente;
    TABBPersonas persona;
    TLSEAdopciones adopcion;
    TLDEPerros perro;
    TAGFichaVacunacion ficha;
    TConjuntoPerros conjuntoPerro;
    TConjuntoPerros conjuntoPerrosAdoptados;
    TColaPerros colaPerro;
    TTablaFichaVacunacion tablaFichaV;
};

/* Ejecuta en O(cantEstimada) peor caso. */
TRefugio crearTRefugio(int cantEstimada) {
    TRefugio nuevoRefugio = new rep_refugio;
    nuevoRefugio->siguiente=NULL;
    nuevoRefugio->persona=NULL;
    nuevoRefugio->adopcion=NULL;
    nuevoRefugio->perro=NULL;
    nuevoRefugio->ficha=NULL;
    nuevoRefugio->conjuntoPerro=crearTConjuntoPerros(MAX_PERROS_REFUGIO);
    nuevoRefugio->conjuntoPerrosAdoptados=crearTConjuntoPerros(MAX_PERROS_REFUGIO );
    nuevoRefugio->colaPerro=NULL;
    nuevoRefugio->tablaFichaV=crearTTablaFichaVacunacion(cantEstimada);    
    return nuevoRefugio;
}

void liberarTRefugio(TRefugio &refugio) {
    while (refugio!=NULL){
        liberarTABBPersonas(refugio->persona);
        liberarTLSEAdopciones(refugio->adopcion);
        liberarTLDEPerros(refugio->perro);
        liberarTAGFichaVacunacion(refugio->ficha);
        liberarTConjuntoPerros(refugio->conjuntoPerro);
        liberarTConjuntoPerros(refugio->conjuntoPerrosAdoptados);
        liberarTColaPerros(refugio->colaPerro);
        liberarTTablaFichaVacunacion(refugio->tablaFichaV);
        TRefugio aborrar = refugio;
        refugio = refugio->siguiente;
        delete aborrar;
        aborrar = NULL;
    }
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de vacunas en la ficha. */
void agregarVacunaTRefugio(TRefugio refugio, int codVacunaPadre, int codVacuna){
    if(cantidadTAGFichaVacunacion(refugio->ficha)==0){
        insertarVacunaTAGFichaVacunacion(refugio->ficha, -1, codVacuna);
    }else{
        insertarVacunaTAGFichaVacunacion(refugio->ficha, codVacunaPadre, codVacuna);
    }
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de vacunas en la ficha. */
void imprimirEsquemaVacunacionTRefugio(TRefugio refugio) {
    if(cantidadTAGFichaVacunacion(refugio->ficha)!=0){imprimirTAGFichaVacunacion(refugio->ficha);}
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de personas registradas en el refugio. */
// La persona parámetro no debe compartir memoria con el refugio.
void registrarPersonaTRefugio(TRefugio &refugio, TPersona persona) {
    if(persona!=NULL) {insertarTPersonaTABBPersonas(refugio->persona, copiarTPersona(persona));}
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de personas registradas en el refugio. */
void imprimirPersonasTRefugio(TRefugio refugio) {
    if(refugio!=NULL){
        imprimirTABBPersonas(refugio->persona);
    }
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de perros en el refugio. */
// El perro parámetro no debe compartir memoria con el refugio. 
void ingresarPerroTRefugio(TRefugio &refugio, TPerro perro) {
    if (refugio->colaPerro == NULL) {
        refugio->colaPerro = crearTColaPerros();
    }
    if (refugio->perro == NULL) {
        refugio->perro = crearTLDEPerrosVacia();
    }
    encolarTColaPerros(refugio->colaPerro, copiarTPerro(perro));
    insertarTLDEPerros(refugio->perro, copiarTPerro(perro));
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de perros en la cola de paseos */
void imprimirColaPaseosTRefugio(TRefugio refugio) {
    if(refugio!=NULL){imprimirTColaPerros(refugio->colaPerro);}
}

/* La función ejecuta en O(n) peor caso, donde n es la cantidad de perros en el refugio. */
void imprimirPerrosTRefugio(TRefugio refugio, bool cachorrosPrimero) {
    if(cachorrosPrimero){
        imprimirTLDEPerros(refugio->perro);
    }else{
        imprimirInvertidoTLDEPerros(refugio->perro);
    }
}

/* La función ejecuta en O(cantidad) peor caso. */
void pasearPerrosTRefugio(TRefugio &refugio, nat cantidad) {
    if(cantidad>0 && refugio!=NULL && cantidad <= cantidadTColaPerros(refugio->colaPerro)){
        TColaPerros tempCola = crearTColaPerros();
        for(nat i = 0; i<cantidad;i++){
            printf("Paseando perro: %d %s\n", idTPerro(frenteTColaPerros(refugio->colaPerro)), nombreTPerro(frenteTColaPerros(refugio->colaPerro)));
            encolarTColaPerros(tempCola, copiarTPerro(frenteTColaPerros(refugio->colaPerro)));
            desencolarTColaPerros(refugio->colaPerro);
        }
        for(nat j = 0; j<cantidad;j++){
            encolarTColaPerros(refugio->colaPerro, copiarTPerro(frenteTColaPerros(tempCola)));
            desencolarTColaPerros(tempCola);
        }
        liberarTColaPerros(tempCola);
    }
}

/* La función ejecuta en O(n + m + l) peor caso, donde n es la cantidad de perros
en el refugio, m la cantidad de personas en el refugio y l la cantidad de adopciones. */
// La fecha de la adopción agregada al refugio no comparte memoria con el parámetro. 
void adoptarPerroTRefugio(TRefugio &refugio, int idPerro, int ciPersona, TFecha fecha) {
    if(refugio!=NULL){        
        TColaPerros tempCola = crearTColaPerros();
        nat cantidad = cantidadTColaPerros(refugio->colaPerro);
        TPersona persona = obtenerTPersonaTABBPersonas(refugio->persona, ciPersona);
        TPerro perro;
        for(nat i = 0; i<cantidad;i++){
            if(idTPerro(frenteTColaPerros(refugio->colaPerro))==idPerro){
                perro=copiarTPerro(frenteTColaPerros(refugio->colaPerro));
            }else{
            encolarTColaPerros(tempCola, copiarTPerro(frenteTColaPerros(refugio->colaPerro)));
            }
            desencolarTColaPerros(refugio->colaPerro);
        }
        while (cantidadTColaPerros(tempCola)!=0) {
            encolarTColaPerros(refugio->colaPerro, copiarTPerro(frenteTColaPerros(tempCola)));
            desencolarTColaPerros(tempCola);
        }
        liberarTColaPerros(tempCola);
        
        insertarTConjuntoPerros(refugio->conjuntoPerrosAdoptados, idPerro);
        borrarDeTConjuntoPerros(refugio->conjuntoPerro, idPerro);
        agregarPerroTPersona(persona, perro);
        insertarTLSEAdopciones(refugio->adopcion, copiarTFecha(fecha), copiarTPersona(persona), perro);
    }

}

/* Ejecuta en O(n) peor caso, donde n es la cantidad de adopciones del refugio. */
void imprimirAdopcionesTRefugio(TRefugio refugio) {
    if(refugio!=NULL){
        imprimirTLSEAdopciones(refugio->adopcion);
    }
}

void vacunarPerroTRefugio(TRefugio refugio, int idPerro, int codVacunaPadre, int codVacuna){
    if(refugio==NULL){return;}
    TAGFichaVacunacion ficha = obtenerFichaTTablaFichaVacunacion(refugio->tablaFichaV, idPerro);
    
    if (ficha == NULL) {
        ficha = crearTAGFichaVacunacion();
        insertarVacunaTAGFichaVacunacion(ficha, -1, codVacuna);
        insertarTTablaFichaVacunacion(refugio->tablaFichaV, idPerro, ficha);

    }else{if (codVacunaPadre == -1) {
        return;
    }
    insertarVacunaTAGFichaVacunacion(ficha, codVacunaPadre, codVacuna);
    }
    if(refugio->ficha==NULL){
        refugio->ficha = crearTAGFichaVacunacion();
    }
     if (!existeVacunaTAGFichaVacunacion(refugio->ficha, codVacuna)) {
         agregarVacunaTRefugio(refugio, codVacunaPadre, codVacuna);
    }
    TPerro perro = NULL;
    nat cantidad = cantidadTLDEPerros(refugio->perro);
    bool encontrado = false;
    nat i = 1;

    while (i <= cantidad && !encontrado) {
        TPerro actual = obtenerNesimoTLDEPerros(refugio->perro, i);
        if (actual != NULL && idTPerro(actual) == idPerro) {
            perro = actual;
            encontrado = true;
        }
        i++;
    }
    if (perro != NULL) {
    actualizarVitalidadTPerro(perro, vitalidadTPerro(perro)+1);
    }
}

void imprimirFichaVacunacionPerroTRefugio(TRefugio refugio, int idPerro){
   if(refugio!=NULL){
        TAGFichaVacunacion ficha = obtenerFichaTTablaFichaVacunacion(refugio->tablaFichaV, idPerro);
        imprimirTAGFichaVacunacion(ficha);
    }
}


TColaDePrioridadPerros obtenerPerrosSinVacunacionTRefugio(TRefugio &refugio) {
    // TColaDePrioridadPerros colaPrioridad = crearTColaDePrioridadPerros(5); // capacidad mínima por defecto
    TColaDePrioridadPerros colaPrioridad=NULL;
    if (refugio != NULL && refugio->perro != NULL) {
        nat cantidad = cantidadTLDEPerros(refugio->perro);
        colaPrioridad = crearTColaDePrioridadPerros(cantidad + 4);
        for (nat i = 1; i <= cantidad; i++) {
            TPerro perro = obtenerNesimoTLDEPerros(refugio->perro, i);
            int id = idTPerro(perro);

//            
            if (//!perteneceTConjuntoPerros(refugio->conjuntoPerro, id)&&
                !perteneceTConjuntoPerros(refugio->conjuntoPerrosAdoptados, id)
                ) {
                TAGFichaVacunacion fichaPerro = obtenerFichaTTablaFichaVacunacion(refugio->tablaFichaV, id);

            // printf("ID: %d\n",id);
            // printf(" iguales %d\n", igualesTAGFichaVacunacion(refugio->ficha, fichaPerro) );
            // printf(" pert %d\n", perteneceTConjuntoPerros(refugio->conjuntoPerro,id) );
            // printf("Cantidad fichaperro %d\n", cantidadTAGFichaVacunacion(fichaPerro) );
            // printf("Cantidad ficharefugio %d\n", cantidadTAGFichaVacunacion(refugio->ficha) );

            //     // Ficha incompleta si es NULL o distinta a la ficha modelo del refugio
                if (//fichaPerro == NULL || 
                    //cantidadTAGFichaVacunacion(fichaPerro)!=cantidadTAGFichaVacunacion(refugio->ficha)||
                    !igualesTAGFichaVacunacion(refugio->ficha, fichaPerro)) {
                    insertarTColaDePrioridadPerros(colaPrioridad, copiarTPerro(perro));
                }
            }
        }
    }

    return colaPrioridad;
}
