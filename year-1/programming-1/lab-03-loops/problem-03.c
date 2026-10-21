#include <stdio.h>

int main(void) {
    int a, b;

    printf("Introdueix un valor enter major o igual a 0: ");
    scanf("%d", &a);

    printf("Introdueix un valor enter major o igual a 0: ");
    scanf("%d", &b);

    if (a < 0 || b < 0) {
        printf("El valor introduït no és vàlid. Si us plau, introdueix un valor enter major o igual a 0.\n");
        return 1;
    }

    return 0;
}