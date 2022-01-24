/*
Main �Լ����� ������ max�� min value�� �̿��Ͽ� 2���� function call�� �����ϰ�
max�� min ���� �ش��ϴ� ���� �������� �ڵ带 �ۼ��ض�
�Է¹޴� �޴� ���� ���� ������ 100�� ���� �ʴ´�.
(function �� ����� �������� for loop�� ���Ǵ� ���� �̿��� ���� ������ ����)
*/

#include <stdio.h>
#include <string.h>

// Function Definition
int getMaxNumber(int number[100], int *max);
int getMinNumber(int number[100], int *min);

int main()
{
    // Initialize the variable
    int number[100];
    int max = -1;
    int min = 101;

    // Input the number
    printf("Input 10 numbers you want\n > ");
    for(int i = 0 ; i < 10; i++) {
        scanf("%d", &number[i]);
    }

    // function call
    max = getMaxNumber(number, &max);
    min = getMinNumber(number, &min);

    // Print the result
    printf("MAX = %d, MIN = %d\n", max, min);

    return 0;
}

int getMaxNumber(int number[100], int *max) {

    // Calculate Max number
    for(int i = 0 ; i < 10; i++) {
        if(*max < number[i]) {
            *max = number[i];
        }
    }

    // Return Max value
    return *max;
}

int getMinNumber(int number[100], int *min) {

    // Calculate Min number
    for(int i = 0 ; i < 10; i++) {
        if(*min > number[i]) {
            *min = number[i];
        }
    }

    // Return Min value
    return *min;
}