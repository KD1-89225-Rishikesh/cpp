
#include <stdio.h>


struct Date {

    char day[3]; 

    char month[3];

    char year[5];

};


void acceptDateFromConsole(struct Date* ptrDate);

void printDateOnConsole(struct Date* ptrDate);


int main() {

    struct Date d1; 

    acceptDateFromConsole(&d1);

    printDateOnConsole(&d1);

    return 0;

}


void acceptDateFromConsole(struct Date* ptrDate) {

    printf("Enter the day: ");

    scanf(" %s", &ptrDate->day);

    printf("Enter the month: ");

    scanf(" %s", &ptrDate->month);

    printf("Enter the year: ");

    scanf(" %s", &ptrDate->year);

}


void printDateOnConsole(struct Date* ptrDate) {

    printf("Date : %s-%s-%s", ptrDate->day, ptrDate->month, ptrDate->year);

}