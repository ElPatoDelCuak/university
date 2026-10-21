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

    int start = a;
    int end = b;

    if (start > end) {
        int temporary = start;
        start = end;
        end = temporary;
    }

    int result = 0;
    int current = start;

    while (current <= end) {
        result += current;
        current++;
    }
    
    printf("La suma del interval de %d a %d és: %d\n", a, b, result);

    return 0;
}