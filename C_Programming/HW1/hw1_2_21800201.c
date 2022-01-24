#include <stdio.h>

int main() {

    float KRW = 0.0F;
    float USD = 0.0F;

    // Input amount of KRW
    printf("Input amount of KRW: ");
    scanf("%f", &KRW);

    // Calculate USD with Exchange rate
    USD = KRW / 1156.94F;

    // Print KRW and USD with Won and dollar
    printf("%f WON = %f Dollar\n", KRW, USD);

    return 0;
}