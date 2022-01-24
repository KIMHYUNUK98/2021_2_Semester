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

#include "Console.h"

#define TRUE 1
#define FALSE 0

int main()
{
    int screen_width = getWindowWidth();            // getWindowsWidth() returns the width of the current window
    int screen_height = getWindowHeight() - 3;      // getWindowsHeight() returns the height of the current windows
                                                    // -3 is to prevent window scrolling

    // clear screen and display guide
    clrscr();                           // clear screen
    gotoxy(1, 1);                       // move the cursor to the upper left corner    
    printf("Move star by 'j'(left), 'i'(top), 'k'(bottom), and 'l'(right). Press 'q' to quit.\n");
    printf("Currently, the star moves to the right whenever the user types a key.\n");  // erase this line when you complete the mission

    printf("screen size = %d x %d\n", screen_width, screen_height);
    
    // set initial coordinate to the center of the screen
    int x = screen_width / 2;
    int y = screen_height / 2;

    // draw star at the initial coordinate
    gotoxy(x, y);
    putchar('*');                       // putchar(ch) prints a character ch, similar to 'printf("%c", ch);'

    while(1){
        // save the current coordinate
        int oldx = x;
        int oldy = y;

        gotoxy(screen_width, 1);        // move the cursor to the upper right corner
        char key = getch();             // getch() read a key not waiting for the Enter key

        if(key == 'q')
            break;

        // move coordinate according to the key

        // TO DO: update the coordinate of the star by increasing or decreasing x or y.
        //        use the switch-statement (switch(key){...})
        //        the star should move beyond the boundary (x in [1, screen_width], y in [1, screen_height])
        // the following two lines only moves the star in the right. modify them using the switch-statement to complete the mission
        
        switch(key) {
            case 'j':
                if(x > 1)
                    x--;
                break;
            case 'k':
                if(y < screen_height)
                    y++;
                break;
            case 'l':
                if(x < screen_width)
                    x++;
                break;
            case 'i':
                if(y > 1)
                    y--;
                break;
        }
        

        // if the coordinate was updated, move the star
        if(x != oldx || y != oldy){
            // TO DO: erase star at the previous location (print a space character)
            gotoxy(oldx, oldy);
            putchar(' ');
            // TO DO: draw star at the new location (print '*')
            gotoxy(x,y);
            putchar('*');
        }
    }

    gotoxy(1, screen_height);
    printf("Bye!\n");           // this message must be displayed

    return 0;
}
