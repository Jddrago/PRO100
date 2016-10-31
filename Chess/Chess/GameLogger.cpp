#include "GameLogger.h"
#include <iostream>
#include <ctime>
#include <string.h>
#include "FilePath.h"
#include <assert.h>
#include "timeStamp.h"

std::ofstream GameLogger::m_logStream;
int GameLogger::m_counts[int(LogMsgType::NumOfTypes)]{0};

GameLogger::GameLogger()
{
}


GameLogger::~GameLogger()
{
}

bool GameLogger::Initialize(const char * const path, const char * const filename)
{
	assert(filename);
	assert(*filename);
	const int pathsize = 512;
	char file[pathsize];

	const int stampSize = 80;
	char stamp[stampSize];
	timeStamp::TimeStamp(stamp, stampSize);

	FilePath::Create(file, pathsize, path, stamp, filename);

	m_logStream.open(file, std::ios::trunc);
	if (!m_logStream.good()) 
	{
		return false;
	}
	else
	{
		Log("%s GameLogger::Initialize() opened log file [%s] for writing\n",EnumToString(LogMsgType::Process), file);
		Log("%s GameLogger::Initialize() successful\n", EnumToString(LogMsgType::Process));
		return true;
	}
}

bool GameLogger::Shutdown()
{
	if (m_logStream.is_open()) 
	{
		Log("%s GameLogger::ShutDown() successful", EnumToString(LogMsgType::Process));
		m_logStream.close();
		return true;
	}
	return false;
}

void GameLogger::WriteLog(const char * const msg)
{
	const int stampSize = 80;
	char stamp[stampSize];
	timeStamp::TimeStamp(stamp, stampSize);
	if (m_logStream.is_open())
	{
		m_logStream << stamp << " " << msg;
	}
	else 
	{
		std::cout << stamp << " " << msg;
	}
}

char * GameLogger::EnumToString(LogMsgType msg)
{
	switch (msg) 
	{
	case LogMsgType::Process: return "Process";
	case LogMsgType::Warning: return "Warning";
	case LogMsgType::Error: return "Error";
	case LogMsgType::FatalError: return "Fatal Error";
	case LogMsgType::Debug: return "Debug";
	case LogMsgType::Info: return "Info";
	default: return "";
	}
}
