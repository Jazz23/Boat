#pragma once
#include <vector>
typedef unsigned char byte;


class RC4
{
public:

	RC4(std::vector<byte> key) : key(key)
	{

	}

	void cipher()
private:
	byte state[256];
	std::vector<byte> key;
	byte i, j;

	void memes()
	{


	}
};