/***********************
*                      *
*  Кофф Даниил ПИ-221  *
*  Календарь           *
*                      *
***********************/

#include <iostream>
#include <string>

using namespace std;

int calendarDisplay (int weekPosition, int days, string month) {
  int index;
  
  cout << "\n\n\n\n" << month << "----------\n\nMon Tue Wed Thu Fri Sat Sun\n";
  
  for (index = 1; index < weekPosition; ++index) {
    cout << "    ";
  }
  
  for (index = 1; index <= days; ++index) {
    cout << " " << index << " ";
    if (index < 10) {
      cout << " ";
    }
    
    ++weekPosition;
    if (weekPosition > 7) {
      cout << "\n";
      weekPosition -= 7;
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
  leap += (startYear - 1) / 4;
  
  weekPosition += startYear + leap;
  while (weekPosition > 7) {
    weekPosition -= 7;
  }
  while (weekPosition < 1) {
    weekPosition += 7;
  }
  
  weekPosition = calendarDisplay(weekPosition, 31, "January");
  if (startYear % 4 == 0) {
    weekPosition = calendarDisplay(weekPosition, 29, "February");
  }
  else {
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

