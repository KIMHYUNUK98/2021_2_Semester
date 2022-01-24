#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function define
int CountChar(char str[128], char c1);

int main()
{
    // Initialize variables
    char str[128];
    char c1 = 'A';
    int count = 0;

    // Infinite while loop for Read the data from user
    while(1) {

        // Read the sentance from the user
        printf("Input a text line: ");
        fgets(str, 128, stdin);
    
        // if str has '\n' break the loop
        if(*str == '\n') {
            printf("Bye!");
            break;
        }

        // Read the find character from the user
        printf("Character to find: ");
        scanf("%c", &c1);

        // Remove the '\n' data from each sentance
        str[strlen(str)-1] = '\0';
        getchar();

        // function call and return the count data.
        int count = CountChar(str, c1);

        // Print out the result
        printf("\"%s\" contains %d '%c' characters\n", str, count, c1);
    }

    return 0;
}

// Function
int CountChar(char str[128], char c1) {

    // Initialize the variable
    int count = 0;

    // Check the character whether it is same or not
    for(int i = 0 ; i < strlen(str) ; i++) {
        // Change each charcter into lowercase
        char c2 = tolower(c1);
        char c3 = tolower(str[i]);

        // If They are same increment the count variable
        if(c2 == c3) {
            count++;
        }
    }

    // return the count value
    return count;
}