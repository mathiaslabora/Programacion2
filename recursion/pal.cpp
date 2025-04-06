#include <stdio.h>


bool esPalindromoRecursivo (char* arrPal,int i, int f){
    if (i >= f) {
        return true;
    }
    if (arrPal[i] != arrPal[f]) {
        return false;
    }
    return esPalindromoRecursivo(arrPal, i + 1, f - 1);
}
int main()
{
    /* code */
    // char arrPal[] = "ana";
    char arrPal[] = {'a', 'n', 'o'};
    // int n = sizeof(arrPal)/sizeof(arrPal[0]);
    bool es= esPalindromoRecursivo(arrPal, 0, 2);
    printf("Es palindromo: %d\n", es);
    return 0;
}



