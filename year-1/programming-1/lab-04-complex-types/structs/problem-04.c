#include <stdio.h>
struct Time{
    int hours;
    int minutes;
    int seconds;
};

int totalSeconds(struct Time time) {
    return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

int main() {
    struct Time time;

    printf("Enter hours, minutes and seconds: ");
    scanf("%d %d %d", &time.hours, &time.minutes, &time.seconds);

    printf("Total seconds: %d\n", totalSeconds(time));

    return 0;
}