#include <stdio.h>

int main()
{
    int startDay = 0, nDays = 0;
    int i = 0;

    // read startDay and # of days
    printf("Input startDay and nDays: ");
    scanf("%d %d", &startDay, &nDays);

    // print title
    printf("SUN MON TUE WED THU FRI SAT\n");
    
    // print a bar
    printf("--- --- --- --- --- --- ---\n");

    // print days
    // print blanks
    for(i = 0; i < startDay; i++)
        printf("    ");

    // print numbers
    for(i = 1; i <= nDays; i++){
        printf("%3d ", i);

        if((startDay + i) % 7 == 0)
            printf("\n");
    }
    if(i == nDays+1)     // fill out the condition
        printf("\n");

    // print a bar
    printf("--- --- --- --- --- --- ---\n");

    return 0;
}