#pragma once
#include "DateTime.h"
#include<iostream>
class TimeAllocation
{
protected:
	DateTime start;
	DateTime end;

public:
	 virtual const std::stringstream showDetails() = 0;
	 const std::string getStart();
	 const std::string getEnd();
	 const int getStartMins();
	 const int getStartHours();
	 const int getEndMins();
	 const int getEndHours();
	 const long getYMins();
	
	TimeAllocation();
	~TimeAllocation();
};

 const std::ostream& operator << (std::ostream& os, TimeAllocation& tA);