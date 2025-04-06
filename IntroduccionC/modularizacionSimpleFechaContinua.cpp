#include <stdio.h>
#include <ctype.h>
struct rep_fecha
{
    unsigned int f;
};
int main()
{
    rep_fecha arrFecha[3];
    arrFecha[1].f = 20241010;
    arrFecha[0].f = 20220515;
    arrFecha[2].f = 19921120;
    for (int i = 0; i < 2; i++)
    {
        rep_fecha aux;
        if (arrFecha[i].f < arrFecha[i + 1].f)
        {
            aux = arrFecha[i];
            arrFecha[i] = arrFecha[i + 1];
            arrFecha[i + 1] = aux;
        }
    }
    printf("Fechas ordenadas de mayor a menor son:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d/%d/%d\n", arrFecha[i].f / 10000, (arrFecha[i].f % 10000) / 100, arrFecha[i].f % 100);
    }
    return 0;
}
