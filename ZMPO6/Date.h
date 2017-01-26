#pragma once
class Date
{
private:
	int i_year;
	int i_month;
	int i_day;

	int Date::ConvertDateToDays(Date cDate);
	int Date::DaysInMonth(int iMonthNumber, int iYear);

public:
	Date();
	Date(int iYear, int iMonth, int iDay);
	~Date();
	int Date::DaysBetweenTwoDate(Date cFirstDate, Date cSecondDate);
	//Date Date::operator-(Date a);
};

