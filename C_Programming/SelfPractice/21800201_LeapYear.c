/*
������ �־����� ��, �����̸� 1, �ƴϸ� 0�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
������ ������ 4�� ����̸鼭, 100�� ����� �ƴ� �� �Ǵ� 400�� ����� ���̴�.
���� ���, 2012���� 4�� ����̸鼭 100�� ����� �ƴ϶� �����̴�. 
1900���� 100�� ����̰� 400�� ����� �ƴϱ� ������ ������ �ƴϴ�. 
������, 2000���� 400�� ����̱� ������ �����̴�.
*/

#include<stdio.h>

int main() 
{
    // Initialize the variable
    int year = 0;

    // Read the year
    printf("Input the year: ");
    scanf("%d", &year);

    // Calculate the leap year
    // Leap year : print 1  or  Not leap year : print 0
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}