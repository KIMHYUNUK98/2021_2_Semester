#include <stdio.h>

int main() 
{
    int x = 0;
    int sum = 0;
    int testEOF = 0;

    printf("Enter the numbers <EOF> to stop\n");
    do {
        testEOF = scanf("%d", &x);
        if(testEOF != EOF) {
            sum += x;
        }
    } while(testEOF != EOF);

    printf("Total : %d\n", sum);

    return 0;
}