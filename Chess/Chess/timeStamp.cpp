#include "timeStamp.h"
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

const char * timeStamp::TimeStamp(char * const buffer, int bufsize, bool useColons)
{
	const char* const format = useColons ? "%F %T." : "%F %H-%M-%S.";

	const int millisize = 5;
	char millibuf[millisize];
	struct _timeb timebuffer;
	_ftime64_s(&timebuffer);
	unsigned short millitime = timebuffer.millitm;
	sprintf_s(millibuf, millisize, "%03d.", millitime);

	time_t rawTime;
	time(&rawTime);
	struct tm timeInfo;
	localtime_s(&timeInfo, &rawTime);
	strftime(buffer, bufsize, format, &timeInfo);
	strcat_s(buffer, bufsize, millibuf);
	return buffer;
}

std::ostream & operator<<(std::ostream & os, timeStamp& /*t*/)
{
	const int stampSize = 50;
	char stampBuffer[stampSize];
	return os << timeStamp::TimeStamp(stampBuffer, stampSize, true);
}
