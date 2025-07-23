#include "../include/lseAdopciones.h"

struct rep_lseadopciones {
	TPersona 	persona;
	TPerro 		perro;
	TFecha 		fecha;
	TLSEAdopciones siguiente;
};

TLSEAdopciones crearTLSEAdopcionesVacia(){
	TLSEAdopciones adopcion = NULL;
	return adopcion;	
}


bool esVaciaTLSEAdopciones(TLSEAdopciones lseAdopciones){
	return lseAdopciones==NULL;
}

void imprimirTLSEAdopciones(TLSEAdopciones lseAdopciones){
	
	if (lseAdopciones!=NULL){
		TLSEAdopciones auxRecorrer = lseAdopciones;
		while (auxRecorrer!=NULL){
		printf("---------------------------\n");
		printf("Adopcion en fecha ");
		imprimirTFecha(auxRecorrer->fecha);
		printf("Adoptante:\n");
		printf("Persona %s %s\n", nombreTPersona(auxRecorrer->persona), apellidoTPersona(auxRecorrer->persona));
		printf("CI: %d\n",ciTPersona(auxRecorrer->persona));
		printf("Adoptado:\n");
		printf("Perro %d\n",idTPerro(auxRecorrer->perro));
		printf("Nombre: %s\n", nombreTPerro(auxRecorrer->perro));
		printf("Fecha de ingreso: ");
		imprimirTFecha(fechaIngresoTPerro(auxRecorrer->perro));
		printf("---------------------------\n");
		auxRecorrer=auxRecorrer->siguiente;
		}
	}
}

void liberarTLSEAdopciones(TLSEAdopciones &lseAdopciones){
	TLSEAdopciones auxRecorrerElim;
	while (lseAdopciones!=NULL){
			liberarTFecha(lseAdopciones->fecha);
			liberarTPerro(lseAdopciones->perro);
			liberarTPersona(lseAdopciones->persona);
			auxRecorrerElim=lseAdopciones;
			lseAdopciones=lseAdopciones->siguiente;
			delete auxRecorrerElim;
			auxRecorrerElim=NULL;
	}		
}

void insertarTLSEAdopciones(TLSEAdopciones &lseAdopciones, TFecha fecha, TPersona persona, TPerro perro){
		TLSEAdopciones auxRecorrer = lseAdopciones;
		TLSEAdopciones nuevo = new rep_lseadopciones;
		if (lseAdopciones == NULL || compararTFechas(fecha, lseAdopciones->fecha) == -1) {
			nuevo->siguiente = lseAdopciones;
			nuevo->fecha=fecha;
			nuevo->perro=perro;
			nuevo->persona=persona;
			lseAdopciones = nuevo;
		}else{
			while (auxRecorrer->siguiente!=NULL && compararTFechas(fecha, auxRecorrer->siguiente->fecha)!=-1){
				auxRecorrer=auxRecorrer->siguiente;
			}
			nuevo->fecha=fecha;
			nuevo->perro=perro;
			nuevo->persona=persona;
			nuevo->siguiente=auxRecorrer->siguiente;
			auxRecorrer->siguiente=nuevo;
		}
}

bool existeAdopcionTLSEAdopciones(TLSEAdopciones lseAdopciones, int ciPersona, int idPerro){
	if(lseAdopciones!=NULL){
		TLSEAdopciones auxExiste = lseAdopciones;
		while (auxExiste!= NULL){
			if(ciTPersona(auxExiste->persona) == ciPersona 
				&& idTPerro(auxExiste->perro) == idPerro) {
				return true;
			}
			auxExiste=auxExiste->siguiente;
		}
	}	
	return false;
}

void removerAdopcionTLSEAdopciones(TLSEAdopciones &lseAdopciones, int ciPersona, int idPerro){
	if (lseAdopciones != NULL) {
        TLSEAdopciones auxAdopRemov = lseAdopciones;
        TLSEAdopciones auxAnterior = NULL; // Inicializar como NULL para el primer nodo


        if (ciTPersona(auxAdopRemov->persona) == ciPersona && idTPerro(auxAdopRemov->perro) == idPerro) {
            liberarTFecha(auxAdopRemov->fecha);
            liberarTPerro(auxAdopRemov->perro);
            liberarTPersona(auxAdopRemov->persona);
            lseAdopciones = auxAdopRemov->siguiente;
            delete auxAdopRemov;
            auxAdopRemov = NULL;
        }else{
        while (auxAdopRemov != NULL &&
			ciTPersona(auxAdopRemov->persona) != ciPersona 
			&& idTPerro(auxAdopRemov->perro) != idPerro) {
            auxAnterior = auxAdopRemov; 
            auxAdopRemov = auxAdopRemov->siguiente;
        }
        if (auxAdopRemov != NULL) {
         	liberarTFecha(auxAdopRemov->fecha);
            liberarTPerro(auxAdopRemov->perro);
            liberarTPersona(auxAdopRemov->persona);
            if (auxAnterior != NULL) {
                auxAnterior->siguiente = auxAdopRemov->siguiente;
            }
            delete auxAdopRemov;
            auxAdopRemov = NULL;
        }
	}
    }
}

