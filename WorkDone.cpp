#include "WorkDone.h"
#include "TimeAllocation.h"
#include <iostream>

WorkDone::WorkDone(char const * start_, char const * end_, char const * desc_) 
{
	start = DateTime(start_);
	end = DateTime(end_);
	description = desc_;

}


void WorkDone::showDetails()
{
	std::cout << type << std::endl;
	std::cout << description << std::endl;
}

WorkDone::WorkDone()
{
}


WorkDone::~WorkDone()
{
}
