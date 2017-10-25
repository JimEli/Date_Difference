/*************************************************************************
* Title: Date Difference Calculator
* File: main.c
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
#include <assert.h> 
#include <stdbool.h>
#include <stdio.h>

#include "gDay.h"

int main(void) {

	// Unit tests.
#ifndef NDEBUG
	int numDays = 0; // Consecutive count of days.

	fputs("Validity check of consecutive dates.\n", stdout);
	// Iterate through date range (1582 - 2500), asserting consecutive days.
	for (int y = MIN_YEAR; y < (MAX_YEAR - 1); y++)
		for (unsigned int m = 1; m <= 12; m++)
			for (unsigned int d = 1; d <= lastDayOfMonth(y, m); d++)
				assert(numDays++ == gDay(y, m, d) - gDay(MIN_YEAR, 1, 1));
	fputs("Check passed.\n", stdout);
#else
	fputs("Nothing to do.\n", stdout);
#endif

	fputs("\nProgram terminating.\n", stdout);
}
