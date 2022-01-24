/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
각 테스트 케이스마다 "Case #x: A + B = C" 형식으로 출력한다. x는 테스트 케이스 번호이고 1부터 시작하며, 
C는 A+B이다.
*/
#include<stdio.h>

int main()
{
    // Initialize the variable.
    int count = 0;
    int num1 = 0;
    int num2 = 0;

    // Read the count(rotate number) variable.
    printf("Input the rotate numbers: ");
    scanf("%d", &count);

    // rotate the loop to read two numbers.
    for(int i = 1 ; i <= count ; i++) {

        // Read two numbers from user.
        printf("input two numbers: ");
        scanf("%d %d", &num1, &num2);

        // Calculate tthe sum of two numbers
        // Print the result
        int sum = num1 + num2;
        printf("Case #%d: %d + %d = %d\n", i, num1, num2, sum);
    }

    return 0;
}