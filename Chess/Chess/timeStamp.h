#pragma once
#include <ostream>
class timeStamp
{
public:
	static const char* TimeStamp(char* const buffer, int bufsize, bool useColons = false);
};

std::ostream& operator<<(std::ostream& os, timeStamp& list);
