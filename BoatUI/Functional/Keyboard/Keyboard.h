#pragma once

namespace Keyboard
{
	void  SetMaxQueueBufferSize(size_t s);
	void  ReportCharacter(char c);
	void ClearBuffer();
	char ReadChar();
	void TrimBuffer();
	bool HasChar();

	void  KeyDown(char c);
	void  KeyUp(char c);
	
}