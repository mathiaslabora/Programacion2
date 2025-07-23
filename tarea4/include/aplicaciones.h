/*
  Módulo de definición de 'aplicaciones'.

  El módulo de aplicaciones es para practicar el USO de TADs mediante la resolución de ejercicios usando los TADs desarrollados.
  Durante la implementación sólo se deben utilizar los TADs.
  Nunca se puede acceder a la representación de los datos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

 #ifndef APLICACIONES_H
 #define APLICACIONES_H
 
 #include "pila.h"
 #include "colaPerros.h"
 #include "ldePerros.h"
 #include "conjuntoPerros.h"
 
 // Se desea saber si una pila y una cola tienen exactamente los mismos elementos (ids) y fueron insertados en ellas
 // exactamente en el mismo orden, donde la Pila contiene enteros que representan ids de perros y la Cola contiene elementos
 // de tipo TPerro con su respectivo id. 
 // Al terminar, p y c deben quedar vacías.
 // No se deben hacer comparaciones innecesarias. No se pueden usar funciones auxiliares.
 bool mismosElementos(TPila p, TColaPerros c); 

 // Función que devuelve una pila con la vitalidad de los perros de 'lista' cuya vitalidad es menor estricta que la de cada uno de los siguientes.
 // Es decir, en el resto de la lista no hay ningún perro cuya vitalidad es menor o igual.
 // En la pila resultado los elementos deben estar en orden reverso al que estaban en 'lista'. 
 // Que la pila resultado esté en orden reverso implica que la vitalidad de la cima es mayor que todas las demás.
 // Al final de la ejecución de la función 'lista' debe quedar vacía.
 // No se deben usar estructuras auxiliares ni definir funciones auxiliares.
 // El tiempo de ejecución debe ser O(n) pero caso, siendo 'n' la cantidad de elementos de 'lista'.
 TPila menoresQueElResto(TLDEPerros lista);
 
 // Función que determina si hay un par de ids pertenecientes a "c" tales que su suma es igual a "k"
 // La función es Theta(n) peor caso, siendo "n" la cantidad máxima de elementos de "c"
 bool sumaPares(nat k, TConjuntoPerros c);
 
 #endif  // APLICACIONES_H
 