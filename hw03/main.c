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
 * @brief Check if the day in month is valid
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

/**
 * @brief Check for holidays
 *
 * This function check is the date is not a holiday
 *
 * @param day Day of the date
 * @param month Month of the date
 */
bool isFixedHoliday(int day, int month) {
    int holidays[11][2] = {
        {1, 1}, {1, 5}, {8, 5}, {5, 7},
        {6, 7}, {28, 9}, {28, 10},
        {17, 11}, {24, 12}, {25, 12},
        {26, 12}
    };
    for (int i = 0; i < 11; ++i) {
        if (day == holidays[i][0] && month == holidays[i][1]) {
            return true;
        }
    }
    return false;
}


/**
 * @brief Zeller's congruence
 *
 * This is a algorithm devised by Christian Zeller to calculate
 * the day of the week for any Gregorian calender date.
 *
 * @param day Day of the date
 * @param month Month of the date
 * @param year Year of the date
 */
int dayOfWeek(int day, int month, int year){
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int f = day + ((13*(month + 1)) / 5) + K + (K/4) + (J/4) + (5*J);
    int dow = (f - 1) % 7; // Mandatory modify to set day: 0 = monday .. 6 = sunday
    return dow == -1 ? 6 : dow; // If the dow is '-1' change it to 6 - it is sunday in non-negative numbers
}


/**
 * @brief Calculates is the day in date is work day
 *
 * Function checks if the day in the date is working day.
 * To achive this, it is using another 3 functions: 
 *      isValidDay 
 *      dayOfWeek
 *      isFixedHoliday
 * 
 * @param y Year of the date
 * @param m Month of the date
 * @param d Day of the date
 */
bool isWorkDay ( int y, int m, int d ) {
    if (y < 2000 || 1 > d || d > isValidDay(y, m)) return false;
    int dow = dayOfWeek(d, m, y);
    if (dow == 0 || dow == 6) return false;
    if (isFixedHoliday(d, m)) return false;
    
    return true;
}

/**
 * @brief Calculates the total number of days since a reference date (1.1.2000)
 *
 * @param year The year of the given date
 * @param month The month of the given date
 * @param day The day of the month of the given date
 * @return The total number of days since 1.1.2000 to the given date
 */
int daysSinceReference(int year, int month, int day) {
    static const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    
    for (int y = 2000; y < year; ++y) {
        totalDays += (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 366 : 365;
    }
    
    for (int m = 0; m < month - 1; ++m) {
        totalDays += monthDays[m];
    }
    
    totalDays += day;
    
    if (month > 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        totalDays += 1;
    }
    
    return totalDays;
}

/**
 * @brief Calculates the total number of weekends between a range of days
 *
 * @param startDay The day of the week the range starts
 * @param totalDays The total number of days in the range
 * @return The total number of weekends within the range
 */
int countWeekends(int startDay, int totalDays){
    int weekends = 0;
    int fullWeeks = totalDays / 7;
    weekends += fullWeeks * 2;

    int remainingDays = totalDays % 7;
    for (int i = 0; i < remainingDays; ++i){
        int currentDay = (startDay + i) % 7;
        if (currentDay == 6 || currentDay == 0) {
            weekends++;
        }
    }

    return weekends;
}


/**
 * @brief Calculates the day of the week for a given date
 *
 * @param day The day of the month
 * @param month The month of the year
 * @param year The year of the date
 * @return The day of the week (0 = Monday ... 6 = Sunday)
 */
int holidayDayOfWeek(int day, int month, int year){
    int referenceYear = 2000;
    int referenceDow = dayOfWeek(day, month, referenceYear);
    int yearsDifference = year - referenceYear;
    int leapYears = (yearsDifference / 4) - (yearsDifference / 100) + (yearsDifference / 400);
    int totalShift = yearsDifference + leapYears;
    int targetDow = (referenceDow + totalShift) % 7;
    return targetDow;
}


/**
 * @brief Calculates the total days and workdays between two dates
 *
 * @param y1 The year of the start date
 * @param m1 The month of the start date
 * @param d1 The day of the start date
 * @param y2 The year of the end date
 * @param m2 The month of the end date
 * @param d2 The day of the end date
 * @return A TResult structure containing the total days and workdays
 */
TResult countDays ( int y1, int m1, int d1,
                    int y2, int m2, int d2 ) {
    TResult result;
    if ((y1 < 2000 || 1 > d1 || d1 > isValidDay(y1, m1))
            || y2 < 2000 || 1 > d2 || d2 > isValidDay(y2, m2)){
        result.m_TotalDays = -1;
        result.m_WorkDays = -1;
        return result;
    }

    if (y1 > y2 || (y1 == y2 && (m1 > m2 || (m1 == m2 && d1 > d2)))) {
        result.m_TotalDays = -1;
        result.m_WorkDays = -1;
        return result;
    }


    int date1 = daysSinceReference(y1, m1, d1);
    int date2 = daysSinceReference(y2, m2, d2);
    int date1Day = dayOfWeek(d1, m1, y1);
    //int date2Day = dayOfWeek(d2, m2, y2);
    int daysBetweenTwoDates = (date2-date1)+1;

    int weekendsBetweenDates = countWeekends(date1Day, daysBetweenTwoDates);

    /** Calculates the holidays between two dates **/

    int holidays[11][2] = {
        {1, 1}, {1, 5}, {8, 5}, {5, 7},
        {6, 7}, {28, 9}, {28, 10},
        {17, 11}, {24, 12}, {25, 12},
        {26, 12}
    };
    int totalHolidays = 0; 
    int firstHolidayIndex = -1;
    int lastHolidayIndex = -1;
    int day = 0;
    int month = 0;
    int year = 0;
    int dow = 0;
    int yearsDifference = y2 - y1;

    for (int i = 0; i < 11; ++i) {
        if (holidays[i][1] > m1 || (holidays[i][1] == m1 && holidays[i][0] >= d1)) {
            firstHolidayIndex = i;
            break;
        }
    }
    for (int i = 0; i < 11; ++i) {
        if (holidays[i][1] > m2 || (holidays[i][1] == m2 && holidays[i][0] > d2)) {
            break;
        }
        lastHolidayIndex = i;
    }



    if (yearsDifference){
        // Calculates the holidays in first year
        for (int i = firstHolidayIndex; i < 11; ++i){
        day = holidays[i][0];
        month = holidays[i][1];
        dow = holidayDayOfWeek(day, month, y1);
        if (dow != 0 && dow != 6){
            totalHolidays++;
        }
    }

    // Calculates the holidays between first and last year
    for (int k = 1; k < yearsDifference; ++k) {
        for (int i = 0; i < 11; ++i){
            day = holidays[i][0];
            month = holidays[i][1];
            year = y1 + k;
            dow = dayOfWeek(day, month, year);
            if (dow != 0 && dow != 6){
                totalHolidays++;
            }
        }
    }

    // Calculates the holidays in last year
    for (int i = 0; i <= lastHolidayIndex; ++i){
        day = holidays[i][0];
        month = holidays[i][1];
        dow = holidayDayOfWeek(day, month, y2);
        if (dow != 0 && dow != 6){
            totalHolidays++;
        }
    }
    } else {
        // Calculates holidays between 2 dates which has the same year
        for (int i = firstHolidayIndex; i <= lastHolidayIndex; ++i){
            day = holidays[i][0];
            month = holidays[i][1];
            dow = holidayDayOfWeek(day, month, y1);
            if (dow != 0 && dow != 6){
                totalHolidays++;
            }
        }
    }

    /*********************************************/
    

    result.m_TotalDays = daysBetweenTwoDates;
    result.m_WorkDays = daysBetweenTwoDates - totalHolidays - weekendsBetweenDates;

    return result;
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
 

  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
