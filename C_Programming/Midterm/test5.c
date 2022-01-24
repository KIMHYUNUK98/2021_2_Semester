#include <stdio.h>

int main() 
{

    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 9-i ; j > 0 ; j--) {
            printf(" ");
        }

        for(int j = 9-i ; j < 10 ; j++) {
            printf("*");
        }

        for(int j = 10-i ; j < 10 ; j++) {
            printf("*");
        }

    printf("\n");
    }

    for(int i = 0 ; i < 10 ; i++) {
        for(int j = 10-i ; j < 10 ; j++) {
            printf(" ");
        }

        for(int j = i ; j < 10 ; j++) {
            printf("*");
        }

        for(int j = 10-i ; j < 10 ; j++) {
            printf("*");
        }
    printf("\n");
    }
    


    return  0;
}