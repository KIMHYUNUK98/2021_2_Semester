#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    char str[128];
    char even_str[128];
    char odd_str[218];

    int even_len = 0;
    int odd_len = 0;

    printf("Input a text line: ");
    fgets(str, 128, stdin);

    for(int i = 0 ; i < strlen(str) ; i++) {
        if(isdigit(str[i]) != 0) {
            int num = str[i] - '0';
            if(num % 2 == 0) {
                even_str[even_len++] = str[i];
            } else if(num % 2 != 0) {
                odd_str[odd_len++] = str[i];
            }
        }
    }

    even_str[strlen(even_str)] = '\0';
    odd_str[strlen(odd_str)] = '\0';

    if(even_len == 0) {
        printf("no even digit.\n");
    } else {
        printf("Even digit: ");
        for(int i = 0 ; i < even_len ; i++) {
            printf(" %c", even_str[i]);
        }
        printf("\n");
    }

    if(odd_len == 0) {
        printf("no odd digit\n");
    } else {
        printf("Odd digit: ");
        for(int i = 0 ; i < odd_len ; i++) {
            printf(" %c", odd_str[i]);
        } 
        printf("\n");
    }

    int even_num = atoi(even_str);
    int odd_num = atoi(odd_str);
    int sum = even_num + odd_num;

    printf("\"%s\" and \"%s\" are converted into %d and %d, respectively.Their sum is %d.",
                even_str, odd_str, even_num, odd_num, sum);

    return 0;
}