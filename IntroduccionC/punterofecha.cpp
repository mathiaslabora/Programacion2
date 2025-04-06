#include <stdio.h>
struct rep_fecha
{
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

typedef struct rep_fecha* TFecha; 
/* Devuelve un 'TFecha' con dia d, mes m y año a */ 
TFecha crearFecha (unsigned int d, unsigned int m, unsigned int a)
{
    TFecha nueva = new rep_fecha;
    nueva->d=d;
    (*nueva).m=m;
    nueva->a=a;

    return nueva;
}
/* Devuelve true si f1 es anterior a f2, false en otro caso */ 
bool esAnterior (TFecha f1, TFecha f2){

    if (f1->a < f2->a ||
        (f1->a == f2->a && f1->m < f2->m) ||
        (f1->a == f2->a && f1->m == f2->m && f1->d < f2->d)){
        return true;
    }else 
        return false;
}
/* Devuelve el día correspondiente a fecha */ 
unsigned int dia (TFecha fecha){
    return fecha->d;
}
/* Devuelve el mes correspondiente a fecha */ 
unsigned int mes (TFecha fecha){
    return fecha->m;
}
/* Devuelve el año correspondiente a fecha */ 
unsigned int anio (TFecha fecha){
    return fecha->a;
}

int main()
{
    int n=3;
    TFecha arrFecha[n];
    arrFecha[1] = crearFecha(10, 10, 2022);
    arrFecha[0] = crearFecha(15, 05, 2022);
    arrFecha[2] = crearFecha(20, 11, 1992);

    for (int i = 0; i < n; i++)
    {
        int min=1;
        for (int j = i+1;j < n; j++)
        {
            if(esAnterior(arrFecha[j], arrFecha[min])){
                min=j;
            }
            TFecha aux = arrFecha[min];
            arrFecha[min] = arrFecha[i];
            arrFecha[i] = aux;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d/%d\n", dia(arrFecha[i]), mes(arrFecha[i]), anio(arrFecha[i]));
    }
    
}
