/*
    1. Read a text message from the user.

    2. Print the message at five locations of a text buffer.
        - five locations: center, top-left, top-right, bottom-left, bottom-right)
        - implement PrintBuffeXY() function that prints a text message on a 2D text array from the specified coordinate)

    3. Show the content of the buffer on the screen from right to left
        - implement ShowBufferFromRight()

    Compilation
        Windows:  gcc hw6_2.c Console.c -D_WINDOWS
        MAC:      gcc hw6_2.c Console.c -D_MAC

*/

#include <stdio.h>
#include <string.h>

#include "Console.h"

#define MAX_WIDTH 200
#define MAX_HEIGHT 100

void PrintBufferXY(char buffer[][MAX_WIDTH], int x, int y, char mesg[]);
void FillScreen(int width, int height, char ch);
void ShowBuffer(char buffer[][MAX_WIDTH], int width, int height);
void ShowBufferFromRight(char buffer[][MAX_WIDTH], int width, int height);

int main()
{
    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;
    printf("screen size = %d x %d\n", screen_width, screen_height);

    char buffer[MAX_HEIGHT][MAX_WIDTH] = { 0 };

    // TO DO: fill the buffer with the space characters (' ')
    //        fill only the region from buffer[0][0] to buffer[screen_height-1][screen_width-1];
    for(int i = 0 ; i < screen_height ; i++) {
        for(int j = 0 ; j < screen_width ; j++) {
            buffer[i][j] = ' ';
        }
    }
    

    // read a text message into the buffer (use fgets())
    char message[256] = "";
    printf("Input a message: ");
    fgets(message, 255, stdin);
    int len = strlen(message);
    message[--len] = 0;

    // print the message on the buffer at the center, top-left, top-right, bottom-left, and bottom-right coordinates
    PrintBufferXY(buffer, 1, 1, message);                           // top-left
    PrintBufferXY(buffer, screen_width - len, 1, message);          // top-right

    PrintBufferXY(buffer, (screen_width - len) / 2, screen_height / 2, message);    // center

    PrintBufferXY(buffer, 1, screen_height, message);               // bottom-right
    PrintBufferXY(buffer, screen_width - len, screen_height, message);  // bottom-right

    // show the buffer on the screen
    ShowBuffer(buffer, screen_width, screen_height);
    gotoxy(1, screen_height + 1);
    MyPause();              // Wait for the Enter key

    FillScreen(screen_width, screen_height, '#');       // fill the screen with '#'

    // show the message from the right of the screen
    ShowBufferFromRight(buffer, screen_width, screen_height);

    gotoxy(1, screen_height + 1);
    MyPause();

    return 0;
}

void PrintBufferXY(char buffer[][MAX_WIDTH], int x, int y, char mesg[])
// TO DO: implement this function
//        print mesg to the buffer from (x - 1, y - 1)   (-1 is the difference between array indices and text coordinate)
{
    int len = strlen(mesg);

    // TO DO: write your code here
    for(int i = 0 ; i < len ; i++) {
        buffer[y-1][x-1 + i] = mesg[i];
    }

}

void ShowBuffer(char buffer[][MAX_WIDTH], int width, int height)
// shows the buffer on the screen
{
    int x = 0, y = 0;

    for(y = 0; y < height; y++){
        gotoxy(1, y + 1);
        for(x = 0; x < width; x++)
            putchar(buffer[y][x]);
    }
}

void FillScreen(int width, int height, char ch)
// fills the screen with ch
{
    gotoxy(1, 1);
    int x = 0, y = 0;
    for(y = 0; y < height; y++){
        for(x = 0; x < width; x++)
            putchar(ch);
    }
}

void ShowBufferFromRight(char buffer[][MAX_WIDTH], int width, int height)
// TO DO: implement this function
//        shows the buffer from right to left
{
    // repeat decreasing x from (width - 1) to 0
    for(int x = width-1 ; x >= 0 ; x--) {
        // repeat increasing y from 0 to height
        for(int y = 0 ; y < height ; y++) {
            // move cursor to (x + 1, y + 1)
            gotoxy(x+1, y+1);
            // print buffer[y][x]
            putchar(buffer[y][x]);
        }
        // wait for 10 msec by calling MySleep(10)
        MySleep(10);
    }
}

