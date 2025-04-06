#include <stdio.h>



int main()
{
    int primerNum, segNum;
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &primerNum, &segNum);
    int mayor, menor;
    if(primerNum > segNum){   
        mayor = primerNum;
        menor = segNum;
    }else {
        mayor = segNum;
        menor = primerNum;}

    for(int i = menor; i<= mayor; i++)
    {
        bool esPrimo = true;
        if (i == 1)
        {
            esPrimo = false;
        }else {
            
            for(int g = i-1; g>=2; g--)
            {
                if(i%g == 0)
                {
                esPrimo = false;
                break;
                }
            }
            
        }   
        if (esPrimo==true)
            {
                printf("Es primo: %d\n", i);
            }
    }
    return 0;
}
