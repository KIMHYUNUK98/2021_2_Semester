/*
���� ���� ���� �� �ϳ��� �־��� ���� ��� ��и鿡 ���ϴ��� �˾Ƴ��� ���̴�. 
��и��� �Ʒ� �׸�ó�� 1���� 4���� ��ȣ�� ���´�. "Quadrant n"�� "��n��и�"�̶�� ���̴�.
���� ���, ��ǥ�� (12, 5)�� �� A�� x��ǥ�� y��ǥ�� ��� ����̹Ƿ� ��1��и鿡 ���Ѵ�.
�� B�� x��ǥ�� �����̰� y��ǥ�� ����̹Ƿ� ��2��и鿡 ���Ѵ�.
���� ��ǥ�� �Է¹޾� �� ���� ��� ��и鿡 ���ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. 
��, x��ǥ�� y��ǥ�� ��� ����� ������� �����Ѵ�.

�Է�: ù �ٿ��� ���� x�� �־�����. (?1000 �� x �� 1000; x �� 0) 
    ���� �ٿ��� ���� y�� �־�����. (?1000 �� y �� 1000; y �� 0)
���: �� (x, y)�� ��и� ��ȣ(1, 2, 3, 4 �� �ϳ�)�� ����Ѵ�.
*/

#include <stdio.h>

int main()
{
    // Initialize the variable
    int x = 0;
    int y = 0;

    // Input the x-coordinate from user
    printf("Input the x-coordinate number: ");
    scanf("%d",&x);

    // Input the y-coordinate from user
    printf("Input the y-coordinate number: ");
    scanf("%d", &y);

    // calculate the quadrant of the number(x,y)
    // printf the quadrant!!
    if(x > 0 && y > 0) {
        printf("1");
    } else if(x < 0 && y > 0) {
        printf("2");
    } else if(x < 0 && y < 0) {
        printf("3");
    } else {
        printf("4");
    }

    return 0;
}