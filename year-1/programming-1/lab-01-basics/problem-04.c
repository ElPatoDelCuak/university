#include <stdio.h>

int main(void) {
    float num;
    
    printf("Introdueix un valor real: ");
    scanf("%f", &num);
    
    printf("El valor introduït en diferents formats son:\n");
    printf("Notació científica: %e\n", num);
    printf("Notació de punt flotant: %f\n", num);
    printf("Format automatic: %g\n", num);
    
    return 0;
}