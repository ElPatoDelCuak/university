#include <stdio.h>

int main() {
    char digit;
    int valor_enter;

    printf("Introdueix un dígit hexadecimal (0-F): ");
    scanf(" %c", &digit);

    if (!((digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F') || (digit >= 'a' && digit <= 'f'))) {
        printf("Error: El caràcter introduït no és un dígit hexadecimal.\n");
        return -1;
    }

    if (digit >= '0' && digit <= '9') {
        valor_enter = digit - '0';
    } else if (digit >= 'A' && digit <= 'F') {
        valor_enter = digit - 'A' + 10;
    } else if (digit >= 'a' && digit <= 'f') {
        valor_enter = digit - 'a' + 10;
    }

    printf("\nDígit introduït: %c\n", digit);
    printf("Codi intern (ASCII): %d\n", digit);
    printf("Valor enter decimal: %d\n", valor_enter);

    return 0;
}
