#include <stdio.h>
#include <math.h>
#include <string.h>

// Function definition
int bin2dec(char str[128]);

int main()
{
    // Initialize the variables
    char str[128];
    int sum = 0;

    // Input the binary string number from user
    printf("Input a binary string: ");
    scanf("%s", str);

    // Function call and return the decimal number
    sum = bin2dec(str);

    // Print out the result
    printf("\"%s\" = %d (0x%x)", str, sum, sum);

    return 0;
}

// Function
int bin2dec(char str[128]) {

    // Initialize the variable
    int sum = 0;
    int count = 0;
    int len = 0;

    // Get the length of str
    len = strlen(str);

    // Calculate the binary number to decimal number
    for(int i = len-1 ; i >= 0 ; i--) {

        // Return 0 if there are another number 0 and 1
        if(str[i] != '0' && str[i] != '1') {
            return 0;
        }

        // Calculate the decimal number 
        // Convert the char to Int 
        sum += (str[i] - '0') * pow(2, count++);
    }

    // return the Calculated Decimal number
    return sum;
}