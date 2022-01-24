#include <stdio.h>
#include <string.h>

int main() 
{
    // Initialize variables
    char input[256] ={0};
    int len = 0;
    int digit = 0;
    int lower = 0;
    int upper = 0;
    int space = 0;

    // Input the text (using fgets) 
    printf("Input a text: ");
    fgets(input, 255, stdin);

    // Calculate length of text
    len = strlen(input);
    input[len-1] = 0;

    // count digit, lower, upper, space with if-statement in for loop
    for(int i = 0 ; i < len-1 ; i++) {
        if(input[i] >= '0' && input[i] <= '9') {
            digit++;
        } else if(input[i] >= 'a' && input[i] <= 'z') {
            lower++;
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            upper++;
        } else if(input[i] == ' ') {
            space++;
        }
    }
    
    // Print the result
    printf("\"%s\" contains %d space, %d uppercase, %d lowercase, and %d digit characters.\n",
                    input, space, upper, lower, digit);

    return 0;
}