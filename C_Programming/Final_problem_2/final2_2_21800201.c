/*
    This program rotates even-numbered characters and odd-numbered characters in the opposite directions.
    Complete the code following the instructions.

    Example)
        Input a text: Welcome to HGU!
        len = 16
        Input string:                 [Welcome to HGU! ]
        Rotate right even characters: [!eWclmo eotH UG ]
        Rotate right odd characters:  [! Welcome to HGU]
        Rotate left even characters:  [W leocemt  oGH!U]
        Rotate left odd characters:   [Welcome to HGU! ]
        Rotate even characters right and odd characters left:
        [l oeectm  Go!HWU]
        [oUe te cGm! WolH]
        [eHtU  Ge!cWml oo]
        [to HGU! Welcome ]
        [  Go!HWUl oeectm]
        [Gm! WolHoUe te c]
        [!cWml ooeHtU  Ge]
        [Welcome to HGU! ]
        Rotate odd characters right and even characters left:
        [!cWml ooeHtU  Ge]
        [Gm! WolHoUe te c]
        [  Go!HWUl oeectm]
        [to HGU! Welcome ]
        [eHtU  Ge!cWml oo]
        [oUe te cGm! WolH]
        [l oeectm  Go!HWU]
        [Welcome to HGU! ]

*/

#include <stdio.h>
#include <string.h>

enum RotateOption { EVEN_RIGHT, ODD_RIGHT };
enum Offset { ROTATE_EVEN, ROTATE_ODD };

void RotateString(char string[], int rotate_option);
void RotateLeft(char string[], int offset);
void RotateRight(char string[], int offset);

int main()
{
    char string[256] = "";

    // read a text
    printf("Input a text: ");
    fgets(string, 255, stdin);
    int len = strlen(string);
    string[--len] = 0;

    // TO DO: make string even-length
    //        if len is an odd number, concatenate " " to string and increase len
    if(len % 2 != 0) {
        strcat(string, " ");
        len++;
    }

    printf("len = %d\n", len);
    printf("Input string:                 ");
    printf("[%s]\n", string);

    printf("Rotate right even characters: ");
    RotateRight(string, 0);    
    printf("[%s]\n", string);

    printf("Rotate right odd characters:  ");
    RotateRight(string, 1);
    printf("[%s]\n", string);

    printf("Rotate left even characters:  ");
    RotateLeft(string, 0);
    printf("[%s]\n", string);

    printf("Rotate left odd characters:   ");
    RotateLeft(string, 1);
    printf("[%s]\n", string);

    printf("Rotate even characters right and odd characters left:\n");
    for(int i = 0; i < len / 2; i++){
        RotateString(string, EVEN_RIGHT);
        printf("[%s]\n", string);
    }

    printf("Rotate odd characters right and even characters left:\n");
    for(int i = 0; i < len / 2; i++){
        RotateString(string, ODD_RIGHT);
        printf("[%s]\n", string);
    }

    return 0;
}

void RotateString(char string[], int rotate_option)
{
    int len = strlen(string);
    switch(rotate_option){
        case EVEN_RIGHT:
            RotateRight(string, ROTATE_ODD);
            RotateLeft(string, ROTATE_EVEN);
            break;

        case ODD_RIGHT:
            RotateRight(string, ROTATE_EVEN);
            RotateLeft(string, ROTATE_ODD);
            break;
    }
}

void RotateLeft(char string[], int offset)
{
    /*
        TO DO:
            if offset is zero, rotate the even-numbered characters in the string to the left (0, 2, 4, ...)
            if offset is one, rotate the odd-numbered characters in the string to the left (1, 3, 5, ...)

        Example) if string contains "Welcome to HGU! ",
            RotateLeft(string, 0) changes string to "leocemt  oGH!UW "
            RotateLeft(string, 1) changes string to "Wclmo eotH UG !e"

    */

    if(offset == 0) {
        char temp = string[0];
        for(int i = 0 ; i < strlen(string) - 2 ; i++) {
            if(i % 2 == 0)
                string[i] = string[i+2];
        }
        string[strlen(string)-2] = temp;
    }
    else if(offset == 1) {
        char temp = string[1];
        for(int i = 0 ; i < strlen(string) - 2 ; i++) {
            if(i % 2 == 1) 
                string[i] = string[i+2];
        }
        string[strlen(string)-1] = temp;
    }
}

void RotateRight(char string[], int offset)
{
    /*
        TO DO:
            if offset is zero, rotate the even-numbered characters (0, 2, 4, ...) in the string to the right 
            if offset is one, rotate the odd-numbered characters (1, 3, 5, ...) in the string to the right

        Example) if string contains "Welcome to HGU! ",
            RotateRight(string, 0) changes string to "!eWclmo eotH UG "
            RotateRight(string, 1) changes string to "W leocemt  oGH!U"

    */

    if(offset == 0) {
        char temp = string[strlen(string)-2];
        for(int i = strlen(string) - 1 ; i > 1 ; i--) {
            if(i % 2 == 0)
                string[i] = string[i-2];
        }
        string[0] = temp;
    }
    else if(offset == 1) {
        char temp = string[strlen(string) - 1];
        for(int i = strlen(string) - 1; i > 1 ; i--) {
            if(i % 2 == 1)
                string[i] = string[i-2];
        }
        string[1] = temp;
    }
}
