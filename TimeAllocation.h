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
	const int getEndMins();
	long getYMins()  const;

	TimeAllocation();
	~TimeAllocation();
};

const std::ostream& operator << (std::ostream& os, TimeAllocation& tA);
bool operator<(const TimeAllocation& t1, const TimeAllocation& t2);