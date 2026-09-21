#include <stdio.h>

int main(void) {
    int num;
    
    printf("Introdueix un valor enter: ");
    scanf("%d", &num);
    
    printf("El valor introduït en diferents bases son:\n");
    printf("Binària: %b\n", num);
    printf("Octal: %o\n", num);
    printf("Decimal: %d\n", num);
    printf("Hexadecimal: %x\n", num);
    
    return 0;
}