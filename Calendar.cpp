/***********************
*                      *
*  Кофф Даниил ПИ-221  *
*  Календарь           *
*                      *
***********************/

#include <iostream>
#include <string>

using namespace std;

int daysPerWeek = 7;

int calendarDisplay (int weekPosition, int dayIndexs, string month) {
  int dayIndex;
  
  cout << "\n\n\n\n" << month << "----------\n\nMon Tue Wed Thu Fri Sat Sun\n";
  
  for (dayIndex = 1; dayIndex < weekPosition; ++dayIndex) {
    cout << "    ";
  }
  
  for (dayIndex = 1; dayIndex <= dayIndexs; ++dayIndex) {
    printf("%02d  ", dayIndex);
    
    ++weekPosition;
    
    if (weekPosition > daysPerWeek) {
      cout << "\n";
      
      weekPosition -= daysPerWeek;
    }
  }
  
  return weekPosition;
}

int main() {
  int year;
  int startYear = 2000;
  int weekPosition = 6;
  int leap = 1;
  
  cout << "Enter year: ";
  cin  >> year;
  
  startYear = year - startYear;
  
  if (startYear <= 0) {
    --leap;
  }

  leap += (startYear - 1) / 4 - (startYear - 1) / 100 + (startYear - 1) / 400;
  weekPosition += startYear + leap;
  
  while (weekPosition > daysPerWeek) {
    weekPosition -= daysPerWeek;
  }
  
  while (weekPosition < 1) {
    weekPosition += daysPerWeek;
  }
  
  weekPosition = calendarDisplay(weekPosition, 31, "January");
  if ((startYear % 4 == 0 && startYear % 100 != 0) || startYear % 400 == 0) {
    weekPosition = calendarDisplay(weekPosition, 29, "February");
  } else {
    weekPosition = calendarDisplay(weekPosition, 28, "February");
  }
  weekPosition = calendarDisplay(weekPosition, 31, "March");
  weekPosition = calendarDisplay(weekPosition, 30, "April");
  weekPosition = calendarDisplay(weekPosition, 31, "May");
  weekPosition = calendarDisplay(weekPosition, 30, "June");
  weekPosition = calendarDisplay(weekPosition, 31, "July");
  weekPosition = calendarDisplay(weekPosition, 31, "August");
  weekPosition = calendarDisplay(weekPosition, 30, "September");
  weekPosition = calendarDisplay(weekPosition, 31, "October");
  weekPosition = calendarDisplay(weekPosition, 30, "November");
  weekPosition = calendarDisplay(weekPosition, 31, "December");

  return 0;
}

