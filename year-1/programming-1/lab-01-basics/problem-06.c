#include <stdio.h>

int main(void) {
    // Definim les variables com a 'float'
    float num_1;
    float num_2;

    printf("Introdueix dos valors per obtenir el seu resultat en diferents formats\n");

    // Per llegir un float amb scanf utilitzem "%f"
    printf("Introdueix el primer valor: ");
    scanf("%f", &num_1);

    printf("Introdueix el segon valor: ");
    scanf("%f", &num_2);

    // Totes les operacions es guarden en variables tipus float
    float result_sum = num_1 + num_2;
    float result_res = num_1 - num_2;
    float result_mul = num_1 * num_2;
    float result_div = num_1 / num_2;

    printf("---- SUMA ----:\n");
    printf("Notació científica: %e\n", result_sum);
    printf("Notació de punt flotant: %f\n", result_sum);
    printf("Format automàtic: %g\n", result_sum);

    printf("---- RESTA ----:\n");
    printf("Notació científica: %e\n", result_res);
    printf("Notació de punt flotant: %f\n", result_res);
    printf("Format automàtic: %g\n", result_res);

    printf("---- MULTIPLICACIÓ ----:\n");
    printf("Notació científica: %e\n", result_mul);
    printf("Notació de punt flotant: %f\n", result_mul);
    printf("Format automàtic: %g\n", result_mul);

    printf("---- DIVISIÓ REAL ----:\n");
    printf("Notació científica: %e\n", result_div);
    printf("Notació de punt flotant: %f\n", result_div);
    printf("Format automàtic: %g\n", result_div);

    return 0;
}