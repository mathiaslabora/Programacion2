#include <stdio.h>



struct nodoAG { 
    int dato; 
    nodoAG *pH; 
    nodoAG *sH; 
};
typedef nodoAG * AG;


// int nivel (AG & t, int x){
//     // if (t==NULL)return 0;
//     if (x<t->dato) return 1+nivel(t->pH, x);
//     else if(x>t->dato) return nivel(t->sH, x);
//     else if (x==t->dato) return 1;
//     else return 0;
// }
int nivel (AG & t, int x){
    if (t==NULL)return 0;
    if (x<t->dato) return 1+nivel(t->pH, x);
    else if (x==t->dato) return 1;
    else {
        int ret= nivel(t->pH, x);
        if (ret>0) return 1 + ret;
        else return nivel(t->sH, x);
    } 
}

void imprimirAGOrd(AG arbolAG){
    if (arbolAG!=NULL){
        printf("%d\n", arbolAG->dato);
        imprimirAGOrd(arbolAG->pH);
        imprimirAGOrd(arbolAG->sH);
    }
}

int main(){
    nodoAG n10 = {10, NULL, NULL};
    nodoAG n20 = {20, NULL, NULL};
    nodoAG n30 = {30, NULL, NULL};
    nodoAG n40 = {40, NULL, NULL};
    nodoAG n50 = {50, NULL, NULL};
    nodoAG n60 = {60, NULL, NULL};
    nodoAG n70 = {70, NULL, NULL};
    nodoAG n80 = {80, NULL, NULL};
    nodoAG n90 = {90, NULL, NULL};

    AG t = &n50;

    n50.pH = &n30;
    n50.sH = &n70;
    
    n30.pH = &n20;
    n30.sH = &n40;
    
    n70.pH = &n60;
    n70.sH = &n80;
    
    n80.sH = &n90;

    // Aquí ya podés usar t como el árbol general con 9 nodos
    // Por ejemplo:
    int lvl = nivel(t, 80);
    printf("%d\n", lvl);
    // imprimirAGOrd(t);
    return 0;
}