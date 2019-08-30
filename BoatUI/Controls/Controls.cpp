#include "Controls.h"
#include "../Functional/Keyboard/Keyboard.h"
namespace C
{
	void __fastcall SetFontContext(Font* f) { fontContext = f; }

	void StartControls()
	{
		if (!AreAnyClicked())
			Keyboard::ClearBuffer();
		buttonIndex = 0;
		dropBoxIndex = 0;
		textBoxIndex = 0;
	}
}