#pragma once
class FilePath
{
public:
	static char* Create(char* const buffer, int bufSize, const char* const path, const char* const stamp, const char* const filename);
};

