#pragma once
#include "DateTime.h"
#include<iostream>
class TimeAllocation
{
protected:
	DateTime start;
	DateTime end;

public:
	virtual const void showDetails() = 0;
	virtual const std::string getStart();
	virtual const std::string getEnd();
	virtual const int getStartMins();
	virtual const int getStartHours();
	virtual const int getEndMins();
	virtual const int getEndHours();
	virtual const long getYMins();
	
	TimeAllocation();
	~TimeAllocation();
};

 const std::ostream& operator << (std::ostream& os, TimeAllocation& tA);