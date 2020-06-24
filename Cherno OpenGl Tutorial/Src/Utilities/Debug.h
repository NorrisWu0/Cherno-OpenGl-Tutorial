#pragma once
#include <GL/glew.h>

#include <iostream>
#include <vector>

#define Assert(_x) if (!(_x)) __debugbreak();
#define GLCall(_x) Debug::GLClearError(); _x; Assert(Debug::GLLogCall(#_x, __FILE__, __LINE__)) // Will not work with functions in if statement and if the line assign a variable

class Debug
{
public:
	enum class LogLevel
	{
		Error, Warning, Info
	};

	Debug() = delete;

	static void SetLogFilter(std::vector<LogLevel> _level);
	static void LogInfo(const char* _msg, const char* _head = "N/A");
	static void LogWarning(const char* _msg, const char* _head = "N/A");
	static void LogError(const char* _msg, const char* _head = "N/A");
	static void GLClearError();
	static void GLCheckError();
	static bool GLLogCall(const char* _function, const char* _file, int _line);

private:
	static std::vector<Debug::LogLevel> m_LogFilter;
};