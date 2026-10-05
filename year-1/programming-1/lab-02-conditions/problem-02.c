#include <stdio.h>

int main(void) {
    int segons;
    int hores, minuts;

    printf("Introdueix el nombre de segons: ");
    scanf("%d", &segons);

    hores = segons / 3600;
    minuts = (segons % 3600) / 60;
    segons = segons % 60;

    printf("%d segons equivalen a %d hores i %d minuts i %d segons.\n", segons, hores, minuts, segons);

    return 0;
}