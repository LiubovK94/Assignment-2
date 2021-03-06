#pragma once

#include <string>
#include <sstream>
#include <iomanip>

class DateTime
{
public:
	DateTime(std::string); // parse from a string format
	std::string getFormatted() const; // return as a formatted string
	const int getHours();
	const int getMins();
	const int getDay();
	const int getMonth();
	const int getYear();
	const int getFullMin();
	long getYMin() const;

	DateTime();
	~DateTime();
private:
	int minute; // 0 to 59
	int hour; // 0 to 23
	int day; // 1 to 31
	int month; // 1 to 12
	int year;
};