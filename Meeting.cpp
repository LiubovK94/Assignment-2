#include "Meeting.h"
#include <iostream>


Meeting::Meeting(char const * start_, char const * end_, char const * desc_)
{
	start = DateTime(start_);
	end = DateTime(end_);
	location = desc_;

}

void Meeting::showDetails()
{
	std::cout << type << std::endl;
	std::cout << location << std::endl;
	for (auto i = attendees.begin(); i < attendees.end(); ++i){
		std::cout << (*i) << std::endl;
	}
    std::cout << start.getFormatted() << std::endl;
	std::cout << end.getFormatted() << std::endl;
}

void Meeting::addAttendee(char const * a)
{
	attendees.push_back(a);
}

Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}
