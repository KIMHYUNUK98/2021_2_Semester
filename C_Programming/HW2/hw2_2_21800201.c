#include <stdio.h>

int main() {

    // Declare the variables and Initiate
    int number = 0;
    int first_digit = 0;
    int second_digit = 0;
    int third_digit = 0;

    // Read the 3-digit number
    printf("Input a 3 digit number: ");
    scanf("%d", &number);

    // Calculate each digit into each variable
    first_digit = number % 10;
    second_digit = number / 10 % 10;
    third_digit = number /100 % 10;

    // Print the reversed 3-digit number using each digit
    printf("Reversed number = %d%d%d\n", first_digit, second_digit, third_digit);

    return 0;
}