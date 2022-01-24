/*
    Write a C program that reads a hexadicimal string and converts it into the corresponding integer value.
        - Implement my_strlen() function that returns the length of a string as the standard function strlen()
        - DO NOT use strlen().
        - Make the output messages as similar to the examples as possible.

        - Use isdigit() to decide whether a character is a digit.
        - Use isalpha() to decide whether a character is an alphabet, if necessary
        - Use tolower() to convert uppercase characters into lowercase.

Example)
    Input a hexadecimal number: adf     // the user typed "adf"
    The length of "adf" = 3
    "adf" = 2783 (0xadf)

Example)
    Input a hexadecimal number: 394     // the user typed "394"
    The length of "394" = 3
    "394" = 916 (0x394)

Example)
    The length of "asdf" = 4             // the user typed "asdf"
    s is not a hexadecimal digit!
    "asdf" = 0 (0x0)

*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int my_strlen(const char string[]);

int main()
{
    char hex_str[32] = "";
    int len = 0;

    // read a hexadecimal number as a string using scanf()
    printf("Input a hexadecimal number: ");
    scanf("%s", hex_str);

    // get the length of hex_str by calling my_strlen(), not strlen()
    len = my_strlen(hex_str);

    // display the length of hex_str
    printf("The length of \"%s\" = %d\n", hex_str, len);


    // initialize value by 0 and place by 1
    int value = 0;
    int place = 1;

    for(int i = len-1 ; i >= 0 ; i--) {
        char number = hex_str[i];
        number = tolower(hex_str[i]);

        if(isdigit(number)) {
            if(number == '1') {
                value += 1 * pow(16, len-1-i);
            } else if(number == '2') {
                value += 2 * pow(16, len-1-i);
            } else if(number == '3') {
                value += 3 * pow(16, len-1-i);
            } else if(number == '4') {
                value += 4 * pow(16, len-1-i);
            } else if(number == '5') {
                value += 5 * pow(16, len-1-i);
            } else if(number == '6') {
                value += 6 * pow(16, len-1-i);
            } else if(number == '7') {
                value += 7 * pow(16, len-1-i);
            } else if(number == '8') {
                value += 8 * pow(16, len-1-i);
            } else if(number == '9') {
                value += 9 * pow(16, len-1-i);
            }
        } else if(number == 'a') {
            value += 10 * pow(16, len-1-i);
        } else if(number == 'b') {
            value += 11 * pow(16, len-1-i);
        } else if(number == 'c') {
            value += 12 * pow(16, len-1-i);
        } else if(number == 'd') {
            value += 13 * pow(16, len-1-i);
        } else if(number == 'e') {
            value += 14 * pow(16, len-1-i);
        } else if(number == 'f') {
            value += 15 * pow(16, len-1-i);
        } else {
            printf("%c is not hexadecimal digit!\n", hex_str[i]);
            value = 0;
            break;
        }
    }

    printf("\"%s\" = %d (0x%x)", hex_str, value, value);
    // repeat on i from (length - 1) to 0, decreasing i
        // convert the i-th character into an integer using isdigit()
        //  e.g., '0'->0, '9'->9, 'A' -> 10, 'b' -> 11, C -> 12, 'd' -> 14, 'f' -> 15
        // hint) converting 'b' into number: 'b' - 'a' + 10 = 11
        //       converting 'd' into number: 'd' - 'a' + 10 = 13
        // hint) use tolower() to ignore case

        // if the i-th character is not hexadecimal digit,
            // print an error message indicating the character is not a hexadecimal digit
            // set value to zero
            // break the loop


        // add (place * <the converted digit>) to value

        // multiply place by 16

    // display the conversion result in decimal (%d) and hexadecimal (%x) format


    return 0;
}

int my_strlen(const char string[])
// TO DO: implement this function not using strlen().
{
    // initialize length by zero
    int len = 0;

    // increase length until string[length] is '\0' using the while-statement
    while(string[len] != '\0') {
        len++;
    }
    // return length
    return len;
}
