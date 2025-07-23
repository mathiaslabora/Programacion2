/*
  Módulo principal de la Tarea 4.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#define cmd_es(nom_comando, cmd) (0 == strcmp(nom_comando, cmd))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/agFichaVacunacion.h"
#include "include/refugio.h"
#include "include/aplicaciones.h"
#include "include/tablaFichaVacunacion.h"
#include "include/colaDePrioridadPerros.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

///////////////////////////////
// Funciones main para Fecha //
///////////////////////////////

void leerFecha(TFecha &fecha); // Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void main_crearFecha(TFecha &fecha); // Crea una fecha y la almacena en la variable fecha
void main_liberarFecha(TFecha &fecha); // Libera la memoria de la variable fecha
void main_imprimirFecha(TFecha fecha); // Imprime la fecha almacenada en la variable fecha
void main_copiarFecha(TFecha fecha);
void main_aumentarDias(TFecha &fecha); // Aumenta la fecha almacenada en la variable fecha en la cantidad de días indicada
void main_compararFechas(); // Compara dos fechas leidas de la entrada

////////////////////////////////////
// Funciones main para Personas  //
////////////////////////////////////
void main_crearPersona(TPersona &persona); // Crea una persona y la almacena en la variable 'persona'
void main_imprimirCIPersona(TPersona persona); // Imprime la CI de la persona almacenada en la variable 'persona'
void main_imprimirNombreYApellidoPersona(TPersona persona); // Imprime el nombre y apelldio de la persona almacenada en la variable 'persona'
void main_imprimirPersona(TPersona persona); // Imprime la persona almacenada en la variable 'persona'
void main_imprimirFechaNacimientoPersona(TPersona persona); // Imprime la fecha de nacimiento de la persona almacenada en la variable 'persona'
void main_copiarPersona(TPersona persona); // Prueba de la función copia
void main_liberarPersona(TPersona &persona); // Libera la memoria asociada a la persona guardada en la variable 'persona'
void main_agregarPerroPersona(TPersona persona, TPerro &perro); 
void main_pertenecePerroPersona(TPersona persona);
void main_cantidadPerrosPersona(TPersona persona);

////////////////////////////////////
//   Funciones main testear Perro //
////////////////////////////////////
void main_crearPerro(TPerro &perro, TFecha &fecha);
void main_liberarPerro(TPerro &perro); 
void main_imprimirIdPerro(TPerro perro);
void main_imprimirNombrePerro(TPerro perro); 
void main_imprimirEdadPerro(TPerro perro); 
void main_imprimirDescripcionPerro(TPerro perro); 
void main_imprimirFechaIngresoPerro(TPerro perro); 
void main_imprimirVitalidadPerro(TPerro perro); 
void main_imprimirPerro(TPerro perro); 
void main_copiarPerro(TPerro perro);
void main_actualizarEdadPerro(TPerro &perro); 
void main_actualizarVitalidadPerro(TPerro &perro); 


//////////////////////////////////////////////
//   Funciones main para LSE Adopciones     //
//////////////////////////////////////////////
void main_crearLSEAdopcionesVacia(TLSEAdopciones &listaAdopciones);
void main_insertarLSEAdopciones(TLSEAdopciones &listaAdopciones, TFecha &fecha, TPersona &persona, TPerro &perro);
void main_imprimirLSEAdopciones(TLSEAdopciones listaAdopciones);
void main_liberarLSEAdopciones(TLSEAdopciones &listaAdopciones);
void main_esVaciaLSEAdopciones(TLSEAdopciones listaAdopciones);
void main_existeAdopcionLSEAdopciones(TLSEAdopciones listaAdopciones);
void main_removerAdopcionLSEAdopciones(TLSEAdopciones &listaAdopciones);

//////////////////////////////////////////
//    Funciones main para LDEPerros     //
//////////////////////////////////////////
void main_crearLDEPerrosVacia(TLDEPerros &ldePerros);
void main_insertarLDEPerros(TLDEPerros &ldePerros, TPerro &perro);
void main_imprimirLDEPerros(TLDEPerros ldePerros);
void main_imprimirInvertidoLDEPerros(TLDEPerros ldePerros);
void main_cantidadLDEPerros(TLDEPerros ldePerros);
void main_obtenerPrimeroLDEPerros(TLDEPerros ldePerros);
void main_obtenerUltimoLDEPerros(TLDEPerros ldePerros);
void main_obtenerNesimoLDEPerros(TLDEPerros ldePerros);
void main_existePerroLDEPerros(TLDEPerros ldePerros);
void main_removerPerroLDEPerros(TLDEPerros ldePerros);
void main_liberarLDEPerros(TLDEPerros &ldePerros);
void main_removerPrimeroLDEPerros(TLDEPerros &ldePerros);
void main_removerUltimoLDEPerros(TLDEPerros &ldePerros);

//////////////////////////////////////
// Funciones main para ABB Personas //
//////////////////////////////////////
void main_crearABBPersonasVacio(TABBPersonas &abbPersonas); 
void main_insertarPersonaABBPersonas(TABBPersonas &abbPersonas, TPersona &persona);
void main_imprimirABBPersonas(TABBPersonas abbPersonas); 
void main_existePersonaABBPersonas(TABBPersonas abbPersonas);
void main_obtenerPersonaABBPersonas(TABBPersonas abbPersonas);
void main_alturaABBPersonas(TABBPersonas abbPersonas);
void main_maxCIPersonaABBPersonas(TABBPersonas abbPersonas);
void main_cantidadABBPersonas(TABBPersonas abbPersonas);
void main_obtenerNesimaPersonaABBPersonas(TABBPersonas gruabbPersonaspo);
void main_removerPersonaABBPersonas(TABBPersonas &abbPersonas);
void main_liberarABBPersonas(TABBPersonas &abbPersonas);
void main_filtradoPorFechaDeNacimientoABBPersonas(TABBPersonas abbPersonas);
void main_alturaABBPersonasTiempo();
void main_obtenerExistePersonaABBPersonasTiempo();

//////////////////////////////////////
// Funciones main para Pila         //
//////////////////////////////////////
void main_crearPila(TPila &pila); 
void main_apilarPila(TPila &pila);
void main_desapilarPila(TPila &Pila); 
void main_cimaPila(TPila pila);
void main_cantidadPila(TPila Pila);
void main_imprimirPila(TPila Pila);
void main_liberarPila(TPila &Pila);

///////////////////////////////////////////
// Funciones main para AGFichaVacunacion //
///////////////////////////////////////////
void main_crearAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion); 
void main_insertarVacunaAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion);
void main_imprimirAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion); 
void main_liberarAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion);
void main_existeVacunaAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion);
void main_alturaAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion);
void main_cantidadAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion); 
void main_removerVacunaAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion);
void main_igualesAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion); 
 
///////////////////////////////////////////
//   Funciones main para Cola Perros     //
///////////////////////////////////////////
void main_crearColaPerros(TColaPerros &colaPerros); 
void main_encolarColaPerros(TColaPerros &colaPerros, TPerro &perro);
void main_desencolarColaPerros(TColaPerros &colaPerros);
void main_frenteColaPerros(TColaPerros colaPerros);
void main_cantidadColaPerros(TColaPerros colaPerros);
void main_imprimirColaPerros(TColaPerros colaPerros);
void main_liberarColaPerros(TColaPerros &colaPerros);

///////////////////////////////////////////
//  Funciones main para Conjunto Perros  //
///////////////////////////////////////////
void main_crearConjuntoPerros(TConjuntoPerros &conjuntoPerros); 
void main_esVacioConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_insertarConjuntoPerros(TConjuntoPerros &conjuntoPerros); 
void main_borrarDeConjuntoPerros(TConjuntoPerros &conjuntoPerros);
void main_perteneceConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_cardinalConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_cantMaxConjuntoPerros(TConjuntoPerros conjuntoPerros); 
void main_imprimirConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_liberarConjuntoPerros(TConjuntoPerros &conjuntoPerros); 
void main_unionConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_interseccionConjuntoPerros(TConjuntoPerros conjuntoPerros);
void main_diferenciaConjuntoPerros(TConjuntoPerros conjuntoPerros);

///////////////////////////////////////////
//    Funciones main para Aplicaciones   //
///////////////////////////////////////////

void main_mismosElementos(TPila p, TColaPerros c); 
void main_menoresQueElResto(TLDEPerros l); 
void main_sumaPares(TConjuntoPerros c); 

///////////////////////////////////////////////
//Funciones main para colaDePrioridadPerros  //
//////////////////////////////////////////////

void main_crearCP(TColaDePrioridadPerros &cpPerros); 
void main_invertirPrioridadCP(TColaDePrioridadPerros &cpPerros);
void main_liberarCP(TColaDePrioridadPerros &cpPerros);
void main_insertarEnCP(TColaDePrioridadPerros &cpPerros, TPerro &perro);
void main_esVaciaCP(TColaDePrioridadPerros cpPerros);
void main_prioritarioCP(TColaDePrioridadPerros cpPerros);
void main_eliminarPrioritarioCP(TColaDePrioridadPerros &cpPerros);
void main_estaEnCP(TColaDePrioridadPerros cpPerros);
void main_prioridadEnCP(TColaDePrioridadPerros cpPerros);
void main_CPTiempo();

/////////////////////////////////////////////////////////////
//   Funciones main para Tabla de Fichas de Vacunación     //
/////////////////////////////////////////////////////////////
void main_crearTabla(TTablaFichaVacunacion &tablaFichaVacunacion); 
void main_insertarEnTabla(TTablaFichaVacunacion &tablaFichaVacunacion, TAGFichaVacunacion &ficha);
void main_eliminarDeTabla(TTablaFichaVacunacion &tablaFichaVacunacion);
void main_perteneceATabla(TTablaFichaVacunacion tablaFichaVacunacion);
void main_obtenerDeTabla(TTablaFichaVacunacion tablaFichaVacunacion);
void main_liberarTabla(TTablaFichaVacunacion &tablaFichaVacunacion); 
void main_imprimirTabla(TTablaFichaVacunacion tablaFichaVacunacion);

///////////////////////////////////////////
//      Funciones main para Refugio      //
///////////////////////////////////////////

void main_crearRefugio(TRefugio &refugio);
void main_registrarPersonaRefugio(TRefugio &refugio, TPersona &persona);
void main_ingresarPerroRefugio(TRefugio &refugio, TPerro &perro);
void main_agregarVacunaRefugio(TRefugio &refugio);
void main_imprimirEsquemaVacunacionRefugio(TRefugio refugio);
void main_adoptarPerroRefugio(TRefugio &refugio, TFecha &fecha);
void main_pasearPerrosRefugio(TRefugio &refugio);
void main_imprimirColaPaseosRefugio(TRefugio refugio);
void main_imprimirPersonasRefugio(TRefugio refugio);
void main_imprimirPerrosRefugio(TRefugio refugio);
void main_imprimirAdopcionesRefugio(TRefugio refugio);
void main_imprimirFichaVacunacionPerroRefugio(TRefugio refugio);
void main_vacunarPerroRefugio(TRefugio &refugio);
void main_obtenerPerrosSinVacunacionRefugio(TRefugio refugio);
void main_liberarRefugio(TRefugio &refugio);

 
// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TPersona persona = NULL;
    TPerro perro = NULL;

    TABBPersonas abbPersonas = NULL;
    TLSEAdopciones listaAdopciones = NULL;
    TLDEPerros ldePerros = NULL;

    TAGFichaVacunacion fichaVacunacion = NULL;
    TColaPerros colaPerros = NULL;
    TConjuntoPerros conjuntoPerros = NULL;
    TPila pila = NULL;

    TColaDePrioridadPerros cpPerros = NULL; 
    TTablaFichaVacunacion tablaFichaVacunacion = NULL; 
    TRefugio refugio = NULL;
    
    char restoLinea[MAX_LINEA + 1];
    char cmd[MAX_PALABRA];

    int cont_comandos = 0;
    bool seguir = true;
    while (seguir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%u> ", cont_comandos);

        // leer el comando en la variable cmd
        leerChars(cmd);

        // procesar el comando
        if (cmd_es("Fin", cmd)) {  // Termina el programa
            seguir = false;
            printf("Fin.\n");

        } else if (cmd_es("#", cmd)) {  // Imprime el comentario luego del #
            leerRestoLinea(restoLinea);
            printf("# %s.\n", restoLinea);

            ///////////////////////////////////
            /* Funciones para testear fecha */
            ///////////////////////////////////

        } else if (cmd_es("crearFecha", cmd)) {  
            main_crearFecha(fecha);
        } else if (cmd_es("imprimirFecha", cmd)) {  
            main_imprimirFecha(fecha);
        } else if (cmd_es("liberarFecha", cmd)) {  
            main_liberarFecha(fecha);
        } else if (cmd_es("aumentarDias", cmd)) {  
            main_aumentarDias(fecha);
        } else if (cmd_es("compararFechas", cmd)) {  
            main_compararFechas();

        } else if (cmd_es("crearPerro", cmd)) {  
            main_crearPerro(perro, fecha);
        } else if (cmd_es("liberarPerro", cmd)) { 
            main_liberarPerro(perro);
        } else if (cmd_es("imprimirIdPerro", cmd)) { 
            main_imprimirIdPerro(perro);
        } else if (cmd_es("imprimirNombrePerro", cmd)) {
            main_imprimirNombrePerro(perro); 
        } else if (cmd_es("imprimirEdadPerro", cmd)) { 
            main_imprimirEdadPerro(perro); 
        } else if (cmd_es("imprimirDescripcionPerro", cmd)) {
            main_imprimirDescripcionPerro(perro);
        } else if (cmd_es("imprimirFechaIngresoPerro", cmd)) {
            main_imprimirFechaIngresoPerro(perro); 
        } else if (cmd_es("imprimirVitalidadPerro", cmd)) {
            main_imprimirVitalidadPerro(perro); 
        } else if (cmd_es("imprimirPerro", cmd)) { 
            main_imprimirPerro(perro); 
        } else if (cmd_es("actualizarEdadPerro", cmd)) { 
            main_actualizarEdadPerro(perro);
        } else if (cmd_es("actualizarVitalidadPerro", cmd)) { 
            main_actualizarVitalidadPerro(perro);

            //////////////////////////////////////
            /* Funciones para testear persona */
            //////////////////////////////////////

        } else if (cmd_es("crearPersona", cmd)) {  
            main_crearPersona(persona);
        } else if (cmd_es("imprimirCIPersona",cmd)){
            main_imprimirCIPersona(persona);
        } else if (cmd_es("imprimirNombreYApellidoPersona", cmd)){     
            main_imprimirNombreYApellidoPersona(persona);
        } else if (cmd_es("imprimirFechaNacimientoPersona", cmd)){     
            main_imprimirFechaNacimientoPersona(persona);
        } else if (cmd_es("imprimirPersona", cmd)) { 
            main_imprimirPersona(persona);
        } else if (cmd_es("copiarPersona",cmd)){
            main_copiarPersona(persona);
        } else if (cmd_es("agregarPerroPersona", cmd)){     
            main_agregarPerroPersona(persona, perro);
        } else if (cmd_es("pertenecePerroPersona", cmd)) { 
            main_pertenecePerroPersona(persona);
        } else if (cmd_es("cantidadPerrosPersona",cmd)){
            main_cantidadPerrosPersona(persona);
        } else if (cmd_es("liberarPersona", cmd)) {  
            main_liberarPersona(persona);        
          
            
            //////////////////////////////////////////////
            //   Funciones main para LSE Adopciones     //
            //////////////////////////////////////////////
        } else if (cmd_es("crearLSEAdopcionesVacia", cmd)) {  
            main_crearLSEAdopcionesVacia(listaAdopciones);
        } else if (cmd_es("insertarLSEAdopciones", cmd)) {  
            main_insertarLSEAdopciones(listaAdopciones, fecha, persona, perro);
        } else if (cmd_es("imprimirLSEAdopciones", cmd)) {  
            main_imprimirLSEAdopciones(listaAdopciones);
        } else if (cmd_es("liberarLSEAdopciones", cmd)) {  
            main_liberarLSEAdopciones(listaAdopciones);
        } else if (cmd_es("esVaciaLSEAdopciones", cmd)) {  
            main_esVaciaLSEAdopciones(listaAdopciones);
        } else if (cmd_es("existeAdopcionLSEAdopciones", cmd)){ 
            main_existeAdopcionLSEAdopciones(listaAdopciones);
        } else if (cmd_es("removerAdopcionLSEAdopciones", cmd)) {  
            main_removerAdopcionLSEAdopciones(listaAdopciones);


            /////////////////////////////////////////
            // Funciones para testear abb personas //
            /////////////////////////////////////////
        } else if (cmd_es("crearABBPersonasVacio", cmd)) {  
            main_crearABBPersonasVacio(abbPersonas);
        } else if (cmd_es("insertarPersonaABBPersonas", cmd)) {  
            main_insertarPersonaABBPersonas(abbPersonas, persona);
        } else if (cmd_es("imprimirPersonaABB", cmd)) { 
            main_imprimirABBPersonas(abbPersonas);
        } else if (cmd_es("existePersonaABBPersonas", cmd)) { 
            main_existePersonaABBPersonas(abbPersonas);
        } else if (cmd_es("obtenerPersonaABBPersonas", cmd)) { 
            main_obtenerPersonaABBPersonas(abbPersonas);
        } else if (cmd_es("alturaABBPersonas", cmd)) { 
            main_alturaABBPersonas(abbPersonas);
        } else if (cmd_es("maxCIPersonaABBPersonas", cmd)) { 
            main_maxCIPersonaABBPersonas(abbPersonas);
        } else if (cmd_es("cantidadABBPersonas", cmd)) { 
            main_cantidadABBPersonas(abbPersonas);
        } else if (cmd_es("obtenerNesimaPersonaABBPersonas", cmd)) { 
            main_obtenerNesimaPersonaABBPersonas(abbPersonas);
        } else if (cmd_es("removerPersonaABBPersonas", cmd)) { 
            main_removerPersonaABBPersonas(abbPersonas);
        } else if (cmd_es("liberarABBPersonas", cmd)) { 
            main_liberarABBPersonas(abbPersonas);
        } else if (cmd_es("filtradoPorFechaDeNacimientoABBPersonas", cmd)) { 
            main_filtradoPorFechaDeNacimientoABBPersonas(abbPersonas);
        } else if (cmd_es("alturaABBPersonasTiempo", cmd)) { 
            main_alturaABBPersonasTiempo();
        } else if (cmd_es("obtenerExistePersonaABBPersonasTiempo", cmd)) { 
            main_obtenerExistePersonaABBPersonasTiempo();



            //////////////////////////////////////////////
            // Funciones para testear LDE Perros  //
            //////////////////////////////////////////////
        } else if (cmd_es("crearLDEPerrosVacia", cmd)) { 
            main_crearLDEPerrosVacia(ldePerros);
        } else if (cmd_es("insertarLDEPerros", cmd)) { 
            main_insertarLDEPerros(ldePerros, perro);
        } else if (cmd_es("imprimirLDEPerros", cmd)) { 
            main_imprimirLDEPerros(ldePerros);
        } else if (cmd_es("imprimirInvertidoLDEPerros", cmd)) { 
            main_imprimirInvertidoLDEPerros(ldePerros);
        } else if (cmd_es("cantidadLDEPerros", cmd)) { 
            main_cantidadLDEPerros(ldePerros);
        } else if (cmd_es("obtenerPrimeroLDEPerros", cmd)) { 
            main_obtenerPrimeroLDEPerros(ldePerros);
        } else if (cmd_es("obtenerUltimoLDEPerros", cmd)) { 
            main_obtenerUltimoLDEPerros(ldePerros);
        } else if (cmd_es("obtenerNesimoLDEPerros", cmd)) { 
            main_obtenerNesimoLDEPerros(ldePerros);
        } else if (cmd_es("existePerroLDEPerros", cmd)) { 
            main_existePerroLDEPerros(ldePerros);
        } else if (cmd_es("removerPerroLDEPerros", cmd)) { 
            main_removerPerroLDEPerros(ldePerros);
        } else if (cmd_es("liberarLDEPerros", cmd)) { 
            main_liberarLDEPerros(ldePerros);
        } else if (cmd_es("removerPrimeroLDEPerros", cmd)) {
            main_removerPrimeroLDEPerros(ldePerros);
        } else if (cmd_es("removerUltimoLDEPerros", cmd)) {
            main_removerUltimoLDEPerros(ldePerros);

            //////////////////////////////////////
            // Funciones main para Pila         //
            //////////////////////////////////////
        } else if (cmd_es("crearPila", cmd)) { 
            main_crearPila(pila);
        } else if (cmd_es("apilarPila", cmd)) { 
            main_apilarPila(pila);
        } else if (cmd_es("desapilarPila", cmd)) { 
            main_desapilarPila(pila);
        } else if (cmd_es("cimaPila", cmd)) {
            main_cimaPila(pila);
        } else if (cmd_es("cantidadPila", cmd)) { 
            main_cantidadPila(pila);
        } else if (cmd_es("imprimirPila", cmd)) { 
            main_imprimirPila(pila);
        } else if (cmd_es("liberarPila", cmd)) { 
            main_liberarPila(pila);
        
            ///////////////////////////////////////////
            // Funciones main para AGFichaVacunacion //
            ///////////////////////////////////////////
        } else if (cmd_es("crearAGFichaVacunacion", cmd)) { 
            main_crearAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("insertarVacunaAGFichaVacunacion", cmd)) { 
            main_insertarVacunaAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("imprimirAGFichaVacunacion", cmd)) { 
            main_imprimirAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("liberarAGFichaVacunacion", cmd)) { 
            main_liberarAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("existeVacunaAGFichaVacunacion", cmd)) { 
            main_existeVacunaAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("alturaAGFichaVacunacion", cmd)) { 
            main_alturaAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("cantidadAGFichaVacunacion", cmd)) { 
            main_cantidadAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("removerVacunaAGFichaVacunacion", cmd)) { 
            main_removerVacunaAGFichaVacunacion(fichaVacunacion);
        } else if (cmd_es("igualesAGFichaVacunacion", cmd)) { 
            main_igualesAGFichaVacunacion(fichaVacunacion);

        
            ///////////////////////////////////////////
            //   Funciones main para Cola Perros     //
            ///////////////////////////////////////////
        } else if (cmd_es("crearColaPerros", cmd)) { 
            main_crearColaPerros(colaPerros);
        } else if (cmd_es("encolarColaPerros", cmd)) { 
            main_encolarColaPerros(colaPerros, perro);
        } else if (cmd_es("desencolarColaPerros", cmd)) { 
            main_desencolarColaPerros(colaPerros);
        } else if (cmd_es("frenteColaPerros", cmd)) {
            main_frenteColaPerros(colaPerros);
        } else if (cmd_es("cantidadColaPerros", cmd)) { 
            main_cantidadColaPerros(colaPerros);
        } else if (cmd_es("imprimirColaPerros", cmd)) { 
            main_imprimirColaPerros(colaPerros);
        } else if (cmd_es("liberarColaPerros", cmd)) { 
            main_liberarColaPerros(colaPerros);        

            
            ///////////////////////////////////////////
            //  Funciones main para Conjunto Perros  //
            ///////////////////////////////////////////
        } else if (cmd_es("crearConjuntoPerros", cmd)) { 
            main_crearConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("esVacioConjuntoPerros", cmd)) { 
            main_esVacioConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("insertarConjuntoPerros", cmd)) { 
            main_insertarConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("borrarDeConjuntoPerros", cmd)) { 
            main_borrarDeConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("perteneceConjuntoPerros", cmd)) { 
            main_perteneceConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("cardinalConjuntoPerros", cmd)) { 
            main_cardinalConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("cantMaxConjuntoPerros", cmd)) { 
            main_cantMaxConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("imprimirConjuntoPerros", cmd)) { 
            main_imprimirConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("liberarConjuntoPerros", cmd)) { 
            main_liberarConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("unionConjuntoPerros", cmd)) { 
            main_unionConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("interseccionConjuntoPerros", cmd)) { 
            main_interseccionConjuntoPerros(conjuntoPerros);
        } else if (cmd_es("diferenciaConjuntoPerros", cmd)) { 
            main_diferenciaConjuntoPerros(conjuntoPerros);
            ///////////////////////////////////////////
            //   Funciones main para Aplicaciones    //
            ///////////////////////////////////////////
        } else if (cmd_es("mismosElementos", cmd)) {
            main_mismosElementos(pila, colaPerros);
        } else if (cmd_es("menoresQueElResto", cmd)) {
            main_menoresQueElResto(ldePerros);
        } else if (cmd_es("sumaPares", cmd)) {
            main_sumaPares(conjuntoPerros);
            ///////////////////////////////////////////
            //      Funciones main para CP      //
            ///////////////////////////////////////////
        } else if(cmd_es("crearCP", cmd)) {
            main_crearCP(cpPerros);
        } else if(cmd_es("invertirPrioCP", cmd)) {
            main_invertirPrioridadCP(cpPerros);
        } else if(cmd_es("liberarCP", cmd)) {
            main_liberarCP(cpPerros);
        } else if(cmd_es("insertarEnCP", cmd)) {
            main_insertarEnCP(cpPerros, perro);
        } else if(cmd_es("esVaciaCP", cmd)) {
            main_esVaciaCP(cpPerros);
        } else if(cmd_es("prioritarioCP", cmd)) {
            main_prioritarioCP(cpPerros);
        } else if(cmd_es("eliminarPrioritarioCP", cmd)) {
            main_eliminarPrioritarioCP(cpPerros);
        } else if(cmd_es("estaEnCP", cmd)) {
            main_estaEnCP(cpPerros);
        } else if(cmd_es("prioridadEnCP", cmd)) {
            main_prioridadEnCP(cpPerros);
        } else if (cmd_es("CPTiempo", cmd)) {
            main_CPTiempo();
            //////////////////////////////////////////////////////////
            //   Funciones main para Tabla Fichas de Vacunación     //
            //////////////////////////////////////////////////////////
        } else if(cmd_es("crearTabla", cmd)) {
            main_crearTabla(tablaFichaVacunacion);
        } else if(cmd_es("insertarEnTabla", cmd)) {
            main_insertarEnTabla(tablaFichaVacunacion, fichaVacunacion);
        } else if(cmd_es("eliminarDeTabla", cmd)) {
            main_eliminarDeTabla(tablaFichaVacunacion);
        } else if(cmd_es("perteneceATabla", cmd)) {
            main_perteneceATabla(tablaFichaVacunacion);
        } else if(cmd_es("obtenerDeTabla", cmd)) {
            main_obtenerDeTabla(tablaFichaVacunacion);
        } else if(cmd_es("liberarTabla", cmd)) {
            main_liberarTabla(tablaFichaVacunacion);
        } else if(cmd_es("imprimirTabla", cmd)) {
            main_imprimirTabla(tablaFichaVacunacion);

            /////////////////////////////////////////
            //     Funciones main para Refugio      //
            /////////////////////////////////////////
        } else if (cmd_es("crearRefugio", cmd)) { 
            main_crearRefugio(refugio);
        } else if (cmd_es("registrarPersonaRefugio", cmd)) { 
            main_registrarPersonaRefugio(refugio, persona);
        } else if (cmd_es("ingresarPerroRefugio", cmd)) { 
            main_ingresarPerroRefugio(refugio, perro);
        } else if (cmd_es("agregarVacunaRefugio", cmd)) {
            main_agregarVacunaRefugio(refugio);
        } else if (cmd_es("imprimirEsquemaVacunacionRefugio", cmd)) {
            main_imprimirEsquemaVacunacionRefugio(refugio);
        } else if (cmd_es("adoptarPerroRefugio", cmd)) { 
            main_adoptarPerroRefugio(refugio, fecha);
        } else if (cmd_es("pasearPerrosRefugio", cmd)) { 
            main_pasearPerrosRefugio(refugio);
        } else if (cmd_es("imprimirColaPaseosRefugio", cmd)) { 
            main_imprimirColaPaseosRefugio(refugio);
        } else if (cmd_es("imprimirPersonasRefugio", cmd)) { 
            main_imprimirPersonasRefugio(refugio);
        } else if (cmd_es("imprimirPerrosRefugio", cmd)) { 
            main_imprimirPerrosRefugio(refugio);
        } else if (cmd_es("imprimirAdopcionesRefugio", cmd)) { 
            main_imprimirAdopcionesRefugio(refugio);
        } else if (cmd_es("imprimirFichaVacunacionPerroRefugio", cmd)) { 
            main_imprimirFichaVacunacionPerroRefugio(refugio);
        } else if (cmd_es("vacunarPerroRefugio", cmd)) { 
            main_vacunarPerroRefugio(refugio);
        } else if (cmd_es("obtenerPerrosSinVacunacionRefugio", cmd)) { 
            main_obtenerPerrosSinVacunacionRefugio(refugio);
        } else if (cmd_es("liberarRefugio", cmd)) {
            main_liberarRefugio(refugio);
        
        } else {
            printf("Comando no reconocido.\n");  // Comando no reconocido
        }  
        fgets(restoLinea, MAX_LINEA + 1, stdin);
    }  // while

    return 0;
}  // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha) {
    nat *componentes = new nat[3];
    scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
    fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
    delete[] componentes;
}

void main_crearFecha(TFecha &fecha) {
    assert(fecha == NULL);
    leerFecha(fecha);
    printf("Fecha creada en forma exitosa.\n");
}

void main_liberarFecha(TFecha &fecha) {
    assert(fecha != NULL);
    liberarTFecha(fecha);
    printf("Fecha liberada en forma exitosa.\n");
}

void main_imprimirFecha(TFecha fecha) {
    assert(fecha != NULL);
    imprimirTFecha(fecha);
}

void main_aumentarDias(TFecha &fecha) {
    assert(fecha != NULL);
    nat cantDias = leerNat();
    aumentarTFecha(fecha, cantDias);
    printf("La nueva fecha aplazada %d dias es: \n", cantDias);
    imprimirTFecha(fecha);
}

void main_compararFechas() {
    TFecha fecha1 = NULL, fecha2 = NULL;
    leerFecha(fecha1);
    leerFecha(fecha2);
    int comp = compararTFechas(fecha1, fecha2);
    if (comp == 0) {
        printf("Las fechas son iguales. \n");
    } else if (comp == 1) {
        printf("La primera fecha es posterior a la segunda. \n");
    } else
        printf("La primera fecha es anterior a la segunda. \n");
    liberarTFecha(fecha1);
    liberarTFecha(fecha2);
}


///////////////////////////////////
//   Funciones main para Perros  //
///////////////////////////////////

void main_crearPerro(TPerro &perro, TFecha &fecha) {
    assert((perro == NULL) && (fecha != NULL));
    int id = leerNat(); 
    char nombre[100]; 
    leerChars(nombre); 
    nat edad = leerNat(); 
    nat vitalidad = leerNat(); 
    char desc[100]; 
    leerRestoLinea(desc);
    perro = crearTPerro(id, nombre, edad, vitalidad, desc, fecha);
    fecha = NULL;
}

void main_liberarPerro(TPerro &perro) {
    assert(perro!=NULL); 
    liberarTPerro(perro); 
}

void main_imprimirIdPerro(TPerro perro) {
    assert(perro != NULL);
    printf("El id del perro es: %d\n", idTPerro(perro));
}

void main_imprimirNombrePerro(TPerro perro) {
    assert(perro != NULL);
    printf("El nombre del perro es: %s\n", nombreTPerro(perro));
}

void main_imprimirEdadPerro(TPerro perro) {
    assert(perro != NULL);
    printf("La edad del perro es: %d\n", edadTPerro(perro));
}
void main_imprimirDescripcionPerro(TPerro perro) {
    assert(perro != NULL);
    printf("La descripcion del perro es: %s\n", descripcionTPerro(perro));
}

void main_imprimirFechaIngresoPerro(TPerro perro) {
    assert(perro != NULL); 
    TFecha fechaIngreso = fechaIngresoTPerro(perro); 
    assert(fechaIngreso != NULL); 
    printf("La fecha de ingreso del perro es: ");
    imprimirTFecha(fechaIngreso);
}

void main_imprimirVitalidadPerro(TPerro perro) {
    assert(perro != NULL);
    printf("La vitalidad del perro es: %d\n", vitalidadTPerro(perro));   
}

void main_imprimirPerro(TPerro perro) {
    assert(perro != NULL); 
    imprimirTPerro(perro); 
} 

void main_actualizarEdadPerro(TPerro &perro) {
    assert(perro!=NULL); 
    nat nuevaEdad = leerNat(); 
    actualizarEdadTPerro(perro, nuevaEdad); 
}

void main_actualizarVitalidadPerro(TPerro &perro) {
    assert(perro!=NULL); 
    nat nuevaVit = leerNat(); 
    actualizarVitalidadTPerro(perro, nuevaVit); 
}

///////////////////////////////////
/* Funciones main para Persona */
///////////////////////////////////

void main_crearPersona(TPersona &persona){
    assert(persona == NULL);
    int ci = leerInt();
    char nombre[MAX_NOMBRE_PERSONA];
    leerChars(nombre);
    char apellido[MAX_APELLIDO_PERSONA];
    leerChars(apellido);
    nat dia = leerNat();
    nat mes = leerNat();
    nat anio = leerNat();

    persona = crearTPersona(ci, nombre, apellido, dia, mes, anio);
}

void main_imprimirCIPersona(TPersona persona) {
    assert(persona != NULL);
    printf("La CI de la persona es: %d\n", ciTPersona(persona));
}

void main_imprimirNombreYApellidoPersona(TPersona persona){
    assert(persona != NULL);
    printf("El nombre de la persona es: %s\n", nombreTPersona(persona));
    printf("El apellido de la persona es: %s\n", apellidoTPersona(persona));
}

void main_imprimirFechaNacimientoPersona(TPersona persona){
    assert(persona != NULL);
    TFecha fecha = fechaNacimientoTPersona(persona);
    printf("La fecha de nacimiento de la persona es: ");
    imprimirTFecha(fecha);
}

void main_imprimirPersona(TPersona persona) {
    assert(persona != NULL);
    imprimirTPersona(persona);
}

void main_copiarPersona(TPersona persona){
    TPersona personaCopia = copiarTPersona(persona);
    printf("Persona copiada. Datos de la copia:\n");
    imprimirTPersona(personaCopia);

    liberarTPersona(personaCopia);
    personaCopia = NULL;
}

void main_agregarPerroPersona(TPersona persona, TPerro &perro){
    assert(persona != NULL);
    assert(perro != NULL);
    agregarPerroTPersona(persona, perro);
}

void main_pertenecePerroPersona(TPersona persona){
    assert(persona != NULL);
    int id = leerInt();
    bool existe = pertenecePerroTPersona(persona, id);
    if (existe){
        printf("El perro con id %d pertenece a la persona.\n", id);
    } else {
        printf("El perro con id %d NO pertenece a la persona.\n", id);
    }
}
            
void main_cantidadPerrosPersona(TPersona persona){
    assert(persona != NULL);
    int cant = cantidadPerrosTPersona(persona);
    printf("La persona tiene %d perro/s.\n", cant);    
}

void main_liberarPersona(TPersona &persona) {
    assert(persona != NULL);
    liberarTPersona(persona);
}


//////////////////////////////////////////////
//    Funciones main para LSE Adopciones    //
//////////////////////////////////////////////

void main_crearLSEAdopcionesVacia(TLSEAdopciones &listaAdopciones){
    assert(listaAdopciones == NULL);
    listaAdopciones = crearTLSEAdopcionesVacia();
    printf("Lista de adopciones creada de forma exitosa.\n");
}

void main_insertarLSEAdopciones(TLSEAdopciones &listaAdopciones, TFecha &fecha, TPersona &persona, TPerro &perro){
    insertarTLSEAdopciones(listaAdopciones, fecha, persona, perro);
    printf("Adopcion de persona de CI %d y perro de id %d agregada de forma exitosa.\n", ciTPersona(persona), idTPerro(perro));
    fecha = NULL;
    persona = NULL;
    perro = NULL;
}

void main_imprimirLSEAdopciones(TLSEAdopciones listaAdopciones){
    printf("Lista de adopciones:\n");
    imprimirTLSEAdopciones(listaAdopciones);
    printf("Fin lista de adopciones.\n");
}

void main_liberarLSEAdopciones(TLSEAdopciones &listaAdopciones){
    liberarTLSEAdopciones(listaAdopciones);
    printf("Lista de adopciones liberada con exito.\n");
}

void main_esVaciaLSEAdopciones(TLSEAdopciones listaAdopciones){
    bool esVacia = esVaciaTLSEAdopciones(listaAdopciones);
    if (esVacia){
        printf("La lista de adopciones es vacia.\n");
    } else {
        printf("La lista de adopciones NO es vacia.\n");
    }
}

void main_existeAdopcionLSEAdopciones(TLSEAdopciones listaAdopciones){
    int ciPersona = leerInt();
    int idPerro = leerInt();
    bool existe = existeAdopcionTLSEAdopciones(listaAdopciones, ciPersona, idPerro);
    if (existe){
        printf("Existe una adopcion de la persona de CI %d al perro %d en la lista.\n", ciPersona, idPerro);
    } else {
        printf("NO Existe una adopcion de la persona de CI %d al perro %d en la lista.\n", ciPersona, idPerro);
    }
}

void main_removerAdopcionLSEAdopciones(TLSEAdopciones &listaAdopciones){
    int ciPersona = leerInt();
    int idPerro = leerInt();
    assert(existeAdopcionTLSEAdopciones(listaAdopciones, ciPersona, idPerro));
    removerAdopcionTLSEAdopciones(listaAdopciones, ciPersona, idPerro);
    printf("Adopcion de la persona de CI %d al perro %d removida de la lista exitosamente.\n", ciPersona, idPerro);
}

/////////////////////////////////////
// Funciones main para ABB Persona //
/////////////////////////////////////

void main_crearABBPersonasVacio(TABBPersonas &abbPersonas){
    assert(abbPersonas == NULL);
    abbPersonas = crearTABBPersonasVacio();
    printf("El abb de personas ha sido creado de forma exitosa.\n");
}

void main_insertarPersonaABBPersonas(TABBPersonas &abbPersonas, TPersona &persona){
    assert(persona != NULL);
    insertarTPersonaTABBPersonas(abbPersonas, persona);
    printf("Persona agregada al arbol exitosamente.\n");
    persona = NULL;
}

void main_imprimirABBPersonas(TABBPersonas abbPersonas){
    imprimirTABBPersonas(abbPersonas);
}

void main_existePersonaABBPersonas(TABBPersonas abbPersonas){
    int id = leerInt();
    if (existeTPersonaTABBPersonas(abbPersonas, id)){
        printf("La persona con ci %d pertenece al arbol.\n", id);
    }else{
        printf("La persona con ci %d NO pertenece al arbol.\n", id);
    }
}

void main_obtenerPersonaABBPersonas(TABBPersonas abbPersonas){
    int id = leerInt();
    TPersona persona = obtenerTPersonaTABBPersonas(abbPersonas, id);
    if (persona == NULL){
        printf("La persona con CI %d no se puede imprimir pues NO pertenece al arbol.\n", id);
    }else{  
        imprimirTPersona(persona);
    }
}

void main_alturaABBPersonas(TABBPersonas abbPersonas){
    nat altura = alturaTABBPersonas(abbPersonas);
    printf("La altura del arbol es %d.\n", altura);
}

void main_maxCIPersonaABBPersonas(TABBPersonas abbPersonas){
    TPersona personaMaxCI = maxCITPersonaTABBPersonas(abbPersonas);
    printf("La mayor cedula en el arbol es %d.\n", ciTPersona(personaMaxCI));
}

void main_cantidadABBPersonas(TABBPersonas abbPersonas){
    int cantidad = cantidadTABBPersonas(abbPersonas);
    printf("La cantidad de personas en el arbol es %d.\n", cantidad);
}

void main_obtenerNesimaPersonaABBPersonas(TABBPersonas abbPersonas){
    int n = leerInt();
    int cantEnArbol = cantidadTABBPersonas(abbPersonas); 
    if (cantEnArbol >= n) {
        TPersona persona = obtenerNesimaPersonaTABBPersonas(abbPersonas, n);
        printf("Persona nro %d del abb personas:\n", n);
        imprimirTPersona(persona);
    } else {
        printf("No se puede imprimir la persona nro %d del arbol porque solo hay %d.\n", n, cantEnArbol);
    }
}

void main_removerPersonaABBPersonas(TABBPersonas &abbPersonas){
    int ci = leerInt();
    if (existeTPersonaTABBPersonas(abbPersonas, ci)) {
        removerTPersonaTABBPersonas(abbPersonas, ci);
        printf("La persona con id %d se removio del arbol.\n", ci);
    } else {
        printf("La persona con CI %d no se puede remover porque NO pertenece al arbol.\n", ci);
    }
}

void main_liberarABBPersonas(TABBPersonas &abbPersonas){
    liberarTABBPersonas(abbPersonas);
    printf("ABB personas liberado con exito.\n");
}

void main_filtradoPorFechaDeNacimientoABBPersonas(TABBPersonas abbPersonas){
    TFecha fechaFiltrado = NULL;
    leerFecha(fechaFiltrado);
    int criterio = leerInt();
    TABBPersonas filtrado = filtradoPorFechaDeNacimientoTABBPersonas(abbPersonas, fechaFiltrado, criterio);
    printf("Arbol filtrado:\n");
    imprimirTABBPersonas(filtrado);
    liberarTABBPersonas(filtrado);
}

void insertarEnArbolDesdeArreglo(TABBPersonas &abbPersonas, TPersona *arreglo, int inicio, int final){
    if (inicio <= final){
        int mid = (inicio + final) / 2;
        insertarTPersonaTABBPersonas(abbPersonas, arreglo[mid]);
        insertarEnArbolDesdeArreglo(abbPersonas, arreglo, inicio, mid - 1);
        insertarEnArbolDesdeArreglo(abbPersonas, arreglo, mid + 1, final);
    }
}

void main_alturaABBPersonasTiempo(){
    TABBPersonas abbPersonas = crearTABBPersonasVacio();

    nat tamanio = leerNat();
    nat timeout = leerNat();

    TPersona *arreglo = new TPersona[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTPersona(i, "Carlos", "Luna", 2, 5, 1960);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(abbPersonas, arreglo, inicio, final);
    clock_t tm = clock();
    nat altura = alturaTABBPersonas(abbPersonas);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    }else{
        printf("La altura del argbol es %d. Calculado correctamente en menos de %ds.\n", altura, timeout);    
    }
    
    liberarTABBPersonas(abbPersonas);
    delete[] arreglo;
}

void main_obtenerExistePersonaABBPersonasTiempo(){
    TABBPersonas abbPersonas = crearTABBPersonasVacio();

    nat tamanio = leerNat();
    double timeout = leerDouble();

    TPersona *arreglo = new TPersona[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTPersona(i, "Carlos", "Luna",  2, 5, 1960);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(abbPersonas, arreglo, inicio, final);
    clock_t tm = clock();
    bool existePersona1 = existeTPersonaTABBPersonas(abbPersonas, 0);
    bool existePersona2 = existeTPersonaTABBPersonas(abbPersonas, tamanio - 1);
    bool existePersona3 = existeTPersonaTABBPersonas(abbPersonas, tamanio / 3);
    bool existePersona4 = existeTPersonaTABBPersonas(abbPersonas, (2 * tamanio) / 3);
    TPersona persona1 = obtenerTPersonaTABBPersonas(abbPersonas, 0);
    TPersona persona2 = obtenerTPersonaTABBPersonas(abbPersonas, tamanio - 1);
    TPersona persona3 = obtenerTPersonaTABBPersonas(abbPersonas, tamanio / 3);
    TPersona persona4 = obtenerTPersonaTABBPersonas(abbPersonas, (2 * tamanio) / 3);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
    }else{
        printf("Se obtuvieron las personas %d %d %d %d con cis respectivas %d %d %d %d\n", existePersona1, existePersona2, existePersona3, existePersona4, ciTPersona(persona1), ciTPersona(persona2), ciTPersona(persona3), ciTPersona(persona4));
        printf("Calculado correctamente en menos de %.3fs.\n", timeout);    
    }
    
    liberarTABBPersonas(abbPersonas);
    delete[] arreglo;
}

//////////////////////////////////////////
//   Funciones main para LDE Perros     //
//////////////////////////////////////////

void main_crearLDEPerrosVacia(TLDEPerros &ldePerros){
    assert(ldePerros == NULL);
    ldePerros = crearTLDEPerrosVacia();
    printf("La LDE de perros ha sido creado de forma exitosa.\n");
}

void main_insertarLDEPerros(TLDEPerros &ldePerros, TPerro &perro){
    assert(perro != NULL);
    insertarTLDEPerros(ldePerros, perro);
    perro = NULL;
    printf("Se ha agregado el perro a la lista de forma exitosa.\n");
}

void main_imprimirLDEPerros(TLDEPerros ldePerros){
    imprimirTLDEPerros(ldePerros);
}

void main_imprimirInvertidoLDEPerros(TLDEPerros ldePerros){
    imprimirInvertidoTLDEPerros(ldePerros);
}

void main_cantidadLDEPerros(TLDEPerros ldePerros){
    nat cant = cantidadTLDEPerros(ldePerros);
    printf("La cantidad de perros en la lista es %d\n", cant);
}

void main_obtenerPrimeroLDEPerros(TLDEPerros ldePerros){
    nat cant = cantidadTLDEPerros(ldePerros);
    if (cant > 0){
        TPerro perro = obtenerPrimeroTLDEPerros(ldePerros);
        assert(perro != NULL);
        printf("Primer perro:\n");
        imprimirTPerro(perro);
    }else{
        printf("No se puede obtener el primero de la LDE de perros porque es vacia\n");
    }
}

void main_obtenerUltimoLDEPerros(TLDEPerros ldePerros){
    nat cant = cantidadTLDEPerros(ldePerros);
    if (cant > 0){
        TPerro perro = obtenerUltimoTLDEPerros(ldePerros);
        assert(perro != NULL);
        printf("Ultimo perro:\n");
        imprimirTPerro(perro);
    }else{
        printf("No se puede obtener el ultimo de la LDE de perros porque es vacia\n");
    }
}

void main_obtenerNesimoLDEPerros(TLDEPerros ldePerros){
    nat n = leerNat();
    assert(cantidadTLDEPerros(ldePerros) >= n);

    TPerro perro = obtenerNesimoTLDEPerros(ldePerros, n);
    assert(perro != NULL);

    printf("Perro en la posicion %d:\n", n);
    imprimirTPerro(perro);
}

void main_existePerroLDEPerros(TLDEPerros ldePerros){
    int id = leerInt();
    bool existe = existePerroTLDEPerros(ldePerros, id);
    if (existe){
        printf("El perro de id %d pertenece a la lista.\n", id);
    }else{
        printf("El perro de id %d NO pertenece a la lista.\n", id);
    }
}

void main_removerPerroLDEPerros(TLDEPerros ldePerros){
    nat id = leerNat();
    assert(existePerroTLDEPerros(ldePerros, id));

    TPerro perro = removerPerroTLDEPerros(ldePerros, id);
    assert(perro != NULL);

    printf("Perro removido de la lista:\n");
    imprimirTPerro(perro);
    liberarTPerro(perro);
}

void main_liberarLDEPerros(TLDEPerros &ldePerros){
    assert(ldePerros != NULL);
    liberarTLDEPerros(ldePerros);
    printf("Lista doblemente encadenada de perros liberada.\n");
    ldePerros = NULL;
}

void main_removerPrimeroLDEPerros(TLDEPerros &ldePerros) {
    assert(cantidadTLDEPerros(ldePerros) > 0); 
    TPerro perro = removerPrimeroTLDEPerros(ldePerros);
    printf("Primer perro (ahora removido):\n");
    imprimirTPerro(perro);
    liberarTPerro(perro);
}

void main_removerUltimoLDEPerros(TLDEPerros &ldePerros) {
    assert(cantidadTLDEPerros(ldePerros) > 0); 
    TPerro perro = removerUltimoTLDEPerros(ldePerros);
    printf("Útimo perro (ahora removido):\n");
    imprimirTPerro(perro);
    liberarTPerro(perro);
}

//////////////////////////////////////
// Funciones main para Pila         //
//////////////////////////////////////
void main_crearPila(TPila &pila){
    assert(pila == NULL);
    pila = crearTPila();
    printf("Se ejecutó 'crearTPila' exitosamente\n");
}

void main_apilarPila(TPila &pila){
    int entero = leerInt();
    apilarTPila(pila, entero);
    printf("Se ejecutó 'apilarTPila' exitosamente con entero %d\n", entero);
}

void main_desapilarPila(TPila &pila){
    assert(cantidadTPila(pila) > 0);
    desapilarTPila(pila);
    printf("Se ejecutó 'desapilarTPila' exitosamente\n");
}

void main_cimaPila(TPila pila) {
    assert(cantidadTPila(pila) > 0); 
    int cima = cimaTPila(pila);
    printf("Elemento obtenido al ejecutar cima: %d.\n", cima);
}

void main_cantidadPila(TPila pila){
    nat cantidad = cantidadTPila(pila);

    printf("Existen %d elementos en la pila.\n", cantidad);
}

void main_imprimirPila(TPila pila){
    printf("Pila:\n");
    imprimirTPila(pila);
}

void main_liberarPila(TPila &pila){
    assert(pila != NULL); 
    liberarTPila(pila);
    assert(pila == NULL); 
    printf("Se ejecutó 'liberarTPila' exitosamente.\n");    
}

///////////////////////////////////////////
// Funciones main para AGFichaVacunacion //
///////////////////////////////////////////

void main_crearAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion){
    assert(fichaVacunacion == NULL);
    fichaVacunacion = crearTAGFichaVacunacion();
    printf("Se ejecutó 'crearTAGFichaVacunacion' exitosamente.\n");    
}

void main_insertarVacunaAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion){
    int codVacunaPadre = leerInt();    
    int codVacuna = leerInt();
    insertarVacunaTAGFichaVacunacion(fichaVacunacion, codVacunaPadre, codVacuna);
    printf("Se ejecutó 'insertarVacunaTAGFichaVacunacion' con codVacunaPadre %d y codVacuna %d.\n", codVacunaPadre, codVacuna);    
}

void main_imprimirAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    imprimirTAGFichaVacunacion(fichaVacunacion);
}

void main_liberarAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion){
    liberarTAGFichaVacunacion(fichaVacunacion);
    printf("Se ejecutó 'liberarTAGFichaVacunacion' exitosamente.\n");    
}

void main_existeVacunaAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    int codVacuna = leerInt();
    bool existe = existeVacunaTAGFichaVacunacion(fichaVacunacion, codVacuna);
    if (existe){
        printf("La vacuna de código %d está incluída en la ficha de vacunación.\n", codVacuna);        
    } else {
        printf("La vacuna de código %d NO está incluída en la ficha de vacunación.\n", codVacuna);        
    }
}

void main_alturaAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    nat altura = alturaTAGFichaVacunacion(fichaVacunacion);
    printf("La altura de la ficha de vacunación (árbol general) es: %d.\n", altura);        
}

void main_cantidadAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    nat cantidad = cantidadTAGFichaVacunacion(fichaVacunacion);
    printf("Existen %d vacunas en la ficha de vacunación.\n", cantidad);            
}

void main_removerVacunaAGFichaVacunacion(TAGFichaVacunacion &fichaVacunacion){
    int codVacuna = leerInt();
    assert(existeVacunaTAGFichaVacunacion(fichaVacunacion, codVacuna));
    removerVacunaTAGFichaVacunacion(fichaVacunacion, codVacuna);
    bool existe = existeVacunaTAGFichaVacunacion(fichaVacunacion, codVacuna);
    if (existe){
        printf("La vacuna de código %d no fue removida.\n", codVacuna);        
    }else{
        printf("Vacuna de código %d removida.\n", codVacuna);                
    }
}

TAGFichaVacunacion aux_leerAGFichaVacunacion(){
    TAGFichaVacunacion fichaVacunacion = crearTAGFichaVacunacion();
    nat cant = leerNat();
    for (nat i = 0; i < cant; i++){
        int codVacunaPadre = leerInt();
        int codVacuna = leerInt();
        insertarVacunaTAGFichaVacunacion(fichaVacunacion, codVacunaPadre, codVacuna);
    }
    return fichaVacunacion;
}

void main_igualesAGFichaVacunacion(TAGFichaVacunacion fichaVacunacion){
    TAGFichaVacunacion ficha2 = aux_leerAGFichaVacunacion();
    bool iguales = igualesTAGFichaVacunacion(fichaVacunacion, ficha2);
    if (iguales){
        printf("Las fichas de vacunación son iguales.\n");        
    } else {
        printf("Las fichas de vacunación NO son iguales.\n");        
    }
    liberarTAGFichaVacunacion(ficha2);
}
 
///////////////////////////////////////////
//   Funciones main para Cola Perros     //
///////////////////////////////////////////

void main_crearColaPerros(TColaPerros &colaPerros){
    assert(colaPerros == NULL);    
    colaPerros = crearTColaPerros();
    printf("Se ejecutó 'crearTColaPerros' exitosamente\n");
}

void main_encolarColaPerros(TColaPerros &colaPerros, TPerro &perro){
    int idPerro = idTPerro(perro);
    encolarTColaPerros(colaPerros, perro);
    perro = NULL;
    printf("Se ejecutó 'encolarTColaPerros' exitosamente con perro de id %d\n", idPerro);
}

void main_desencolarColaPerros(TColaPerros &colaPerros){
    assert(cantidadTColaPerros(colaPerros) > 0);
    desencolarTColaPerros(colaPerros);
    printf("Se ejecutó 'desencolarTColaPerros' exitosamente\n");
}

void main_frenteColaPerros(TColaPerros colaPerros) {
    assert(cantidadTColaPerros(colaPerros) > 0);
    TPerro perro = frenteTColaPerros(colaPerros);
    printf("Perro obtenido al ejecutar frente:\n");
    imprimirTPerro(perro);
}

void main_cantidadColaPerros(TColaPerros colaPerros){
    int cant = cantidadTColaPerros(colaPerros);
    printf("La cantidad de perros en la cola es %d\n", cant);
}

void main_imprimirColaPerros(TColaPerros colaPerros){
    imprimirTColaPerros(colaPerros);
}

void main_liberarColaPerros(TColaPerros &colaPerros){
    assert(colaPerros != NULL);
    liberarTColaPerros(colaPerros);
    assert(colaPerros == NULL);
    printf("Se ejecutó 'liberarTColaPerros' exitosamente\n");
}

///////////////////////////////////////////
//  Funciones main para Conjunto Perros  //
///////////////////////////////////////////

void main_crearConjuntoPerros(TConjuntoPerros &conjuntoPerros){
    assert(conjuntoPerros == NULL);

    int cantMax = leerInt();    
    conjuntoPerros = crearTConjuntoPerros(cantMax);
    printf("Se creó conjunto perros con cantMax %d exitosamente.\n", cantMax);
}

void main_esVacioConjuntoPerros(TConjuntoPerros conjuntoPerros){
    bool esVacia = esVacioTConjuntoPerros(conjuntoPerros);
    if (esVacia){
        printf("El conjunto de perros es vacío.\n");
    } else {
        printf("La conjunto de perros NO es vacío.\n");
    }
}

void main_insertarConjuntoPerros(TConjuntoPerros &conjuntoPerros){
    int idPerro = leerInt();
    insertarTConjuntoPerros(conjuntoPerros, idPerro);
    printf("Se ejecutó 'insertarTConjuntoPerros con perro de id %d exitosamente.\n", idPerro);
}

void main_borrarDeConjuntoPerros(TConjuntoPerros &conjuntoPerros){
    int idPerro = leerInt();
    borrarDeTConjuntoPerros(conjuntoPerros, idPerro);
    printf("Se ejecutó 'borrarDeTConjuntoPerros con perro de id %d exitosamente.\n", idPerro);
}

void main_perteneceConjuntoPerros(TConjuntoPerros conjuntoPerros){
    int idPerro = leerInt();
    bool pertenece = perteneceTConjuntoPerros(conjuntoPerros, idPerro);
    if (pertenece){
        printf("El perro de id %d pertenece al conjunto.\n", idPerro);   
    }else{
        printf("El perro de id %d NO pertenece al conjunto.\n", idPerro);   
    }
}

void main_cardinalConjuntoPerros(TConjuntoPerros conjuntoPerros){
    int cardinal = cardinalTConjuntoPerros(conjuntoPerros);
    printf("El cardinal del conjunto es: %d.\n", cardinal);    
}

void main_cantMaxConjuntoPerros(TConjuntoPerros conjuntoPerros){
    int cantMax = cantMaxTConjuntoPerros(conjuntoPerros);
    printf("La cantidad máxima del conjunto es: %d.\n", cantMax); 
}

void main_imprimirConjuntoPerros(TConjuntoPerros conjuntoPerros){
    printf("Conjunto de perros:\n");    
    imprimirTConjuntoPerros(conjuntoPerros);
}

void main_liberarConjuntoPerros(TConjuntoPerros &conjuntoPerros){
    liberarTConjuntoPerros(conjuntoPerros);
    assert(conjuntoPerros == NULL);
    printf("Se ejecutó 'liberarTConjuntoPerros' exitosamente.\n");    
}

TConjuntoPerros aux_crearConjuntoPerros(TConjuntoPerros conjuntoPerros){
    int cantMax = cantMaxTConjuntoPerros(conjuntoPerros);
    TConjuntoPerros otroConjunto = crearTConjuntoPerros(cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int id = leerInt();
        insertarTConjuntoPerros(otroConjunto, id);
    }

    return otroConjunto;
}

void main_unionConjuntoPerros(TConjuntoPerros conjuntoPerros){
    TConjuntoPerros otroConjunto = aux_crearConjuntoPerros(conjuntoPerros);

    TConjuntoPerros unionConjuntoPerros = unionTConjuntoPerros(conjuntoPerros, otroConjunto);
    printf("Conjunto de perros unión:\n");    
    imprimirTConjuntoPerros(unionConjuntoPerros);

    liberarTConjuntoPerros(unionConjuntoPerros);
    liberarTConjuntoPerros(otroConjunto);
}

void main_interseccionConjuntoPerros(TConjuntoPerros conjuntoPerros){
    TConjuntoPerros otroConjunto = aux_crearConjuntoPerros(conjuntoPerros);

    TConjuntoPerros interseccion = interseccionTConjuntoPerros(conjuntoPerros, otroConjunto);
    printf("Conjunto de perros intersección:\n");    
    imprimirTConjuntoPerros(interseccion);

    liberarTConjuntoPerros(interseccion);
    liberarTConjuntoPerros(otroConjunto);
}

void main_diferenciaConjuntoPerros(TConjuntoPerros conjuntoPerros){
    TConjuntoPerros otroConjunto = aux_crearConjuntoPerros(conjuntoPerros);

    TConjuntoPerros diferencia = diferenciaTConjuntoPerros(conjuntoPerros, otroConjunto);
    printf("Conjunto de perros diferencia:\n");    
    imprimirTConjuntoPerros(diferencia);

    liberarTConjuntoPerros(diferencia);
    liberarTConjuntoPerros(otroConjunto);
}

///////////////////////////////////////////
//    Funciones main para Aplicaciones   //
///////////////////////////////////////////

void main_mismosElementos(TPila p, TColaPerros c) {
    bool res = mismosElementos(p, c);
    if (res) printf("Tienen los mismos elementos.\n");
    else printf("NO tienen los mismos elementos.\n");
}

void main_menoresQueElResto(TLDEPerros l) {
    TPila res = menoresQueElResto(l); 
    imprimirTPila(res);
    liberarTPila(res);
}

void main_sumaPares(TConjuntoPerros c) {
    nat k = leerNat(); 
    bool res = sumaPares(k, c);
    if (res) {
        printf("Existen dos ids en el conjunto que suman %d.\n", k);
    } else {
        printf("NO existen dos ids en el conjunto que sumen %d.\n", k);
    }
}

///////////////////////////////////////////
//        Funciones main para CP         //
///////////////////////////////////////////

void main_crearCP(TColaDePrioridadPerros &cpPerros) {
    nat max = leerNat(); 
    cpPerros = crearTColaDePrioridadPerros(max);
    printf("Se creó una cola de prioridad de perros con cantidad maxima %d\n", max);
}

void main_invertirPrioridadCP(TColaDePrioridadPerros &cpPerros) {
    invertirPrioridadTColaDePrioridadPerros(cpPerros);
    printf("Se invirtió la prioridad de la cola de prioridad de perros\n"); 
}

void main_liberarCP(TColaDePrioridadPerros &cpPerros) {
    liberarTColaDePrioridadPerros(cpPerros);
    printf("Se liberó la cola de prioridad de perros\n"); 
}

void main_insertarEnCP(TColaDePrioridadPerros &cpPerros, TPerro &perro) {
    insertarTColaDePrioridadPerros(cpPerros, perro); 
    printf("Se insertó el perro en la cola de prioridad.\n");
    perro = NULL;
}

void main_esVaciaCP(TColaDePrioridadPerros cpPerros) {
    bool esVacia = estaVaciaTColaDePrioridadPerros(cpPerros);
    if(esVacia) printf("La cola de prioridad es vacía.\n");
    else printf("La cola de prioridad NO es vacía.\n");
}

void main_prioritarioCP(TColaDePrioridadPerros cpPerros) {
    TPerro prioritario = prioritarioTColaDePrioridadPerros(cpPerros); 
    imprimirTPerro(prioritario); 
}

void main_eliminarPrioritarioCP(TColaDePrioridadPerros &cpPerros) {
    eliminarPrioritarioTColaDePrioridadPerros(cpPerros);
    printf("Se eliminó el elemento prioritario de la cola de prioridad.\n");
}

void main_estaEnCP(TColaDePrioridadPerros cpPerros) {
    int idPerro = leerInt();
    bool esta = estaTColaDePrioridadPerros(cpPerros, idPerro);
    if(esta) printf("El perro con id %d está en la cola de prioridad.\n", idPerro);
    else printf("El perro con id %d NO está en la cola de prioridad.\n", idPerro);
}

void main_prioridadEnCP(TColaDePrioridadPerros cpPerros) {
    int idPerro = leerInt();
    nat prio = prioridadTColaDePrioridadPerros(cpPerros, idPerro);
    printf("La prioridad del perro de id %d es %d\n", idPerro, prio);
}

void main_CPTiempo (){
    nat N = leerNat();
    nat iteraciones = leerNat();
    nat timeout = leerNat();

    TColaDePrioridadPerros cp;
    TPerro p_obj;
    TFecha fecha_obj;

    clock_t tm = clock();
    for (nat iter = 1; iter <= iteraciones; iter++) { // Bucle principal de iteraciones de prueba
        // Prueba 1: Insertar N perros con vitalidad de N a 1 (prioridad decreciente por defecto) y luego eliminarlos.
        cp = crearTColaDePrioridadPerros(N);
        for (nat i = N; i >= 1; i--) {
            fecha_obj = crearTFecha(1, 1, 2000); // Fecha arbitraria, la prioridad se basa en la vitalidad
            // ID = i, Vitalidad = i. Menor vitalidad = mayor prioridad (comportamiento por defecto).
            p_obj = crearTPerro(i, "Perro", 3, i, "Perro de prueba", fecha_obj);
            insertarTColaDePrioridadPerros(cp, p_obj);
        }

        for (nat i = 1; i <= N; i++)
            eliminarPrioritarioTColaDePrioridadPerros(cp);
        liberarTColaDePrioridadPerros(cp);

        // Prueba 2: Insertar N perros con vitalidad de 1 a N (prioridad creciente por defecto) y luego eliminarlos.
        cp = crearTColaDePrioridadPerros(N);
        for (nat i = 1; i <= N; i++) {
            fecha_obj = crearTFecha(1, 1, 2000); // Fecha arbitraria
            // ID = i, Vitalidad = i.
            p_obj = crearTPerro(i, "Perro", 3, i, "Perro de prueba", fecha_obj);
            insertarTColaDePrioridadPerros(cp, p_obj);
        }

        for (nat i = 1; i <= N; i++)
            eliminarPrioritarioTColaDePrioridadPerros(cp);
        liberarTColaDePrioridadPerros(cp);

        // Prueba 3: Invertir prioridad, insertar N perros con vitalidad de 1 a N, y luego eliminarlos.
        // Con prioridad invertida, mayor vitalidad = mayor prioridad.
        cp = crearTColaDePrioridadPerros(N);
        invertirPrioridadTColaDePrioridadPerros(cp); // Ahora, mayor vitalidad = mayor prioridad
        for (nat i = 1; i <= N; i++) {
            fecha_obj = crearTFecha(1, 1, 2000); // Fecha arbitraria
            // ID = i, Vitalidad = i.
            p_obj = crearTPerro(i, "Perro", 3, i, "Perro de prueba", fecha_obj);
            insertarTColaDePrioridadPerros(cp, p_obj);
        }
        for (nat i = 1; i <= N; i++)
            eliminarPrioritarioTColaDePrioridadPerros(cp);
        liberarTColaDePrioridadPerros(cp);

        // Prueba 4: Insertar N perros con vitalidad de N a 1, invertir prioridad, y luego eliminarlos.
        cp = crearTColaDePrioridadPerros(N);
        for (nat i = N; i >= 1; i--) {
            fecha_obj = crearTFecha(1, 1, 2000); // Fecha arbitraria
            // ID = i, Vitalidad = i.
            p_obj = crearTPerro(i, "Perro", 3, i, "Perro de prueba", fecha_obj);
            insertarTColaDePrioridadPerros(cp, p_obj);
        }
        invertirPrioridadTColaDePrioridadPerros(cp); // Invertir prioridad
        for (nat i = 1; i <= N; i++) {
            if (!estaVaciaTColaDePrioridadPerros(cp)) { // Asegurarse de que la cola no esté vacía antes de acceder/eliminar
                prioritarioTColaDePrioridadPerros(cp); // Acceder al prioritario (no se usa el resultado, solo para testear)
                eliminarPrioritarioTColaDePrioridadPerros(cp);
            }
        }
        liberarTColaDePrioridadPerros(cp);
        
        // Prueba 5: Insertar un perro de baja prioridad, luego N-1 perros de alta prioridad, eliminando el prioritario después de cada inserción.
        cp = crearTColaDePrioridadPerros(N);
        // Perro con ID N, vitalidad N (baja prioridad por defecto si N es grande)
        fecha_obj = crearTFecha(1, 1, 2000);
        p_obj = crearTPerro(N, "Perro", 3, N, "Perro de prueba", fecha_obj);
        insertarTColaDePrioridadPerros(cp, p_obj);

        for (nat i = 1; i < N; i++) {
            // Perros con ID i, vitalidad 1 (alta prioridad por defecto)
            // El bucle es i < N, por lo que i no será N. IDs del 1 al N-1.
            fecha_obj = crearTFecha(1, 1, 2000);
            p_obj = crearTPerro(i, "Perro", 3, 1, "Perro de prueba", fecha_obj);
            insertarTColaDePrioridadPerros(cp, p_obj);
            if (!estaVaciaTColaDePrioridadPerros(cp)) {
                 prioritarioTColaDePrioridadPerros(cp); // Acceder
                 eliminarPrioritarioTColaDePrioridadPerros(cp); // Eliminar
            }
        }
        liberarTColaDePrioridadPerros(cp);
    }
    tm = clock() - tm;
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %u \n", tiempo, timeout);
    else
        printf("Bien.\n");
}


///////////////////////////////////////////
//      Funciones main para Tabla        //
///////////////////////////////////////////

void main_crearTabla(TTablaFichaVacunacion &tablaFichaVacunacion) {
    int max = leerInt(); 
    tablaFichaVacunacion = crearTTablaFichaVacunacion(max); 
    printf("Tabla de fichas de vacunación con cantidad estimada %d creada.\n", max); 
}

void main_insertarEnTabla(TTablaFichaVacunacion &tablaFichaVacunacion, TAGFichaVacunacion &ficha) {
    int idPerro = leerInt(); 
    insertarTTablaFichaVacunacion(tablaFichaVacunacion, idPerro, ficha); 
    printf("Se insertó la asociación de ficha de vacunación para el perro de id (%d) en la tabla de fichas de vacunación.\n", idPerro); 
    ficha = NULL;
}

void main_eliminarDeTabla(TTablaFichaVacunacion &tablaFichaVacunacion) {
    int idPerro = leerInt(); 
    eliminarDeTTablaFichaVacunacion(tablaFichaVacunacion, idPerro); 
    printf("Se eliminó la asociación del perro de id %d de la tabla de fichas de vacunación.\n", idPerro); 
}

void main_perteneceATabla(TTablaFichaVacunacion tablaFichaVacunacion) {
    int idPerro = leerInt(); 
    bool pertenece = perteneceTTablaFichaVacunacion(tablaFichaVacunacion, idPerro); 
    if (pertenece){
        printf("El perro de id %d, tiene correspondencia a la tabla de fichas de vacunación.\n", idPerro); 
    }  else {
        printf("El perro de id %d, NO tiene correspondencia a la tabla fichas de vacunación.\n", idPerro);
    }  
}

void main_obtenerDeTabla(TTablaFichaVacunacion tablaFichaVacunacion) {
    int idPerro = leerInt();
    TAGFichaVacunacion ficha = obtenerFichaTTablaFichaVacunacion(tablaFichaVacunacion, idPerro); 
    printf("Ficha de vacunación obtenida para perro de id %d:\n", idPerro);
    imprimirTAGFichaVacunacion(ficha); 
}

void main_liberarTabla(TTablaFichaVacunacion &tablaFichaVacunacion){
    assert(tablaFichaVacunacion != NULL);
    liberarTTablaFichaVacunacion(tablaFichaVacunacion); 
    printf("Se liberó la tabla de fichas de vacunación.\n"); 
}

void main_imprimirTabla(TTablaFichaVacunacion tablaFichaVacunacion){
    imprimirTTablaFichaVacunacion(tablaFichaVacunacion);
}

///////////////////////////////////////////
//      Funciones main para Refugio      //
///////////////////////////////////////////

void main_crearRefugio(TRefugio &refugio) {
    assert(refugio == NULL); 
    int cantEstimada = leerInt();
    refugio = crearTRefugio(cantEstimada);
    printf("Refugio creado.\n");
}

void main_registrarPersonaRefugio(TRefugio &refugio, TPersona &persona) {
    registrarPersonaTRefugio(refugio, persona);
    printf("Se registró la persona de ci %d en el refugio.\n", ciTPersona(persona));
    liberarTPersona(persona); 
}

void main_ingresarPerroRefugio(TRefugio &refugio, TPerro &perro) {
    ingresarPerroTRefugio(refugio, perro); 
    printf("Se ingresó el perro de id %d en el refugio.\n", idTPerro(perro));
    liberarTPerro(perro);
}

void main_agregarVacunaRefugio(TRefugio &refugio) {
    int vacunaPadre = leerInt(); 
    int vacuna = leerInt(); 
    agregarVacunaTRefugio(refugio, vacunaPadre, vacuna); 
}

void main_imprimirEsquemaVacunacionRefugio(TRefugio refugio) {
    imprimirEsquemaVacunacionTRefugio(refugio);
}

void main_adoptarPerroRefugio(TRefugio &refugio, TFecha &fecha) {
    int idPerro = leerInt();
    int ciPersona = leerInt(); 
    adoptarPerroTRefugio(refugio, idPerro, ciPersona, fecha); 
    liberarTFecha(fecha);
    printf("Se registró la adopción entre el perro de id %d y la persona de ci %d en el refugio.\n", idPerro, ciPersona); 
}

void main_pasearPerrosRefugio(TRefugio &refugio) {
    nat cant = leerNat(); 
    pasearPerrosTRefugio(refugio, cant);
    printf("Se pasearon %d perros del refugio.\n", cant);
}

void main_imprimirColaPaseosRefugio(TRefugio refugio) {
    imprimirColaPaseosTRefugio(refugio); 
}

void main_imprimirPersonasRefugio(TRefugio refugio) {
    imprimirPersonasTRefugio(refugio);
}

void main_imprimirPerrosRefugio(TRefugio refugio) {
    char c  = leerChar(); 
    if(c == 'T') imprimirPerrosTRefugio(refugio, true); 
    else if (c == 'F') imprimirPerrosTRefugio(refugio, false);
    else printf("Comando no reconocido.\n");
}

void main_imprimirAdopcionesRefugio(TRefugio refugio) {
    imprimirAdopcionesTRefugio(refugio);
}

void main_imprimirFichaVacunacionPerroRefugio(TRefugio refugio) {
    int idPerro = leerInt();
    imprimirFichaVacunacionPerroTRefugio(refugio, idPerro);
}

void main_vacunarPerroRefugio(TRefugio &refugio) {
    int idPerro = leerInt();
    int codVacunaPadre = leerInt();
    int codVacuna = leerInt();
    vacunarPerroTRefugio(refugio, idPerro, codVacunaPadre, codVacuna); 
    printf("Se vacunó al perro %d con la vacuna (%d, %d).\n", idPerro, codVacunaPadre, codVacuna); 
}


void main_obtenerPerrosSinVacunacionRefugio(TRefugio refugio) {
    TColaDePrioridadPerros perrosSinVacunas = obtenerPerrosSinVacunacionTRefugio(refugio); 
    if(estaVaciaTColaDePrioridadPerros(perrosSinVacunas)) printf("No hay perros sin vacunacion.\n");
    else {
        printf("Los perros sin vacunación son: \n");
        while(!estaVaciaTColaDePrioridadPerros(perrosSinVacunas)) {
            TPerro prioritario = prioritarioTColaDePrioridadPerros(perrosSinVacunas);
            imprimirTPerro(prioritario);
            eliminarPrioritarioTColaDePrioridadPerros(perrosSinVacunas);
        }
    }
    liberarTColaDePrioridadPerros(perrosSinVacunas);
}

void main_liberarRefugio(TRefugio &refugio) {
    liberarTRefugio(refugio);
    printf("Se liberó la memoria asociada al refugio.\n");
}
