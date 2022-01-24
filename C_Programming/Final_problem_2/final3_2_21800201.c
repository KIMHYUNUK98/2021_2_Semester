/*

    This program displays a greeting message on the screen.
    It is recommended to run it on a large window.

    Complete the program following the instructions.

    Note that the current implementation has a memory leak problem:
        even after completing all instructions marked as 'TO DO',
        a dynamically allocated memory block remains (not deallocated) until the program ends.
    Fix the memory leak problem.

    Compilation:
        on Windows: gcc final3_2_problem.c Console.c -D_WINDOWS
        on Mac: gcc final3_2_problem.c Console.c -D_MAC

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Console.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define MESSAGE_CENTER "Merry Christmas and Happy New Year!"
#define MESSAGE_BOTTOM "God loves you and has a wonderful plan for your life!"

#define MAX_HEIGHT 1024
typedef struct {
    int width, height;
    char *buffer[MAX_HEIGHT];          // for dynamic allocation of 2D array
} ScreenBuffer;

ScreenBuffer* CreateBuffer(int width, int height);      // constructor
void FreeBuffer(ScreenBuffer *sb);                      // destructor
void DisplayBuffer(ScreenBuffer *sb);
void FillBuffer(ScreenBuffer *sb, char ch);
void BufferPrintXY(ScreenBuffer *sb, int sx, int sy, int margin, char string[]);

char GetRandomCharacter();
void HideScreen(int width, int height);

int main()
{
    srand(time(NULL));

    int screen_width = getWindowWidth();
    int screen_height = getWindowHeight() - 3;
  
    clrscr();    
    printf("screen size = %dx%d\n", screen_width, screen_height);

    // read the name of the user
    char name[256] = "";
    printf("What's your name? ");
    fgets(name, 255, stdin);
    name[strlen(name) - 1] = 0;

    char recepient[256] = "";
    sprintf(recepient, "For %s,", name);
    
    // create a screen buffer
    ScreenBuffer *sb = CreateBuffer(screen_width, screen_height);
    
    FillBuffer(sb, 0);      // fill the buffer with random graphical characters
    
    // for the recepient
    BufferPrintXY(sb, 3, 2, 1, recepient);

    // center
    BufferPrintXY(sb, (screen_width - strlen(MESSAGE_CENTER)) / 2, screen_height / 2, 2, MESSAGE_CENTER);

    // bottom
    BufferPrintXY(sb, (screen_width - strlen(MESSAGE_BOTTOM)) / 2, screen_height - 3, 1, MESSAGE_BOTTOM);
    
    // show the buffer on the screen
    DisplayBuffer(sb);

    // deallocate screen buffer
    FreeBuffer(sb);

    return 0;
}

ScreenBuffer* CreateBuffer(int width, int height)
{
    if(height > MAX_HEIGHT){        // for safety
        printf("height (%d) is bigger than MAX_HEIGHT\n", height);
        return NULL;
    }

    ScreenBuffer *sb = (ScreenBuffer*)malloc(sizeof(ScreenBuffer));
    // TO DO: On memory allocation failure, display an error message and return NULL.
    if(sb == NULL) {
        printf("THERE IS AN ERROR IN THIS LINE %d\n", __LINE__);
        return NULL;
    }


    // TO DO: For each i in range [0, height - 1], allocate a block of memory of size 'width' and store the address in sb->buffer[i] 
    //        On memory allocation failure, display an error message and return NULL.
    //        Hint) See FreeBuffer() and DisplayBuffer() to understand the memory structure.
    for(int i = 0 ; i < height ; i++) {
        sb->buffer[i] = (char*)malloc(sizeof(char) * width);
        if(sb->buffer[i] == NULL) {
            printf("THERE IS AN ERROR IN THIS LINE %d\n", __LINE__);
            return NULL;
        }
    }
    
    // TO DO: set sb->width and sb->height to width and height, respectively.    
    sb->width = width;
    sb->height = height;

    return sb;
}

void FreeBuffer(ScreenBuffer *sb)
{
    for(int i = 0; i < sb->height; i++)
        free(sb->buffer[i]);        // the length of sb->buffer[i] is sb->width
}

void DisplayBuffer(ScreenBuffer *sb)
{
    clrscr();
    for(int i = 0; i < sb->height; i++){
        gotoxy(1, i + 1);
        for(int j = 0; j < sb->width; j++)
            putchar(sb->buffer[i][j]);
    }
}

void FillBuffer(ScreenBuffer *sb, char ch)
{
    // TO DO: Fill the screen buffer with ch.
    //        If ch is zero, fill the buffer with random graphical characters generated by GetRandomCharacters()
    if(ch == 0) {
        for(int i = 0 ; i < sb->height ; i++) {
            for(int j = 0 ; j < sb->width ; j++) {
                sb->buffer[i][j] = GetRandomCharacter();
            }
        }
    }
}

void BufferPrintXY(ScreenBuffer *sb, int sx, int sy, int margin, char string[])
// Writes a string on a screen buffer starting from the specified coordinate (sx, sy)
{      
    int len = strlen(string);

    // clear region around the string
    int left = MAX(0, sx - margin * 2);
    int top = MAX(0, sy - margin);
    int right = MIN(sb->width, sx + len + margin * 2);
    int bottom = MIN(sb->height, sy + 1 + margin);

    for(int y = top; y < bottom ; y++){
        for(int x = left; x < right; x++)
            sb->buffer[y][x] = ' ';
    }

    // TO DO: write string on the buffer starting from (sx, sy)
    int count = 0;
    for(int i = sx ; i < sx + len ; i++) {
        sb->buffer[sy][i] = string[count++];
    }
}

void HideScreen(int width, int height)
{
    gotoxy(1, 1);

    int i = 0, j = 0;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            char ch = GetRandomCharacter();
            putchar(ch);
        }
    }
}

char GetRandomCharacter()
{
    char ch = 0;
    do
        ch = rand() % 128;
    while (!isgraph(ch));

    return ch;
}
