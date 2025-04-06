#include <stdio.h>
#include <ctype.h>
int ocurrencias(char frase[], int largo, char letra){
    int suma=0;
    letra = toupper(letra);
    for (int i=0; i<largo; i++){
        frase[i] = toupper(frase[i]);
        if (frase[i] == letra){
            suma+=1;
        }
    }
    return suma;
};

int main()
{
    int largo;
    char letra;
    char frase[100];
    printf("Ingrese una frase, letra, largo: ");
    scanf("%s %c %d", frase, &letra, &largo);
    int cantOcurrencias = ocurrencias(frase, largo, letra);
    printf("La letra %c aparece %d veces en la frase indicada", letra, cantOcurrencias);
    return 0;
}
