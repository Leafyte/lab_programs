//calender program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_DAYS 7

typedef struct {
    char *name_of_day;
    int date_of_day;
    char *activity_descr;
} CALENDAR;

void create_calendar(CALENDAR a[], int i, char name[], int date, char activity[]) {

    a[i].name_of_day = (char *)malloc(strlen(name) + 1);
    strcpy(a[i].name_of_day, name);

    a[i].date_of_day = date;

    a[i].activity_descr = (char *)malloc(strlen(activity) + 1);
    strcpy(a[i].activity_descr, activity);
}

void read_calendar(CALENDAR a[]) {
    int i,date;
    char name[20], activity[50];

    for (i = 0; i < NO_OF_DAYS; i++) {
        printf("Enter day name: ");
        scanf("%s", name);

        printf("Enter date: ");
        scanf("%d", &date);

        printf("Enter activity: ");
        scanf("%s", activity);

        create_calendar(a, i, name, date, activity);
    }
}

void print_weeks_activity(CALENDAR a[]) {
    printf("\nWeek’s Activity Report:\n");

    for (int i = 0; i < NO_OF_DAYS; i++) {
        printf("%s : %s\n", a[i].name_of_day, a[i].activity_descr);
    }
}

int main() {

    CALENDAR a[NO_OF_DAYS];

    printf("Enter day, date, and activity for 7 days:\n\n");

    read_calendar(a);
    print_weeks_activity(a);

    return 0;
}
