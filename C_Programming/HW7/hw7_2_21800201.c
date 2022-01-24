/*

    Read a text line from the user. Then, separate and randomly shuffle the characters in each word in the text. 

    Example)
        Input a text: Welcome to Handong Global University      // the user types "Welcome to Handong Global University"
        word 0) Welcome
        word 1) to
        word 2) Handong
        word 3) Global
        word 4) University
        shuffled text: lmoWece ot Hndnaog oGllba itvsryniUe     // the result can be different from this example

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void GetSubstring(char str[], int from, int to, char result[]);
void ShuffleWord(char str[], int from, int to);

int main()
{
    srand(time(NULL));

    char text[256] = "";     
    char word[128] = "";

    // read a text line from the user
    printf("Input a text: ");
    fgets(text, 255, stdin);
    int len = strlen(text);
    text[--len] = 0;

    int word_start = 0;
    char prev = ' ';
    int start = 0;
    int count = 0;

    // TO DO: detect the start and end position of each word. retrieve each word and shuffle it
    //        use the isspace() function to decide whether a character is a white space character or not
    
    // repeat (len + 1) times increasing i from 0
    for(int i = 0 ; i <= len ; i++) {
        // if the previous character is a white space character and text[i] is not,
        if(isspace(prev) != 0 && isspace(text[i]) == 0)
            // mark the current location as the start of a new word by copying i to start
            start = i;
            //printf("start = %d\n", start);

        // if the previous character is not a white space character and text[i] is a white space character or the null character,
        if(isspace(prev) == 0 && (isspace(text[i]) != 0 || text[i] == '\0')) {
            // retrieve the characters in [start, i) into word by calling GetSubstring()
            GetSubstring(text, start, i, word);
            // print word with the counter
            printf("word %d) %s\n", count, word);
            // increase the counter
            count++;
            // shuffle the characters in [start, i) by calling SuffleWord()
            ShuffleWord(text, start, i);
        }
        // copy text[i] to prev
        prev = text[i];
    }
    
    printf("shuffled text: %s\n", text);

    return 0;
}

void GetSubstring(char str[], int from, int to, char result[])
// make a word composed of characters of str in range [from, to)
// the notation [A, B) means  "greater than or equal to A, and less than B"
// e.g. GetSubstring("Hello, World!", 0, 5) sets "Hello" to result
// e.g. GetSubstring("Hello, World!", 7, 12) sets "World" to result
{
    // TO DO: implement this function
    int count = 0;
    // copy all characters in [from, to) to result using the for-statement
    for(int i = from ; i < to ; i++) 
        result[count++] = str[i];
    // put '\0' at the (to-from)th position of result
    result[to-from] = '\0';
}

void ShuffleWord(char str[], int from, int to)
// randomly shuffle the characters of str in range [from, to)
// e.g. ShuffleWorld("Hello, World!", 7, 12) shuffles the characters in the "World" part
{
    // TO DO: implement this function

    // repeat (to - from) times increasing i from 'from' to 'to'
    for(int i = from ; i < to ; i++) {
        // randomly select a number j in range [from, to) using rand()
        int j = rand() % (to-from) + from;
        // exchange str[i] and str[j]
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
