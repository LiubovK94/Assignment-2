#include "DateTime.h"


DateTime::DateTime(std::string datetime)
{
	// DD/MM/YYYY HH:MM
	std::istringstream iss(datetime);
	char dump;
	iss >> day >> dump >> month >> dump >> year >> hour >> dump >> minute;
}
std::string DateTime::getFormatted() const
{
	// DD/MM/YYYY HH:MM
	std::ostringstream oss;
	oss << std::setfill('0');
	oss << std::setw(2) << day << '/';
	oss << std::setw(2) << month << '/';
	oss << year << ' ';
	oss << std::setw(2) << hour << ':';
	oss << std::setw(2) << minute;
	return oss.str();
}

const int DateTime::getFullMin() //returns hour & min in minutes only
{
	int m = 0;
	m = hour * 60 + minute;
	return m;
}
const int DateTime::getHours(){ return hour; }
const int DateTime::getMins(){ return minute; }
const int DateTime::getDay(){ return day; }
const int DateTime::getMonth(){ return month; }
const int DateTime::getYear(){ return year; }

long DateTime::getYMin() const //converting provided date into minutes only
{
	long min = 0;
	switch (month)
	{
	case 1: min = ((year * 8760) * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 2: min = ((year * 8760) * 60 + 31 * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 3: min = ((year * 8760) * 60 + (31 + 28) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 4: min = ((year * 8760) * 60 + (31 * 2 + 28) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 5: min = ((year * 8760) * 60 + (31 * 2 + 28 + 30) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 6: min = ((year * 8760) * 60 + (31 * 3 + 28 + 30) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 7: min = ((year * 8760) * 60 + (31 * 3 + 28 + 30 * 2) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 8: min = ((year * 8760) * 60 + (31 * 4 + 28 + 30 * 2) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 9: min = ((year * 8760) * 60 + (31 * 4 + 28 + 30 * 3) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 10: min = ((year * 8760) * 60 + (31 * 5 + 28 + 30 * 3) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 11: min = ((year * 8760) * 60 + (31 * 5 + 28 + 30 * 4) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	case 12: min = ((year * 8760) * 60 + (31 * 6 + 28 + 30 * 3) * 24 * 60 + day * 24 * 60 + hour * 60 + min); break;
	default:break;
	}
	return min;
}


DateTime::DateTime()
{
}


DateTime::~DateTime()
{
}
