#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int isValidDay(int year, int month) {
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    } else if ((month == 2) && ((year%400==0 && year!=4000) || (year%4==0 && year%100!=0))){
        return 29;
    } else if (month == 2){
        return 28;
    } else {
        return 30;
    }
}


int dateToIndex(int day, int month, int year, int *idx) {
    if (year < 2000 || (1 > month || month > 12) || ( 1 > day || day > isValidDay(year, month))) {

        *idx = 0;

        return 0;
    }

    int sum_day = day;

    for (int i = 1; i < month; i++) {
        sum_day += isValidDay(year, i);
    }

    *idx = sum_day;

    return 1;
}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */

