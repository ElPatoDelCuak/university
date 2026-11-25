#include <stdio.h>
struct Student{
    char name[50];
    int first_exam;
    int second_exam;
};

int calcular_mitjana(struct Student student) {
    return (student.first_exam + student.second_exam) / 2;
}

int main() {
    struct Student student1 = {"Eduard", 6, 7};
    struct Student student2 = {"Marc", 6, 9};

    int mitjana1 = calcular_mitjana(student1);
    int mitjana2 = calcular_mitjana(student2);

    if (mitjana1 > mitjana2) {
        printf("Eduard té una mitjana més alta que Marc.\n");
    } else if (mitjana1 < mitjana2) {
        printf("Marc té una mitjana més alta que Eduard.\n");
    } else {
        printf("Eduard i Marc tenen la mateixa mitjana.\n");
    }

    return 0;
}