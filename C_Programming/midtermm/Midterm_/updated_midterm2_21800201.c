/*

    Write a C program that reads start time and elapsed time and prints end time.
        - Implement "void AddSeconds()" function.
        - The skeleton code may contain bugs. Fix all of them. (Do not modify correct parts.)
        - Make the output messages as similar to the examples as possible.


    Example)
        Input start time (hour min sec): 5 15 20                  // the user typed "5 15 20"
        start time = 05:15:20
        Input elapsed time in seconds (can be longer than 60): 352  // the user typed "352"
        end time = 05:21:12

    Example)
        Input start time (hour min sec): 23 50 20                 // the user typed "23 50 20"
        start time = 23:50:20
        Input elapsed time in seconds (can be longer than 60): 3600 // the user typed "3600"
        end time = 00:50:20

*/

#include <stdio.h>

void PrintTime(char title[], int hour, int min, int sec);
void AddSeconds(int* hour, int* min, int* sec, int elapsed_sec);

int main()
{
    int hour = 0, min = 0, sec = 0;
    int elapsed_sec = 0;

    // read start time
    printf("Input start time (hour min sec): ");
    scanf("%d %d %d", &hour, &min, &sec);

    // display start time
    PrintTime("start time", hour, min, sec);

    // read elapsed time in seconds
    printf("Input elapsed time in seconds (can be longer than 60): ");
    scanf("%d", &elapsed_sec);

    // add elapsed_sec to (hour, min, sec) by calling the AddSeconds() function
    AddSeconds(&hour, &min, &sec, elapsed_sec);    // should be modified

    // display end time
    PrintTime("end time", hour, min, sec);

    return 0;
}

void PrintTime(char title[], int hour, int min, int sec)
{
    printf("%s = %02d:%02d:%02d\n", title, hour, min, sec);
}

void AddSeconds(int *hour, int* min, int* sec, int elapsed_sec)
// TO DO: Add elapsed_sec to (hour, min, sec)
//  - Use nested if-statements to deal with carries.
//  - After addition, min and sec should be in the range [0, 59] and hour should be in the range [0, 23].
//  - If necessary, modify the formal parameter list.
//  - The increment operator (++) is not recommend for this problem.
{
    int add_hour = 0;
    int add_min = 0;
    int add_sec = 0;

    if(elapsed_sec < 60) {
        *sec = *sec + elapsed_sec;
        if(*sec >= 60) {
            *min = *min + 1;
            *sec = *sec - 60;
            if(*min >= 60) {
                *hour = *hour + 1;
                *min = *min - 60;
                if(*hour >= 24) {
                    *hour = *hour - 24;
                }
            }
        }
    } else  if(elapsed_sec >= 60) {
        add_sec = elapsed_sec % 60;
        add_min = elapsed_sec / 60 % 60;
        add_hour = elapsed_sec / 60 / 60;

        *sec = *sec + add_sec;
        if(*sec >= 60) {
            *min = *min + 1;
            *sec = *sec - 60;
            *min = *min + add_min;
            if(*min >= 60) {
                *hour = *hour + 1;
                *min = *min - 60;
                *hour = *hour + add_hour;
                if(*hour >= 24) {
                    *hour = *hour - 24;
                }
            } else {
                *hour = *hour + add_hour;
                if(*hour >= 24) {
                    *hour = *hour - 24;
                }
            }
        } else {
            *min = *min + add_min;
            if(*min >= 60) {
                *hour = *hour + 1;
                *min = *min - 60;
                *hour = *hour + add_hour;
                if(*hour >= 24) {
                    *hour = *hour - 24;
                }
            } else {
                *hour = *hour + add_hour;
                if(*hour >= 24) {
                    *hour = *hour - 24;
                }
            }
        }
    }
}
