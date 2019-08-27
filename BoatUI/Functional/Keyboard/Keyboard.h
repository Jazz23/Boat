#pragma once

namespace Keyboard
{
	void __fastcall SetMaxQueueBufferSize(size_t s);
	void __fastcall ReportCharacter(char c);
	void ClearBuffer();
	char ReadChar();
	void TrimBuffer();
	bool HasChar();

	void __fastcall KeyDown(char c);
	void __fastcall KeyUp(char c);
	
}