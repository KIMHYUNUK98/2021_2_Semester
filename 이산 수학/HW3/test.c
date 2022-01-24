#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palCheck(int str[],int s, int e)
{
    if (s == e)
    return true;

    if (str[s] != str[e])
    return false;

    if (s < e + 1)
    return palCheck(str, s + 1, e - 1);

    return true;
}
bool isPalindrome(int str[], int size)
{
    int n = size;
    
    if (n == 0)
        return true;
    
    return palCheck(str, 0, n - 1);
}

void printTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void generateAllBinaryStrings(int n, int arr[], int i)
{
    if (i == n) {
        if(isPalindrome(arr,n))
            printTheArray(arr, n);
        return;
    }

    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);

    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}

int main(void) {
    int str[7];

    for(int n = 1 ; n <= 6 ; n++)
        generateAllBinaryStrings(n, str, 0);
}