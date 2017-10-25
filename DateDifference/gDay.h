/*************************************************************************
* Title: Date Difference Calculator
* File: gDay.h
* Author: James Eli
* Date: 10/19/2017
*
* Determine difference between two days, measured in days.
*
* Notes:
*  (1) Algorithm found here:
*      https://alcor.concordia.ca/~gpkatch/gdate-algorithm.html
*  (2) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*************************************************************************
* Change Log:
*   10/19/2017: Initial release. JME
*************************************************************************/
#ifndef _GDAY_H_
#define _GDAY_H_

// Definitions.
#define MIN_YEAR 1582 // Start of gregorian calendar. 
#define MAX_YEAR 2500 // Maximum end date (arbitrary).

// For algorithm, zero day is March 1, year 0. Note: this year 0 is NOT Gregorian 
// year 0, it is a reference date only. However, calculations involving dates 
// after the establishment of the Gregorian calendar will be correct. Therefore, 
// start = dayCount(1582, 10, 1); // WARNING: Dates before Oct, 1582 are inaccurate!
int gDay(const int, const unsigned int, const unsigned int);

// Determine last day of month.
unsigned int lastDayOfMonth(const int, const unsigned int);

#endif // _GDAY_H_

