/*
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)
�� �׽�Ʈ ���̽����� "Case #x: A + B = C" �������� ����Ѵ�. x�� �׽�Ʈ ���̽� ��ȣ�̰� 1���� �����ϸ�, 
C�� A+B�̴�.
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