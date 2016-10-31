#ifndef LOGMSGTYPE_H_
#define LOGMSGTYPE_H_

// Jason Delorie
// 5/3/16
// LOGMSGTYPE.h
// Enum Class for the different types of messages

#include <ostream>
enum class LogMsgType 
	{
		Process, Warning, Error, FatalError, Info, Debug 
		, NumOfTypes
	};


#endif // ndef LOGMSGTYPE_H_
