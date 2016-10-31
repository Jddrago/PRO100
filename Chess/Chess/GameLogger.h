#ifndef GAMELOGGER_H_
#define GAMELOGGER_H_

	// Jason Delorie
	// 5/3/16
	// GameLogger.h
	// Simple Logging for games

#include <fstream>
#include "LogMsgType.h"

class GameLogger
{
public:
	

	public:
		GameLogger();
		~GameLogger();
	public: // public static methods
		static bool Initialize(const char* const path, const char* const filename);
		static bool Shutdown();

		template<typename...Args>
		static void Log(const char* const format, Args... args);
		static char * EnumToString(LogMsgType msg);

	private: // private static methods
		static void WriteLog(const char* const msg); // pre-pend time, error level, etc

	private: // private static data
		static std::ofstream m_logStream;
		static int m_counts[int(LogMsgType::NumOfTypes)];
	};

	template<typename ...Args>
	inline void GameLogger::Log(const char * const format, Args ...args)
	{
		const int bufSize = 400;
		char buffer[bufSize];
		sprintf_s(buffer, bufSize, format, args...);
		WriteLog(buffer);
	}
#endif // ndef GAMELOGGER_H_
