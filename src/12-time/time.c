#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

/*This allows us to refer to localtime(…) and time_t structures 
gives us the current time broken into the appropriate portions  
See the method that follows:
*/
void printDate(){
	//create the structure which will hold current time
	time_t pt;
	//create the structure that will hold the broken down time info
	struct tm* times;
	//set up initial structure
	char c[100];
	time(&pt);
	//assign local time to our target structure
	times = localtime(&pt);
	/* structure contains the following:
	times->tm_min - current minute (0-59)
	times->tm_hour - current hour (0-23)
	times->tm_mon - current month (0-11)
	times->tm_mday - current day (1-31)
	times->tm_year - number of elapsed years since 1900
	*/
	printf("Direct access to tm object\n");
	printf("%d/%d/%d %d%dhrs\n",times->tm_mon+1,times->tm_mday,times->tm_year+1900,times->tm_hour,times->tm_min);
	strftime(c,100,"%A, %B %d, %Y %I:%M:%S %p %Z",times);
	printf("Long Time (strftime)\n%s\n",c);
	strftime(c,100,"%m-%d-%y %H%Mhrs %Z",times);
	printf("Short Time (strftime)\n%s\n",c);

}
/* 
tm structure
struct tm {
    int tm_sec;        seconds after the minute (from 0)
    int tm_min;        minutes after the hour (from 0)
    int tm_hour;       hour of the day (from 0)
    int tm_mday;       day of the month (from 1)
    int tm_mon;        month of the year (from 0)
    int tm_year;       years since 1900 (from 0)
    int tm_wday;       days since Sunday (from 0)
    int tm_yday;       day of the year (from 0)
    int tm_isdst;      Daylight Saving Time flag
    };

strftime variables
    %a    abbreviated weekday name (Sun)
    %A    full weekday name (Sunday)
    %b    abbreviated month name (Dec)
    %B    full month name (December)
    %c    date and time (Dec  2 06:55:15 1979)
    %d    day of the month (02)
    %H    hour of the 24-hour day (06)
    %I    hour of the 12-hour day (06)
    %j    day of the year, from 001 (335)
    %m    month of the year, from 01 (12)
    %M    minutes after the hour (55)
    %p    AM/PM indicator (AM)
    %S    seconds after the minute (15)
    %U    Sunday week of the year, from 00 (48)
    %w    day of the week, from 0 for Sunday (6)
    %W    Monday week of the year, from 00 (47)
    %x    date (Dec  2 1979)
    %X    time (06:55:15)
    %y    year of the century, from 00 (79)
    %Y    year (1979)
    %Z    time zone name, if any (EST)
    %%    percent character %
*/
void main(){
	printDate();
}
