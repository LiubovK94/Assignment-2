#include "BugFix.h"
#include <iostream>
BugFix::BugFix(std::string &start_, std::string &end_, std::string &desc_, std::string &id_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	note = desc_;
	id = id_;

}
const int BugFix::getStartMins(){ return start.getMins(); }

const int BugFix::getStartHours(){ return start.getHours(); }


const int BugFix::getEndMins(){ return end.getMins(); }

const int BugFix::getEndHours(){ return end.getHours(); }


const void BugFix::showDetails()
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

const std::string BugFix::getStart(){ return start.getFormatted(); }
const std::string BugFix::getEnd(){ return end.getFormatted(); }
const std::string BugFix::getNote(){ return note; }
const std::string BugFix::getId(){ return id; }

const std::ostream& operator << (std::ostream& os, BugFix& b)
{
	os << "     " << b.getStart() << " - " << b.getEnd() << ": ";
	os << "Bug #" << b.getId() << " - " << b.getNote() << std::endl;
	return os;
}