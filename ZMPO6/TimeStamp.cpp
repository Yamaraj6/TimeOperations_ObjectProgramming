#include "TimeStamp.h"



TimeStamp::TimeStamp()
	:Date(){}

TimeStamp::TimeStamp(long long int iSeconds)
	:Date(iSeconds){}

TimeStamp::TimeStamp(int iYear, int iMonth, int iDay, int iHour, int iMinute)
	:Date(iYear, iMonth, iDay)
{
	i_time_in_seconds += iHour * 3600;
	i_time_in_seconds += iMinute * 60;
}


TimeStamp::~TimeStamp()
{
}

void TimeStamp::vPrintTime()
{
	int i_Hour;
	int i_Minute;
	i_Hour = (i_time_in_seconds % (HOURS_IN_DAY * SECONDS_IN_HOUR)) / SECONDS_IN_HOUR;
	i_Minute = (i_time_in_seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;

	std::cout << i_Hour << ":";
	if (i_Minute < 10)
		cout << "0";
	cout << i_Minute << endl;
	vPrintDate();
}

int TimeStamp::iMinutesBetween(TimeStamp cTimeStamp)
{
	int i_Minutes_Between = (i_time_in_seconds - cTimeStamp.i_time_in_seconds);
	return i_Minutes_Between > 0 ? i_Minutes_Between / SECONDS_IN_MINUTE : -i_Minutes_Between / SECONDS_IN_MINUTE;
}

TimeStamp* TimeStamp::operator+(int iHours)
{
	TimeStamp* pc_Time_Stamp = new TimeStamp(i_time_in_seconds);
	pc_Time_Stamp->i_time_in_seconds += (iHours*SECONDS_IN_HOUR);
	return pc_Time_Stamp;
}

TimeStamp* TimeStamp::operator-(int iHours)
{
	TimeStamp* pc_Time_Stamp = new TimeStamp(i_time_in_seconds);
	pc_Time_Stamp->i_time_in_seconds -= (iHours * SECONDS_IN_HOUR);
	if (pc_Time_Stamp->i_time_in_seconds > 0)
		return pc_Time_Stamp;
	delete pc_Time_Stamp;
	return nullptr;
}