/**
 * Write a program that reads continuously a month number (1=Jan, 12=Dec) and the first day of the month (1=Mon, 7=Sun) and 
 * displays the calendar for that month. If the input month is February, the program should prompt the user to enter its days, that 
 * is, 28 or 29. If the given month is out of [1, 12], the program should terminate.
*/

#include <stdio.h>

int main(void){
    int month, day, month_days, i, rows;

    while(1){
        printf("\n\nEnter month [1-12]: ");
        scanf("%d", &month);

        if(month < 1 || month > 12) 
            break;
        
        if(month == 2){
            printf("Enter feb days: ");
            scanf("%d", &month_days);
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
            month_days = 30;
        else
            month_days = 31;

        printf("Enter first day of month (1=Mon, 7=Sun): ");
        scanf("%d", &day);

        printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
        
        for(i = 1; i < day; i++)
            printf("\t");

        rows = 0;

        for(i = 1; i <= month_days; i++){
            printf("%d\t", i);
            if(i == 8-day+(rows*7)){
                printf("\n");
                rows++;
            }
        }   
    }
    return 0;
}