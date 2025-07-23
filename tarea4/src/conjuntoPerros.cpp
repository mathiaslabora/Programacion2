#include "../include/conjuntoPerros.h"

struct rep_conjuntoperros{
  int max;
  int cantidad;
  int* arrConjunto;
};

/* Debe ejectuar en O(n) peor caso, siendo n la cantidad máxima de elementos del conjunto. */
TConjuntoPerros crearTConjuntoPerros(int cantMax){
  TConjuntoPerros nuevo = new rep_conjuntoperros;
  nuevo->arrConjunto = new int[cantMax];
  nuevo->max=cantMax;
  nuevo->cantidad=0;
  for (int i=0; i<=nuevo->max-1; i++) nuevo->arrConjunto[i]=0;
  return nuevo;
}

/* Debe ejecutar en O(1) peor caso. */
void insertarTConjuntoPerros(TConjuntoPerros &c, int id){
  if(id<=c->max-1 && c->arrConjunto[id]==0){
    c->arrConjunto[id]=1;
    c->cantidad+=1;
  }
}

/* Debe ejecutar en O(n) peor caso, siendo "n" la cantidad máxima de elementos de "c". */
void imprimirTConjuntoPerros(TConjuntoPerros c){
  int flagEspacio=0;
  for(int i=0; i<=c->max-1; i++){
    if(c->arrConjunto[i]==1){
    if (flagEspacio==1)printf(" ");
    printf("%d",i);
    if (flagEspacio==0) flagEspacio=1;
    }
  }
  printf("\n");
}

/* Debe ejecutar en O(1) peor caso. */
// Luego de la función, el puntero c debe apuntar a NULL.
void liberarTConjuntoPerros(TConjuntoPerros &c){
  if (c==NULL) {return;}
  delete[] c->arrConjunto;
  delete c;
  c=NULL;
}

/* Debe ejecutar en O(1) peor caso. */
bool esVacioTConjuntoPerros(TConjuntoPerros c){
  return c->cantidad==0;
}

/* Debe ejecutar en O(1) peor caso. */
int cardinalTConjuntoPerros(TConjuntoPerros c){
  return c->cantidad;
}

/* Debe ejecutar en O(1) peor caso. */
int cantMaxTConjuntoPerros(TConjuntoPerros c){
  return c->max;
}

/* Debe ejecutar en O(1) peor caso. */
bool perteneceTConjuntoPerros(TConjuntoPerros c, int id){
  // if (c->max>id) return c->arrConjunto[id]==1;
  // return false;
  return id >= 0 && id < c->max && c->arrConjunto[id] == 1;
}

/* Debe ejecutar en O(1) peor caso. */
void borrarDeTConjuntoPerros(TConjuntoPerros &c, int id){
  if(id<=c->max-1 && c->arrConjunto[id]==1){
    c->arrConjunto[id]=0;
    c->cantidad-=1;
  }
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoPerros unionTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2){
  TConjuntoPerros nuevo = crearTConjuntoPerros(c1->max);
  for (int i=0; i<=c1->max-1; i++){
    if(c1->arrConjunto[i]==1||c2->arrConjunto[i]==1){
    insertarTConjuntoPerros(nuevo, i);
    }
  }
  return nuevo;
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoPerros interseccionTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2){
  TConjuntoPerros nuevo = crearTConjuntoPerros(c1->max);
  for (int i=0; i<=c1->max-1; i++){
    if(c1->arrConjunto[i]==1&&c2->arrConjunto[i]==1){
    insertarTConjuntoPerros(nuevo, i);
    }
  }
  return nuevo;
}

/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoPerros diferenciaTConjuntoPerros(TConjuntoPerros c1, TConjuntoPerros c2){
  TConjuntoPerros nuevo = crearTConjuntoPerros(c1->max);
  for (int i=0; i<=c1->max-1; i++){
    if(c1->arrConjunto[i]==1&& c2->arrConjunto[i]==0){
    insertarTConjuntoPerros(nuevo, i);
    }
  }
  return nuevo;
}
