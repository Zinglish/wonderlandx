#include "logger.h"

#include <cstdarg>
#include <stdio.h>

#include <pinc.h>

Logger::Logger() {}
Logger::Logger(const Logger& orig) {}
Logger::~Logger() {}

void Logger::LogInfo(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	
	char fmtBuf[2048];
	char buf[2048];
	
	// We have to do these obscure formats because developers apparently hate variadic functions.
	// I wonder who that is...
	snprintf(fmtBuf, sizeof(fmtBuf), "[WonderlandX][\033[1;34mInfo\033[0m]: %s\n", format);
	vsnprintf(buf, sizeof(buf), fmtBuf, args);
	
	Plugin_Printf(buf);
	
	va_end(args);
}