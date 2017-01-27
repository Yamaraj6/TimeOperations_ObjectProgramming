#include "Date.h"

Date::Date()
{
	i_time_in_seconds = 0;
}

Date::Date(long long int iSeconds)
{
	i_time_in_seconds = iSeconds;
}

Date::Date(int iYear, int iMonth, int iDay)
{	i_time_in_seconds= ConvertDaysToSeconds(ConvertDateToDays(iYear, iMonth, iDay));}


Date::~Date()
{
}

long long int Date::ConvertDateToDays(int iYear, int iMonth, int iDay)
{
	long long int i_Days = iDay;
	iMonth--;

	while (iYear > 0 || iMonth > 0)
	{
		while (iMonth > 0)
		{
			i_Days += DaysInMonth(iMonth, iYear);
			iMonth--;
		}
		if(iYear > 0)
			iMonth = MONTH_IN_YEAR;
		iYear--;
	}
	return i_Days;
}

long long int Date::ConvertDaysToSeconds(long long int iDays)
{	return iDays * HOURS_IN_DAY * SECONDS_IN_HOUR;}

int Date::ConvertSecondsToDays()
{	return i_time_in_seconds / HOURS_IN_DAY / SECONDS_IN_HOUR;}

int Date::DaysInMonth(int iMonthNumber, int iYear)
{
	switch (iMonthNumber)
	{
	case 1: return 31;
	case 2:
		if (IsLeapYear(iYear))
			return 29;
		else
			return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6:	return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	default:
		return 0;
	}
}

int Date::DaysBetweenDates(Date cDate)
{
	int i_Days_Between_Two_Date = cDate.ConvertSecondsToDays() - ConvertSecondsToDays();
	return i_Days_Between_Two_Date > 0 ? i_Days_Between_Two_Date : -i_Days_Between_Two_Date;
}

void Date::GetDate(int &iOutYear, int &iOutMonth, int &iOutDay)
{
	iOutYear = 0;
	iOutMonth = 1;
	iOutDay = 1;
	int i_Days = ConvertSecondsToDays();
	while (i_Days > DAYS_IN_LEAP_YEAR || (i_Days > DAYS_IN_YEAR && !IsLeapYear(iOutYear)))
	{
		if (IsLeapYear(iOutYear))
			i_Days -= DAYS_IN_LEAP_YEAR;
		else
			i_Days -= DAYS_IN_YEAR;
		iOutYear++;
	}

	while (i_Days > DaysInMonth(iOutMonth, iOutYear))
	{
		i_Days -= DaysInMonth(iOutMonth, iOutYear);
		iOutMonth++;
	}
	if (i_Days != 0)
		iOutDay = i_Days;
}

long long int Date::GetSeconds()
{	return i_time_in_seconds;}

void Date::vPrintDate()
{
	int i_Year;
	int i_Month;
	int i_Day;
	GetDate(i_Year, i_Month, i_Day);
	cout << i_Day << ".";
	if (i_Month < 10)
		cout << "0";
	cout << i_Month << ".";
	if (i_Year < 10)
		cout << "000";
	else if (i_Year < 100)
		cout << "00";
	else if (i_Year < 1000)
		cout << "0";
	cout << i_Year << endl;
}

Date* Date::operator+(int iDays)
{
	Date* pc_New_Date = new Date(i_time_in_seconds);
	pc_New_Date->i_time_in_seconds += ConvertDaysToSeconds(iDays);
	return pc_New_Date;
}

Date* Date::operator-(int iDays)
{
	Date* pc_New_Date = new Date(i_time_in_seconds);
	pc_New_Date->i_time_in_seconds -= ConvertDaysToSeconds(iDays);
	if (pc_New_Date->i_time_in_seconds > 0)
		return pc_New_Date;
	delete pc_New_Date;
	return nullptr;
}

bool Date::operator<(Date cDate)
{	return i_time_in_seconds < cDate.i_time_in_seconds;}

bool Date::operator<=(Date cDate)
{	return i_time_in_seconds <= cDate.i_time_in_seconds;}

bool Date::operator>(Date cDate)
{	return i_time_in_seconds > cDate.i_time_in_seconds;}

bool Date::operator>=(Date cDate)
{	return i_time_in_seconds >= cDate.i_time_in_seconds;}

bool Date::operator==(Date cDate)
{	return i_time_in_seconds == cDate.i_time_in_seconds;}

bool IsLeapYear(int iYear)
{	return ((iYear % 4 == 0 && iYear % 100 != 0) || iYear % 400 == 0);}