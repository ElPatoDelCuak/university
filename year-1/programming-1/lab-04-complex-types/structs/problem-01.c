#include <stdio.h>
struct Product{
    int code;
    char name[50];
    float price;
    int discount;
};

int main() {
    struct Product producte = {1, "Producte", 100.0f, 10};
    float preuFinal = producte.price * (1 - producte.discount / 100.0f);

    printf("Codi: %d\n", producte.code);
    printf("Preu final: %.2f\n", preuFinal);

    return 0;
}