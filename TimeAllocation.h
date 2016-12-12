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
	TimeAllocation();
	~TimeAllocation();
};

 const std::ostream& operator << (std::ostream& os, TimeAllocation& tA);