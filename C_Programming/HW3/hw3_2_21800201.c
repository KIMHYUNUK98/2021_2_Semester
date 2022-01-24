#include <stdio.h>

int main()
{
    // Initialize variables
    int data[10] = {0};
    int x = 0;
    int count = 0;
    int sum = 0 ;
    float avg = 0.F;

    // Input Integer to array if "x" has Positive number
    printf("Input 10 Integer: ");
    for(int i = 0 ; i < 10 ; i++) {
        scanf("%d", &x);
        if(x > 0) {
            data[count++] = x;
            sum += x;
        }
    }

    // Calculate avg with type conversion
    avg = (float) sum / count;

    // Print the result with saved poisitve index
    printf("%d positive numbers. sum = %d , avg = %f\n", count, sum, avg);
    printf("Positive numbers: ");
    for(int i = 0 ; i < count ; i++) printf("%d ", data[i]);

    return 0;
}