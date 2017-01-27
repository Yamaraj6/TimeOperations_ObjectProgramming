#pragma once
#include<iostream>

using namespace std;
#define MONTH_IN_YEAR 12
#define DAYS_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600

class Date
{
protected:
	long long int i_time_in_seconds;

	long long int Date::ConvertDateToDays(int iYear, int iMonth, int iDay);
	long long int Date::ConvertDaysToSeconds(long long int iDays);
	int Date::ConvertSecondsToDays();
	int Date::DaysInMonth(int iMonthNumber, int iYear);

public:
	Date();
	Date(long long int iSeconds);
	Date(int iYear, int iMonth, int iDay);
	~Date();
	int Date::DaysBetweenDates(Date cDate);
	void Date::GetDate(int &iOutYear, int &iOutMonth, int &iOutDay);
	long long int Date::GetSeconds();
	void Date::vPrintDate();
	Date* Date::operator+(int iDays);
	Date* Date::operator-(int iDays);
	bool Date::operator<(Date cDate);
	bool Date::operator<=(Date cDate);
	bool Date::operator>(Date cDate);
	bool Date::operator>=(Date cDate);
	bool Date::operator==(Date cDate);
};

bool IsLeapYear(int iYear);