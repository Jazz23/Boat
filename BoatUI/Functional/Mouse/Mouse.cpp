#include <Windows.h>

#include "Mouse.h"


namespace Mouse
{
	bool LeftKey, RightKey;
	size_t __x = 0, __y = 0;
	
	void  GetPos(size_t& x, size_t& y)
	{
		x = __x; y = __y;
	}
	void  SetPos(const size_t& x, const size_t& y)
	{
		__x = x; __y = y;
	}
	bool IsDown(short btn)
	{
		return ((btn == K_MOUSE_LEFT && LeftKey) || (btn == K_MOUSE_RIGHT && RightKey));
	}
	void LeftDown() { LeftKey = true; }
	void LeftUp() { LeftKey = false; }
	void RightDown() { RightKey = true; }
	void RightUp() { RightKey = false; }
}
