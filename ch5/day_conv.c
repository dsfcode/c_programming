#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += *((*daytab + leap) + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *((*daytab + leap) + i); i++)
        yearday -= *((*daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}

int main() {
    int month, day;
    int year = 2017;
    int day_in_year = 100;

    month_day(year, day_in_year, &month, &day);
    printf("Year: %d, days in year: %d, month: %d, day: %d\n", year, day_in_year, month, day);
    month_day(year, day_in_year, &month, &day);
    printf("Year: %d, month: %d, days in year: %d, day: %d\n", year, month, day, day_of_year(year, month, day));
}

