#include <stdio.h>

int main(void) {
    int segons;
    int setmanes, dias, hores, minuts;

    printf("Introdueix el nombre de segons: ");
    scanf("%d", &segons);

    minuts = (segons % 3600) / 60;
    hores = segons / 3600;
    dias = hores / 24;
    setmanes = dias / 7;
    segons = segons % 60;

    printf("%d segons equivalen a  %d setmanes, %d dies, %d hores i %d minuts i %d segons.\n", segons, setmanes, dias, hores, minuts, segons);

    return 0;
}