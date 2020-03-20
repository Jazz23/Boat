#pragma once

#define K_MOUSE_LEFT	1
#define K_MOUSE_RIGHT	2
#define K_MOUSE_MIDDLE	3

namespace Mouse
{
	void  GetPos(size_t& x, size_t& y);
	void  SetPos(const size_t& x, const size_t& y);

	bool IsDown(short btn);
	void LeftDown();
	void LeftUp();
	void RightDown();
	void RightUp();
}