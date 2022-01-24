/*
Main 함수에서 선언한 max와 min value를 이용하여 2번의 function call을 시행하고
max와 min 값에 해당하는 값이 들어오도록 코드를 작성해라
입력받는 받는 값은 양의 정수로 100을 넘지 않는다.
(function 을 만드는 과정에서 for loop에 사용되는 변수 이외의 변수 선언은 금지)
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