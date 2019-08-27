#include "MainLoop.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Controls/Font/Font.h"
#include "../Controls/Controls.h"

namespace BoatMain
{
	void Render()
	{

		if (C::Button(10, 10, 200, 60, "Button1"))
		{
			std::cout << "BUTTON PRESSED\n";
		}
	}
}