# Date Difference Calculator
 
Determines the difference between 2 dates (Gregorian calendar), as measured in days.

The length of a year is 365.2424 days. The Gregorian calendar, instituted in October of 1582, takes the length of a year to be 365.2425 days (one part in ten thousand, 0.0001 too big). However, this is accurate enough to last through the next few millennia. This approximation, 365.2425 can be written as:
```text
365.0000 + 0.2500 - 0.0100 + 0.0025 
```
  or
```text
365 + 1/4 - 1/100 + 1/400
```
So, the number of days in y years is:
```text
d = 365y + y/4 - y/100 + y/400
```
Since the lengths of the months are not the same, and the length of February is not fixed, it seems impossible to calculate day offsets in a year without look-up tables and checking for leap years. To get around this problem, the start of the calendar year is defined as March. Numbering the months this way causes leap days to be added at the end of the year:
```text
d = f(m) = (306*m + 5)/10
```
Notes:
* Algorithm found here: https://alcor.concordia.ca/~gpkatch/gdate-algorithm.html
* WARNING: Dates before establishment of Gregorian calendar (Oct, 1582) are inaccurate!
* Compiled with MS Visual Studio 2017 Community (v141), using C language options.
