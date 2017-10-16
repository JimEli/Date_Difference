/*************************************************************************
* Title: Date Difference Calculator
* File: main.c
* Author: James Eli
* Date: 10/16/2017
*
* Determine difference between two dates, measured in days.
*
* Notes:
*  (1) Algorithm found here: 
*      https://alcor.concordia.ca/~gpkatch/gdate-algorithm.html
*  (2) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*************************************************************************
* Change Log:
*   10/16/2017: Initial release. JME
*************************************************************************/
#include <assert.h> 
#include <stdbool.h>
#include <stdio.h>

// Definitions.
#define MIN_YEAR 1582 // Start of gregorian calendar. 
#define MAX_YEAR 2500 // Maximum end date (arbitrary).

// Leap year validator.
// Logic: if year is divisible by 4, then its a leap year.
// But if that year is divisible by 100, then its not a leap year.
// However, if the year is also divisible by 400, then its a leap year.
static inline bool isLeapYear(const unsigned int year) {
	return ((!(year % 4) && (year % 100)) || !(year % 400));
}

// Determine last day of month.
static unsigned int lastDayOfMonth(const int y, const unsigned int m) {
	static const unsigned int eom[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return m != 2 || !isLeapYear(y) ? eom[m] : 29U;
}

// For algorithm, zero day is March 1, year 0. Note: this year 0 is NOT Gregorian 
// year 0, it is a reference date only. However, calculations involving dates 
// after the establishment of the Gregorian calendar will be correct. Therefore, 
// start = dayCount(1582, 10, 1); // WARNING: Dates before Oct, 1582 are inaccurate!
static int gDay(const int year, const unsigned int month, const unsigned int day) {
	int y, m;

	m = (month + 9)%12; // Mar = 0, Feb = 11
	y = year - m/10;    // If Jan or Feb, year--
	return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (day - 1);
}

int main(void) {
	int n = 0; // Confirm consecutivity for useful date range. 

	fputs("Conducting validity check of consecutive dates... ", stdout);

	// Iterate through date range (1582 - 2500).
	for (int y = MIN_YEAR; y < (MAX_YEAR - 1); y++) 
		for (unsigned int m = 1; m <= 12; m++) 
			for (unsigned int d = 1; d <= lastDayOfMonth(y, m); d++) 
				assert(n++ == gDay(y, m, d) - gDay(MIN_YEAR, 1, 1));
	fputs("Check passed.\n\n", stdout);
}
