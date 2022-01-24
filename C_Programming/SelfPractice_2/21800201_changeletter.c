/*
문자열을 입력하고 사용자가 문자 2개를 입력하면 해당 문자를 변경하고
변경된 문자열을 다시 입력받아 대문자를 소문자로, 소문자를 대문자로 변경하고 출력하라
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function define
void changeString(char str[128], char c1, char c2);
void changeUpper(char str[128]);

int main() 
{
    // Initialize variables
    char str[128];
    char c1 = 'A';
    char c2 = 'A';

    // Input the senctance
    printf("Write sentance: ");
    gets(str);

    // Input two characters
    printf("Input the two character: ");
    scanf("%c %c", &c1, &c2);

    // function call
    changeString(str, c1, c2);
    changeUpper(str);

    return 0;
}

void changeString(char str[128], char c1, char c2) {
    
    // Initialize variable
    int len = 0;

    // get length of string
    len = strlen(str);

    //change c1 and c2 with for loop
    for(int i = 0 ; i < len ; i++) {
        if(str[i] == c1) {
            str[i] = c2;
        } else if(str[i] ==c2) {
            str[i] = c1;
        }
    }

    // Print the result
    printf("CHANGING TWO CHARACTER\n");
    printf("Changing result : %s\n", str);
}

void changeUpper(char str[128]) {
    
    // Initialize the variable
    int len = 0;

    // get length of string
    len = strlen(str);

    // Change lower to upper and vice versa (using for loop)
    for(int i = 0 ; i < len ; i++) {
        if(islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if(isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    // Print the result
    printf("CHANGING UPPER and LOWER\n");
    printf("Changing result : %s\n", str);
}