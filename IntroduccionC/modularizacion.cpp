#include <stdio.h>
#include <ctype.h>

struct rep_fecha
{
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

int main(int argc, char const *argv[])
{
    rep_fecha arrFecha[3];
    arrFecha[1].d = 10;
    arrFecha[1].m = 10;
    arrFecha[1].a = 2022;

    arrFecha[0].d = 15;
    arrFecha[0].m = 05;
    arrFecha[0].a = 2022;

    arrFecha[2].d = 20;
    arrFecha[2].m = 11;
    arrFecha[2].a = 1992;

    for (int i = 0; i < 2; i++)
    {
       rep_fecha aux; 
       if(arrFecha[i].a < arrFecha[i+1].a){
              aux = arrFecha[i];
              arrFecha[i] = arrFecha[i+1];
              arrFecha[i+1] = aux;
       }else if (arrFecha[i].a == arrFecha[i+1].a && arrFecha[i].m < arrFecha[i+1].m){
              aux = arrFecha[i];
              arrFecha[i] = arrFecha[i+1];
              arrFecha[i+1] = aux;
         }else if (arrFecha[i].a == arrFecha[i+1].a && arrFecha[i].m == arrFecha[i+1].m && arrFecha[i].d < arrFecha[i+1].d){
                aux = arrFecha[i];
                arrFecha[i] = arrFecha[i+1];
                arrFecha[i+1] = aux;
             }
    }
    printf("Fechas ordenadas de mayor a menor son:\n");
  for(int i = 0; i < 3; i++){
      printf("%d/%d/%d\n", arrFecha[i].d, arrFecha[i].m, arrFecha[i].a);
  }
    return 0;
}
