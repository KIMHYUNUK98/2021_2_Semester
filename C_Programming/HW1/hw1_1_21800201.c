#include <stdio.h>

int main() {
    int year = 0, month = 0, day = 0;

    // Input birth year
    printf("Input your birth year: ");
    scanf("%d", &year);
    
    // Input birth month
    printf("Input your birth month: ");
    scanf("%d", &month);

    // Input birth day
    printf("Input your birth day: ");
    scanf("%d", &day);

    // Print birth date
    printf("Your birthday is %d-%d-%d.\n", year, month ,day);

    return 0;
}