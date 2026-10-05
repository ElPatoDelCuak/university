#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Introdueix el primer valor enter per a A: ");
    scanf("%d", &a);

    printf("Introdueix el segon valor enter per a B: ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("Els valors després del canvi són: A = %d, B = %d\n", a, b);

    return 0;
}