#include <stdio.h>
int menorNum(int primNum, int segNum, int tercNum, int cuarNum, int quinNum) {
    int menor = primNum;
    if (segNum < menor) menor = segNum;
    if (tercNum < menor) menor = tercNum;
    if (cuarNum < menor) menor = cuarNum;
    if (quinNum < menor) menor = quinNum;
    return menor;
}


int main() {
    printf("Ingrese 5 numeros enteros: ");
    int primNum, segNum, tercNum, cuarNum, quinNum;
    scanf("%d %d %d %d %d", &primNum, &segNum, &tercNum, &cuarNum, &quinNum);
    int menor = menorNum(primNum, segNum, tercNum, cuarNum, quinNum);
    float promedio = (float)(primNum + segNum + tercNum + cuarNum + quinNum - menor) / 4;
    printf("El promedio de los 4 numeros mayores es: %f", promedio);
    return 0;
}