#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct
{
  int m_TotalDays;
  int m_WorkDays;
} TResult;
#endif /* __PROGTEST__ */


/**
 * @brief Functions check if the day in month is valid
 *
 * @param year Is year in which we want to check the validation
 * @param month Is month in which we want to check the validation
 */
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

bool isFixedHoliday(int day, int month) {
    int holidays[12][2] = {
        {1, 1}, {8, 5}, {5, 7},
        {6, 7}, {28, 9}, {28, 10},
        {17, 11}, {24, 12}, {25, 12},
        {26, 12}  // ostatní pevné svátky
    };
    for (int i = 0; i < 12; ++i) {
        if (day == holidays[i][0] && month == holidays[i][1]) {
            return true;
        }
    }
    return false;
}


/**
 * @brief Zeller's congruence
 *
 */
int dayOfWeek(int day, int month, int year){
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int f = day + ((13*(month + 1)) / 5) + K + (K/4) + (J/4) + (5*J);
    int dow = (f - 1) % 7; // Mandatory modify to set day: 0 - monday .. 6 - sunday
    return dow == -1 ? 6 : dow; // If the dow is '-1' change it to 6 - it is sunday in non-negative numbers
}


bool isWorkDay ( int y, int m, int d ) {
  /* TODO */
    if (y < 2000 || 1 > d || d > isValidDay(y, m)) return false;
    int dow = dayOfWeek(d, m, y);
    if (dow == 0 || dow == 6) return false;
    if (isFixedHoliday(d, m)) return false;
    
    return true;
}


TResult countDays ( int y1, int m1, int d1,
                    int y2, int m2, int d2 ) {
  /* TODO */
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TResult r;

  assert ( isWorkDay ( 2023, 10, 10 ) );

  assert ( ! isWorkDay ( 2023, 11, 11 ) );

  assert ( ! isWorkDay ( 2023, 11, 17 ) );

  assert ( ! isWorkDay ( 2023, 11, 31 ) );

  assert ( ! isWorkDay ( 2023,  2, 29 ) );

  assert ( ! isWorkDay ( 2004,  2, 29 ) );

  assert ( isWorkDay ( 2008,  2, 29 ) );

  assert ( ! isWorkDay ( 2001,  2, 29 ) );

  assert ( ! isWorkDay ( 1996,  1,  2 ) );

  /*

  r = countDays ( 2023, 11,  1,
                  2023, 11, 30 );
  assert ( r . m_TotalDays == 30 );
  assert ( r . m_WorkDays == 21 );

  r = countDays ( 2023, 11,  1,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 17 );
  assert ( r . m_WorkDays == 12 );

  r = countDays ( 2023, 11,  1,
                  2023, 11,  1 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 1 );

  r = countDays ( 2023, 11, 17,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 0 );

  r = countDays ( 2023,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 365 );
  assert ( r . m_WorkDays == 252 );

  r = countDays ( 2024,  1,  1,
                  2024, 12, 31 );
  assert ( r . m_TotalDays == 366 );
  assert ( r . m_WorkDays == 254 );

  r = countDays ( 2000,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 8766 );
  assert ( r . m_WorkDays == 6072 );

  r = countDays ( 2001,  2,  3,
                  2023,  7, 18 );
  assert ( r . m_TotalDays == 8201 );
  assert ( r . m_WorkDays == 5682 );

  r = countDays ( 2021,  3, 31,
                  2023, 11, 12 );
  assert ( r . m_TotalDays == 957 );
  assert ( r . m_WorkDays == 666 );

  r = countDays ( 2001,  1,  1,
                  2000,  1,  1 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );

  r = countDays ( 2001,  1,  1,
                  2023,  2, 29 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );
  */

  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
