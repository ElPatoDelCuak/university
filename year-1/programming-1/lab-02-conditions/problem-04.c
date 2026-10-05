#include <stdio.h>

int main() {
    char digit;
    int valor_enter;

    printf("Introdueix un dígit decimal (0-9): ");
    scanf(" %c", &digit);

    if (digit < '0' || digit > '9') {
        printf("Error: El caràcter introduït no és un dígit decimal.\n");
        return -1;
    }

    valor_enter = digit - '0';

    printf("\nDígit introduït: %c\n", digit);
    printf("Codi intern (ASCII): %d\n", digit);
    printf("Valor enter decimal: %d\n", valor_enter);

    return 0;
}
