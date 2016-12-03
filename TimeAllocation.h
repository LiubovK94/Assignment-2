#pragma once
#include "DateTime.h"
class TimeAllocation
{
private:
	DateTime start;
	DateTime end;

public:
	virtual void showDetails() = 0;
	TimeAllocation();
	~TimeAllocation();
};

