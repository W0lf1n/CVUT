#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

/**
 * @brief Functions check if the day in month is valid
 *
 * @param year Is year in which we want to check the validation
 * @param month Is month in which we want to check the validation
 */
int isValidDay(int year, int month) {
    if(year >= 4000) {
        if(month == 2) {
            return 28;
        } else if(month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    } else {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            return 31;
        } else if ((month == 2) && ((year%400==0) || (year%4==0 && year%100!=0))){
            return 29;
        } else if (month == 2){
            return 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return -1;  
        }
    }
}







/**
 * @brief Function calculates the day in the year
 *
 * @param day Given day
 * @param month Given month
 * @param year Given year
 */
int dateToIndex(int day, int month, int year, int *idx) {
    int maxDay = isValidDay(year, month);

    if (year < 2000 || month < 1 || month > 12 || day < 1 || day > maxDay) {
        *idx = 0;
        return 0;
    }

    int sum_day = 0;

    for (int i = 1; i < month; i++) {
        sum_day += isValidDay(year, i);
    }

    sum_day += day;
    *idx = sum_day;

    return 1;
}


#ifndef __PROGTEST__

/**
 * @brief Main function of the program
 */
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
    
    // Nové testovací případy:
    assert(dateToIndex(19,  9, 248000, &idx) == 1 && idx == 262);
    assert(dateToIndex( 1,  8, 524000, &idx) == 1 && idx == 213);
    assert(dateToIndex(31, 10, 640000, &idx) == 1 && idx == 304);
    assert(dateToIndex(29,  2, 360000, &idx) == 0);
    assert(dateToIndex(29, 2, 642400, &idx) == 1);
    assert(dateToIndex(8, 11, 278000, &idx) == 1 && idx == 313);
    return 0;
}
#endif /* __PROGTEST__ */

