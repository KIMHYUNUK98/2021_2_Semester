/*
ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����
������, �������� �������� ������ ��(���� ����)�� ����Ͻÿ�.
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