#include <Windows.h>
#include <queue>

#include "Keyboard.h"

namespace Keyboard
{
	size_t MAX_QUEUE_BUFFER = 1000;
	std::queue<char> buffer;

	void  SetMaxQueueBufferSize(size_t s)
	{
		MAX_QUEUE_BUFFER = s;
	}
	void TrimBuffer()
	{
		while (buffer.size() > MAX_QUEUE_BUFFER)
			buffer.pop();
	}
	void  ReportCharacter(char c)
	{
		buffer.push(c);
		TrimBuffer();
	}
	char ReadChar()
	{
		if (buffer.size() > 0)
		{
			unsigned char c = buffer.front();
			buffer.pop();
			return c;
		}
		else
			return 0;
	}
	void ClearBuffer()
	{
		while (buffer.size() > 0)
			buffer.pop();
	}
	bool HasChar()
	{
		return !!(buffer.size() > 0);
	}


	bool DownCharacters[256] = { false };

	void  KeyDown(char c)
	{
		DownCharacters[c] = true;
	}
	void  KeyUp(char c)
	{
		DownCharacters[c] = false;
	}

}