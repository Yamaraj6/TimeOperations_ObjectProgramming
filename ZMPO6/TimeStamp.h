#pragma once
#include "Date.h"
Date;
class TimeStamp
	:public Date
{
public:
	TimeStamp();
	TimeStamp(long long int iSeconds);
	TimeStamp(int iYear, int iMonth, int iDay, int iHour, int iMinute);
	~TimeStamp();
	void TimeStamp::vPrintTime();
	int TimeStamp::iMinutesBetween(TimeStamp cTimeStamp);
	TimeStamp* TimeStamp::operator+(int iHours);
	TimeStamp* TimeStamp::operator-(int iHours);
};

