/*
두수를 입력받고 최대공약수와 최소공배수를 출력하는 함수를 만들어라
(Main 함수 제외 2개의 함수 사용)
*/
#include<stdio.h>

int Greatest_common_factor(int num1, int num2);
int Least_common_factor(int num1, int num2, int result1);

int main() 
{   
    // Initialize variables
    int num1 = 0;
    int num2 = 0;
    int result1 = 0;
    int result2 = 0;

    // Read two numbers
    printf("Input two numbers : ");
    scanf("%d %d", &num1, &num2);

    // Call the funcion (for calculate Great_num, Least_num)
    result1 = Greatest_common_factor(num1, num2);
    result2 = Least_common_factor(num1, num2, result1);

    // Print the result
    printf("Greatest_common_factor = %d\nLeast_common_factor = %d\n", result1, result2);

    return 0;
}

// Function for calculate Greatest_common_factor
int Greatest_common_factor(int num1, int num2) {

    // Initialize variables
    int large = 0;
    int great = 0;

    // find the Greatest_common_factor using for loop and if condition
    for(int i = 1 ; i <= num1 && i <= num2 ; i++) {
        
        // If num1 and num2 divided by i completely, save the value
        if(num1 % i == 0 && num2 % i == 0) {
            great = i;
        }
    }

    // return answer value
    return great;
}

int Least_common_factor(int num1, int num2, int result1) {

    // Initialize the variable
    int least = 0;

    // Calculate the least_common_factor using Greatest_common_value
    least = (num1 * num2) / result1;

    // return answer value
    return least;
}