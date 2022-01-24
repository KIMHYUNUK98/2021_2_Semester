#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main() 
{
    // Initialize variables
    char str[128];
    char evenstr[128];
    char oddstr[128];
    int even_len = 0;
    int odd_len = 0;
    int num_even = 0;
    int num_odd = 0;
    int sum = 0;

    // Input the sectance from user
    printf("Input a text line: ");
    fgets(str, 128, stdin);

    // Use for loop to find even, odd number
    for(int i = 0 ; i < strlen(str) ; i++) {
        
        // Detect if it is digit or not
        if(isdigit(str[i]) != 0) {
            int num = str[i] - '0';

            // make the even digit string
            if(num % 2 == 0) {
                evenstr[even_len++] = str[i];
            }

            // make the odd digit string
            else if(num % 2 != 0) {
                oddstr[odd_len++] = str[i];
            }
        }
    }

    // put '\0' at the end of even/odd string
    evenstr[even_len] = '\0';
    oddstr[odd_len] = '\0';

    // Display even digits
    if(even_len == 0) printf("no even digit.\n");
    else {
        printf("Even digit:");
        for(int i = 0 ; i < even_len ; i++) {
            printf(" %c", evenstr[i]);
        }
        printf("\n");
    }

    // Display odd digits
    if(odd_len == 0) printf("no odd digit.\n");
    else {
        printf("Odd digit:");
        for(int i = 0 ; i < odd_len ; i++) {
            printf(" %c", oddstr[i]);
        }
        printf("\n");
    }

    // Convert even/odd strings to integer values
    num_even = atoi(evenstr);
    num_odd = atoi(oddstr);

    // Calculate the sum of two number
    sum = num_even + num_odd;

    // Print the result
    printf("\"%s\" and \"%s\" are converted into %d and %d, respectively. Their sum is %d.\n", evenstr, 
            oddstr, num_even, num_odd, sum);
    
    return 0;
}