#include <stdio.h>

int main() {
    char firstname[64] = "NULL";
    char lastname[64] = "NULL";

    // Input first and last name
    printf("Input your first and last name: ");
    scanf("%s %s", firstname, lastname);

    // Print first and last name with Comment
    printf("Nice to meet you, %s %s\n", firstname, lastname);
    printf("Have a great day!\n");


    return 0;
}