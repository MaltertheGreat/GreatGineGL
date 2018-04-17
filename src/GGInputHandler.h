#pragma once

class GGKeyHandler
{
	friend class GGInput;
protected:
	virtual void KeyPressed(int key) = 0;
};
