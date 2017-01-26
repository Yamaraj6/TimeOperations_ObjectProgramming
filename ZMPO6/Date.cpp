#include "Date.h"



Date::Date()
{
	i_year = 0;
	i_month = 0;
	i_day = 0;
}

Date::Date(int iYear, int iMonth, int iDay)
{
	if (iMonth <= 12)
	{
		i_year = iYear;
		i_month = iMonth;
	}
	else
	{
		int i_Temp=iMonth/12;
		i_year = iYear + i_Temp;
		i_month = iMonth%12;
	}
	i_day = iDay;
}


Date::~Date()
{
}

int Date::DaysBetweenTwoDate(Date cFirstDate, Date cSecondDate)
{

}

int Date::ConvertDateToDays(Date cDate)
{
	int i_Year = cDate.i_year;
	int i_Month = cDate.i_month;
	int i_Day = 0;
	int i_Days = cDate.i_day;
	
	while (i_Year > 0 || i_Month > 0)
	{
		while (i_Month > 0)
		{
			i_Day = DaysInMonth(i_Month, i_Year);
			i_Month--;
			while (i_Day > 0)
			{
				i_Days = i_Days + i_Day;
				i_Day = 0;
			}
		}
		i_Month = 12;

	}
}

int Date::DaysInMonth(int iMonthNumber, int iYear)
{
	switch (iMonthNumber)
	{
	case 1: return 31;
	case 2:
		if ((iYear % 4 == 0 && iYear % 100 != 0) || iYear % 400 == 0)
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