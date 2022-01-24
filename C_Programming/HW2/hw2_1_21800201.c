#include <stdio.h>

int main() {

    // Declare the variables and Initiate
    int quantity = 0;
    double unit_price = 0.0;
    double shipping_charge = 0.0;
    double USD = 0.0;
    char Item_name[64] = "NULL";

    // Read each variables
    printf("Item name: ");
    scanf("%s", Item_name);

    printf("Unit Price: ");
    scanf("%lf", &unit_price);

    printf("Quantity: ");
    scanf("%d", &quantity);

    printf("Shipping_Charge: ");
    scanf("%lf", &shipping_charge);

    // Calculate the price in USD
    USD = unit_price * quantity + shipping_charge;

    // Print the Result
    printf("%s: $%.02f * %d + $%.02f = $%.02f\n", Item_name, unit_price, quantity, shipping_charge, USD);

    return 0;
}