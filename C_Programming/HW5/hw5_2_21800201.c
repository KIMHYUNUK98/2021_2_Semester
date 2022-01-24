/*
    The following code move a star in the right direction.
    Extend this code to move the star in four directions according to the input key.
            j: move left
            i: move top
            k: move bottom            
            l: move right
            q: quit

    Compilation: copy Console.h and Console.c into the current directory and run the following command:
        Windows:    gcc hw5_1.c Console.c -D_WINDOWS
        MAC:        gcc hw5_1.c Console.c -D_MAC

*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

#define MAX_LEN 512

#define RIGHT 1
#define LEFT (-1)           // () is recommended for safety

void StretchString(char str[], int target_len);
void ShiftString(char str[], int shift);

int main()
{
    int screen_width = getWindowWidth();            // getWindowsWidth() returns the width of the current window
    int screen_height = getWindowHeight() - 3;      // getWindowsHeight() returns the height of the current windows
                                                    // -3 is to prevent window scrolling
    clrscr();
    printf("screen size = %d x %d\n", screen_width, screen_height);

    // read a text line
    char text[MAX_LEN] = "";
    printf("Input a text: ");
    fgets(text, MAX_LEN - 1, stdin);
    int len = strlen(text);
    text[--len] = 0;

    // TO DO: read shift from the user. if the user types a value not in { -1, 1 }, read again and again using the do-while statement
    int shift = 0;
    do {
        printf("Input shift(1: RIGHT, -1:LEFT): ");
        scanf("%d", &shift);

    } while(shift != 1 && shift != -1);


    // check StretchString()
    printf("input = [%s]\n", text);
    StretchString(text, screen_width - 2);
    printf("stretched string = \n[%s]\n", text);

    // check ShiftString()
    ShiftString(text, shift);
    printf("shifted string = \n[%s]\n", text);

    printf("Press CTRL-C to stop.\n");
    MyPause();

    // display text in the middle row
    gotoxy(2, screen_height / 2);
    printf("%s", text);

    // repeat until the user types CTRL-C
    while(1){
        // shift text
        ShiftString(text, shift);
        
        // display text in the middle row
        gotoxy(2, screen_height / 2);
        printf("%s", text);

        // move the cursor at the upper right corner
        gotoxy(screen_width, screen_height);
        fflush(stdout);

        // sleep for 50 msec.
        MySleep(50);
    }

    return 0;
}

void StretchString(char str[], int target_len)
// TO DO: Stretch string by adding space so that its length is target_len
//    e.g., if str is "hello", StretchString(str, 10) modifies str to "hello     "
{
    // fill the end of the str (from len to target_len - 1) with ' '
    for(int i = strlen(str) ; i <= target_len - 1 ; i++) {
        str[i] = ' ';
    }
    // put the null character ('\0') to mark the end of the string
    str[target_len] = '\0';
}

void ShiftString(char str[], int shift)
// TO DO: If shift is +1, shift str in the right.
//        If shift is -1, shift str in the left.
//  e.g., If str is "hello     ",
//        ShiftString(str, 1);  modifies str to " hello    "
//        ShiftString(str, -1); modifies str to "ello     h"
{
    int i = 0;
    char temp = 0;
    int len = strlen(str);

    switch(shift){
    case RIGHT:             // shift right
        // save the last character in temp
        temp = str[len-1];

        // shift the interior characters to the right by moving str[i-1] to str[i] for i from (len - 1) to 1
        for(int i = len - 1 ; i > 0 ; i--) {
            str[i] = str[i-1];
        }

        // put the saved last character at the beginning
        str[0] = temp;

        break;

    case LEFT:            // shift left
        // save the first character
        temp = str[0];

        // shift the interior characters to the left by moving str[i+1] to str[i] for i from 0 to (len - 1)
        for(int i = 0 ; i < len - 1 ; i++) {
            str[i] = str[i+1];
        }

        // put the saved first character at the end
        str[len-1] = temp;

        break;
    }
}
