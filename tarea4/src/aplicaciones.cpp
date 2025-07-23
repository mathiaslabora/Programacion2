#include "../include/aplicaciones.h"

bool mismosElementos(TPila p, TColaPerros c) {
    bool iguales = true;
    if (cantidadTPila(p) != cantidadTColaPerros(c)) {
        iguales = false;
    }
    TPila cCopy = crearTPila();
    nat x = cantidadTPila(p);
    for (nat i = 0; i < x && iguales; i++) {
        apilarTPila(cCopy, cimaTPila(p));
        desapilarTPila(p);
    }
    while (cantidadTPila(cCopy) != 0 && cantidadTColaPerros(c) != 0 && iguales) {
        if (cimaTPila(cCopy) != idTPerro(frenteTColaPerros(c))) {
            iguales = false;
        }
        desapilarTPila(cCopy);
        desencolarTColaPerros(c);
    }
    if (cantidadTPila(cCopy) != 0 || cantidadTColaPerros(c) != 0) {
        iguales = false;
    }
    while (cantidadTPila(cCopy) != 0) {
        desapilarTPila(cCopy);
    }
    while (cantidadTColaPerros(c) != 0) {
        desencolarTColaPerros(c);
    }
    liberarTPila(cCopy);
    return iguales;
}

TPila menoresQueElResto(TLDEPerros lista) {
    TPila pilaRet = crearTPila();
    TPerro perro;
    // nat actual=0,
    nat vit=0;
    while(cantidadTLDEPerros(lista)!=0){
        perro=removerPrimeroTLDEPerros(lista);
        vit=vitalidadTPerro(perro);
        liberarTPerro(perro);
        if(cantidadTPila(pilaRet)!=0&&vit<(nat)cimaTPila(pilaRet)){
            // actual=vit;
            while (cantidadTPila(pilaRet)!=0 && vit<=(nat)cimaTPila(pilaRet)){
                desapilarTPila(pilaRet);
            }
            apilarTPila(pilaRet,vit);
        }else if(cantidadTPila(pilaRet)==0 ||vit>(nat)cimaTPila(pilaRet)){
            apilarTPila(pilaRet,vit);
        }
    }
    return pilaRet;
}
// TPila menoresQueElResto(TLDEPerros lista) {
//     TPila pilaRet = crearTPila();
//     TPila pilaAux = crearTPila();
//     TPerro perro;
//     nat actual=0, vit=0;
//     while(cantidadTLDEPerros(lista)!=0){
//         perro=removerUltimoTLDEPerros(lista);
//         vit=vitalidadTPerro(perro);
//         liberarTPerro(perro);
//         if(actual==0 || vit<actual){
//             actual=vit;
//             apilarTPila(pilaAux,vit);
//         }
//     }
//     while(cantidadTPila(pilaAux)!=0){
//         apilarTPila(pilaRet, cimaTPila(pilaAux));
//         desapilarTPila(pilaAux);
//     }
//     liberarTPila(pilaAux);
//     return pilaRet;
// }
 
bool sumaPares(nat k, TConjuntoPerros c) {
    int n = cantMaxTConjuntoPerros(c);
    for (int i = 0; i < n; i++) {
      if (perteneceTConjuntoPerros(c, i)) {
        int aux = k - i;
        if (aux >= 0 && aux < n && perteneceTConjuntoPerros(c, aux)) {
          if (i != aux) return true;
        }
      }
    }
    return false;
}