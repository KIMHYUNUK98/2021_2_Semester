#include<stdio.h>

int main() {

    char name[128];
    int num = 0;

    printf("Enter your name > ");
    gets(name);

    printf("Hello, %s ~~!! How are you today??\n", name);
    printf(" 1. Good\n 2. So so\n 3. Not bad\n 4. Sad\n\n >");
    scanf("%d", &num);

    switch(num) {
        case 1:
            printf("Wow!! There must be a good things today!!\n\n");
            break;
        case 2: 
            printf("Yeah!! It's pretty busy and silent enough!!\n\n");
            break;
        case 3:
            printf("What happend to you..? It'll be okay\n\n");
            break;
        case 4: 
            printf("I'm sorry to hear that...\n\n");
            break;
    }

    printf("Can I ask you to play with me?? (0: Ok 1: NO) > ");
    scanf("%d", &num);

    if(num == 0) {
        printf("I want to make a star with you\n");
        printf("Please Enter the number of your favorite number: ");
        scanf("%d", &num);

        for(int i = 0 ; i < num ; i++) {
            for(int j = num-1 ; j > i ; j--) {
                printf(" ");
            }
            for(int j = 0 ; j < num ; j++) {
                printf("*");
            }
            for(int j = num - i ; j > 0 ; j--) {
                printf("*");
            }
            printf("\n");
        }
    
    } else {
        printf("Can I ask you again..??? (0: Ok 1: NO) > ");
        scanf("%d", num);

        printf("I want to make a star with you\n");
        printf("Please Enter the number of your favorite number: ");
        scanf("%d", &num);

        for(int i = 0 ; i < num ; i++) {
            for(int j = num-1 ; j > i ; j--) {
                printf(" ");
            }
            for(int j = 0 ; j < num ; j++) {
                printf("*");
            }
            for(int j = num - i ; j > 0 ; j--) {
                printf("*");
            }
        }
        if(num = 0) {
            printf("Thanks for thinking!!!\n");
        } else {
            printf("Ok,, Bye See you tomorrow!!\n");
        }
    }

    return 0;
}