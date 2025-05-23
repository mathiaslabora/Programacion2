#include <stdio.h>

int fibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned int n = 3;
    printf("El fibonacci de %d es %d\n", n, fibonacci(n));
    return 0;
}