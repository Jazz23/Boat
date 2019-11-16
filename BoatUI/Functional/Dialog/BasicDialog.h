#pragma once

class BasicDialog
{
private:

public:
	BasicDialog()
	{

	}
	virtual void Draw() { return; } //called per draw
	virtual void MakeMove() { return; } //called per update tick because we dont need to update as fast as we draw
};