#include <stdio.h>

int main(void) {
    int n;

    printf("Calculadora de factorials\n");
    printf("Introdueix un valor enter major o igual a 0: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("El valor introduït no és vàlid. Si us plau, introdueix un valor enter major o igual a 0.\n");
        return 1;
    };

    int x = 1;
    int n_og = n;

    while (n > 1) {
        x *= n;
        n--;
    }

    printf("El factorial de %d és: %d\n", n_og, x);
    return 0;
}