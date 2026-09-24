#include <stdio.h>

int main(void) {
    int num_1;
    int num_2;
    
    printf("Introdueix el primer valor enter: ");
    scanf("%d", &num_1);

    printf("Introdueix el segon valor enter: ");
    scanf("%d", &num_2);

    printf("La suma dels dos valors es: %d\n", num_1 + num_2);
    printf("La diferencia dels dos valors es: %d\n", num_1 - num_2);
    printf("El producte dels dos valors es: %d\n", num_1 * num_2);
    printf("El quocient dels dos valors es: %d\n", num_1 / num_2);
    printf("El residu de la divisió dels dos valors es: %d\n", num_1 % num_2);


    
    return 0;
}