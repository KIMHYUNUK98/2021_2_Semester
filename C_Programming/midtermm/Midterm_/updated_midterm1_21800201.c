#include <stdio.h>

/*

    Write a C program that computes the total price from the unit prices, counts, and shipping costs of product items.
        - total_price = The sum of (unit_price * count + shipping_cost) of product items
        - Make the output messages as similar to the examples as possible.

    Example)
        Input unit_price, count, and shipping cost: 10000 3 2500        // the user typed "10000 3 2500"
        Input unit_price, count, and shipping cost: 20000 2 3000        // the user typed "20000 2 3000"
        Input unit_price, count, and shipping cost: ^Z                  // the user typed CTRL-Z (on Windows)
        total price = 75500

    Example)
        Input unit_price, count, and shipping cost: 5000 30 10000       // the user typed "5000 30 10000"
        Input unit_price, count, and shipping cost: 100000 1 0          // the user typed "100000 1 0"
        Input unit_price, count, and shipping cost: 3500 15 2500        // the user typed "3500 15 2500"
        Input unit_price, count, and shipping cost: ^Z                  // the user typed CTRL-Z (on Windows)
        total price = 315000

*/

int main()
{

    int price = 0;
    int count = 0;
    int shipping_cost = 0;
    int user_end = 0;
    int sum = 0;

    // display messages to guide the user
    printf("This program computes the total cost from the input unit price, count and shipping cost.\n");
    printf("When you finished input, press EOF (CTRL-Z on Windows and CTRL-D on Linux/MacOS)\n");

    printf("\n");

    // Repeat the followings until the user types EOF using the do-while statement.
    do {
        // Read unit price, count, and shipping cost of a product item from the user
        // (The user can input EOF by typing CTRL-Z on Windows and CTRL-D on MacOS/Linux.)
        // (Check the return value of scanf() to detect EOF.)
        printf("Input unit_price, count, and shipping cost: ");
        user_end = scanf("%d", &price);
        if(user_end == EOF) break;
        scanf("%d", &count);
        scanf("%d", &shipping_cost);


        // If the user didn't type EOF, add the price of the product item to total_price.
        sum += price * count + shipping_cost;
    } while(user_end != EOF);

    // Print the total price.
    printf("total price = %d", sum);

    return 0;
}
