/*
    This program reads two strings and decides whether the second string is an anagram of the first string.
    An anagram is a word or phrase formed by changing the order of the letters in another word or phrase.
    For example, `triangle' is an anagram of `integral'.

    Complete the program following the instructions.

    In comparison, the program should ignore all whitespace characters, such as space and tab.
    (Use isspace() to detect the whitespace characters.)
   

    Example)
        Input the first string: triangle        // the user typed "triangle"
        Input the second string: integral       // the user typed "integral"
        Input strings:
                str1 = [triangle]
                str2 = [integral]
        After removing space:
                str1_working = [triangle]
                str2_working = [integral]
        After sorting characters:
                str1_working = [aegilnrt]
                str2_working = [aegilnrt]
        [integral] is an anagram of [triangle].

    Example)
        Input the first string: Welcome to HGU!        // the user typed "Welcome to HGU!"
        Input the second string: HGU Welcome to !      // the user typed "HGU Welcome to !"
        Input strings: 
                str1 = [Welcome to HGU!]
                str2 = [HGU Welcome to !]
        After removing space:
                str1_working = [WelcometoHGU!]
                str2_working = [HGUWelcometo!]
        After sorting characters:
                str1_working = [!GHUWceelmoot]
                str2_working = [!GHUWceelmoot]
        [HGU Welcome to !] is an anagram of [Welcome to HGU!]!

    Example)
        Input the first string: triangle        // the user typed "triangle"
        Input the second string: integer        // the user typed "integer"
        Input strings:
                str1 = [triangle]
                str2 = [integer]
        After removing space:
                str1_working = [triangle]
                str2_working = [integer]
        After sorting characters:
                str1_working = [aegilnrt]
                str2_working = [eeginrt]
        [integer] is NOT an anagram of [triangle]!

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void MakeCharacterHistogram(char string[], int histogram[256]);
void DisplayCharacterHisogram(int histogram[]);
int AreSameArrays(int array1[], int array2[], int size);

int main()
{
    char str1[256] = "";
    char str2[256] = "";

    // read two strings, str1 and str2
    printf("Input the first string: ");
    fgets(str1, 255, stdin);
    str1[strlen(str1) - 1] = 0;

    printf("Input the second string: ");
    fgets(str2, 255, stdin);    
    str2[strlen(str2) - 1] = 0;

    printf("Input strings: \n");
    printf("\tstr1 = [%s]\n", str1);
    printf("\tstr2 = [%s]\n", str2);

    // count characters in the two strings
    int histogram1[256];       // histogram1[c] counts the character c in str1 (for all characters c in [0, 255])
    int histogram2[256];      // histogram1[c] counts the character c in str2 (for all characters c in [0, 255])

    MakeCharacterHistogram(str1, histogram1);
    MakeCharacterHistogram(str2, histogram2);

    printf("character histogram from str1: \n");
    DisplayCharacterHisogram(histogram1);

    printf("character histogram from str2: \n");
    DisplayCharacterHisogram(histogram2);
    
    if(AreSameArrays(histogram1, histogram2, 256))
        printf("[%s] is an anagram of [%s]!", str2, str1);
    else
        printf("[%s] is NOT an anagram of [%s]!", str2, str1);

    return 0;
}

void MakeCharacterHistogram(char string[], int histogram[256])
{
    /*
        TO DO: Make the histogram of characters in string
               histogram[c] should count character c, for all c in [0, 255]
               e.g., histogram['A'] contains the frequency of 'A' in string.

               - Do not separate uppercase and lowercase characters. (e.g., count 'a' as 'A')
               - Do not count whitespace characters. (for each whitespace character c, histogram[c] should be zero.)
                 (Use the isspace() function to decide whether a character is whitespace or not)
    */
    for(int i = 0 ; i < 256 ; i++) {
        histogram[i] = 0;
    }
    int len = strlen(string);
    for(int i = 0 ; i < len ; i++) {
        if(isspace(string[i]) == 0) {
            histogram[toupper(string[i])]++;
        }
    }
}

void DisplayCharacterHisogram(int histogram[])
{
    // TO DO: Read this function and understand what a histogram should be like.
    for(int i = 0; i < 256; i++){
        if(histogram[i] != 0)
            printf("histogram[%d] (\'%c\') = %d\n", i, i, histogram[i]);
    }
}

int AreSameArrays(int array1[], int array2[], int size)
{
    /*
        TO DO: If the two arrays contain the same numbers, i.e., array1[i] == array2[i] for all i in range [0, size-1], return 1.
               Otherwise, return 0.
    */
    int error = 0;
    for(int i = 0 ; i < size ; i++) {
        if(array1[i] != array2[i])
            error++;
    }

    if(error == 0) return 1;
    else return 0;
}