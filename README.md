# Date Difference Calculator
 
Determines the difference between 2 dates (Gregorian calendar), as measured in days.

The length of a year has been measured as 365.2424 days. In October of 1582, the Gregorian calendar was instituted. It takes the length of a year to be 365.2425 days, which is one part in ten thousand (0.0001) too big, but is accurate enough to last through the next few millennia. This approximation 365.2425 can be written as:

365.0000 + 0.2500 - 0.0100 + 0.0025 

  or

365 + 1/4 - 1/100 + 1/400

Now the number of days in y years is:

d = 365y + y/4 - y/100 + y/400

Since the lengths of the months are not the same, and the length of February is not fixed, it seems at first to be impossible to calculate day offsets in a year without looking up tables and checking for leap years. To get around the problem we define the start of the calendar year with March. Numbering the months this way has the advantage that leap days are added at the end of the year:

d = f(m) = (306*m + 5)/10

Notes:
* Algorithm found here: https://alcor.concordia.ca/~gpkatch/gdate-algorithm.html
* Compiled with MS Visual Studio 2017 Community (v141), using C language options.
