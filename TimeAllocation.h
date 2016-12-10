#pragma once
#include "DateTime.h"
class TimeAllocation
{
protected:
	DateTime start;
	DateTime end;

public:
	virtual void showDetails() = 0;
	TimeAllocation();
	~TimeAllocation();
};

