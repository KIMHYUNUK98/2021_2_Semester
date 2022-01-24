#include <stdio.h>

int main() 
{
    // Initialize the variables
    int num = 0;
    int mult = 0;

    // Read the number
    printf("Input a number between 1 and 9: ");
    scanf("%d", &num);

    // Print the Multiplication Table
    for(int i = 1 ; i <= 9 ; i++) {
        mult = num * i;
        printf("%d * %d = %d\n", num, i , mult);
    }

    return 0;
}