#include "BugFix.h"
#include <iostream>
BugFix::BugFix(char const * start_, char const * end_, char const * desc_, char const * id_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	note = desc_;
	id = id_;

}

void BugFix::showDetails()
{
	std::cout << "     " << start.getFormatted() << " - " << end.getFormatted() << ": ";
	std::cout << "Bug #" << id << " - " << note << std::endl;
}
BugFix::BugFix()
{
}


BugFix::~BugFix()
{
}
