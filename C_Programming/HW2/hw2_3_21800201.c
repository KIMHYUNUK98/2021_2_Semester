#include <stdio.h>

int main() {

    // Declare the number and Initiate
    char str[64] = "NULL";
    int first_digit = 0;
    int second_digit = 0;
    int third_digit = 0;
    int forth_digit = 0;
    int binary_num = 0;

    // Read the str in char array
    printf("Input a 4-digit bnary number: ");
    scanf("%s", str);

    // Convert str(binary number) to decimal number
    forth_digit = (str[0] - '0') * 8;
    third_digit = (str[1] - '0') * 4;
    second_digit = (str[2] - '0') * 2; 
    first_digit = (str[3] - '0') * 1; 

    // Calculate the sum of each number.
    binary_num = first_digit + second_digit + third_digit + forth_digit;

    // Print the result
    printf("%s = %d (0x%x)", str, binary_num, binary_num);

    return 0;
}