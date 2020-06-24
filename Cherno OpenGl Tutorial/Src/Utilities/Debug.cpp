#include "Debug.h"

std::vector<Debug::LogLevel> Debug::m_LogFilter = { Debug::LogLevel::Error, Debug::LogLevel::Warning, Debug::LogLevel::Info };

void Debug::SetLogFilter(std::vector<LogLevel> _level)
{
	m_LogFilter = _level;
}

void Debug::LogInfo(const char* _msg, const char* _head)
{
	for (LogLevel _filter : m_LogFilter)
		if (_filter == LogLevel::Info)
			std::cout << "[Log - " << _head << "]: " << _msg << std::endl;
}

void Debug::LogWarning(const char* _msg, const char* _head)
{
	for (LogLevel _filter : m_LogFilter)
		if (_filter == LogLevel::Warning)
			std::cout << "[Warning - " << _head << "]: " << _msg << std::endl;
}

void Debug::LogError(const char* _msg, const char* _head)
{
	for (LogLevel _filter : m_LogFilter)
		if (_filter == LogLevel::Error)
			std::cout << "[Error - " << _head << "]: " << _msg << std::endl;
}

void Debug::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

void Debug::GLCheckError()
{
	while (GLenum _error = glGetError())
		std::cout << "[OPENGL ERROR]: " << _error << std::endl;
}

bool Debug::GLLogCall(const char* _function, const char* _file, int _line)
{
	while (GLenum _error = glGetError()) 
	{
		std::cout << "[OpenGL ERROR (" << _error << ")]:"<< _function << _file << ":line." << _line << std::endl;
		return false;
	}
	return true;
}
