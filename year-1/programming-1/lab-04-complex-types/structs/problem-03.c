#include <stdio.h>
struct Rectangle{
    int width;
    int height;
};

int calculate_area(struct Rectangle rect) {
    return rect.width * rect.height;
}

int main() {
    struct Rectangle rectangles[3];
    int count = 0;

    for (int i = 0; i < 3; i++) {
        printf("Introdueix l'amplada i l'alçada del rectangle %d: ", i + 1);
        scanf("%d %d", &rectangles[i].width, &rectangles[i].height);

        if (calculate_area(rectangles[i]) > 20) {
            count++;
        }
    }

    printf("Hi ha %d rectangles amb una àrea superior a 20.\n", count);
    return 0;
}