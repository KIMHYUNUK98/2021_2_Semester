/*
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.
*/

#include <stdio.h>

int main()
{
    // Initialize the variable
    int num = 0;

    // Input the height of the triangle from the user
    printf("Input the height of the triangle: ");
    scanf("%d", &num);

    // Print out the trinagle
    // print the star with num times
    for(int i = 0 ; i < num ; i++) {
        // print the space " " 
        for(int j = num-i ; j > 1 ; j--) {
            printf(" ");
        }
        // print the star
        for(int j = num-i-1 ; j < num ; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}