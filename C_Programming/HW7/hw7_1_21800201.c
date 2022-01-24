/*
    Read an integer and convert into a string of numbers

    Example)
        Input a number: 2847            // the user types 2847
        digit_count = 4                 // 2847 is composed of 4 digits
        total_len = 20                  // the length of num_str
        num_str = two eight four seven  // conversion result

    Example)
        Input a number: 298785
        digit_count = 6
        total_len = 31
        num_str = two nine eight seven eight five

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// digit strings
char DigitString[10][16] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

// the length of the digit strings
int DigitStringLength[] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };

int CountDigits(int num);
int GetDigit(int num, int position);

int main()
{
    int num = 0;

    // read a number
    printf("Input a number: ");
    scanf("%d", &num);

    // get # of digits by calling CountDigits()
    int digit_count = CountDigits(num);
    printf("digit_count = %d\n", digit_count);


    // TO DO: compute the total length of the number string
    int total_len = 0;

    // repeat digit_count times increasing i from 0
    for(int i =0 ; i < digit_count ; i++) {
        // get the length of the string for the i-th digit of num and add it to total_len
        total_len += DigitStringLength[GetDigit(num, i)];
        // if i is not (digit_count - 1), add 1 to total_len for the space character
        if(i != digit_count-1) total_len++;
    }
    
    printf("total_len = %d\n", total_len);


    char *num_str = NULL;
    // TO DO: allocate (total_len + 1) bytes of memory
    // don't forget to check memory allocation failure
    num_str = (char*)malloc(total_len + 1);
    if(num_str == NULL) {
        printf("Failed to open file in line%d\n", __LINE__);
        exit(-1);
    }

    // initialize num_str by an empty string
    num_str[0] = 0;

    // TO DO: build the string of numbers by concatenating the digit strings and space characters
    // repeat digit_count times decreasing i from (digit_count - 1) to 0
    for(int i = digit_count - 1 ; i >= 0 ; i--) {
        // concatenate the digit string for the i-th digit to num_str using strcat()
        strcat(num_str, DigitString[GetDigit(num,i)]);
        // if i is not zero, concatenate " " to num_str
        if(i != 0) strcat(num_str, " ");
    }

    printf("num_str = %s\n", num_str);


    // TO DO: deallocate the dynamic memory block
    free(num_str);

    
    return 0;
}

int CountDigits(int num)
// returns the number of digits in num
// e.g. CountDigits(0) returns 0
// e.g. CountDigits(123) returns 3
// e.g. CountDigits(53214) returns 5
{
    // TO DO: implement this function
    int len = 0;
    int count = 1;

    if(num == 0) 
        return 0;
    if(num != 0)
        return CountDigits(num / 10) + 1;
}

int GetDigit(int num, int position)
// return the p-th digit from the right (GetDigit(num, 0) returns the least significant digit)
// e.g. GetDigit(123, 0) returns 3
// e.g. GetDigit(123, 1) returns 2
// e.g. GetDigit(123, 2) returns 1
{
    // TO DO: implement this function
    int ret = 0;

    for(int i = 0 ; i <= position ; i++) {
        ret = num % 10;
        num = num / 10;
    }

    return ret;
}
