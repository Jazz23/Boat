#include "MainLoop.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Controls/Font/Font.h"
#include "../Controls/Controls.h"

namespace BoatMain
{
	std::string_view wWords[4] = { "val1", "val2", "val3", "val4" };
	int meme = 0;
	std::string str = "";
	bool tbool = false;
	void Render()
	{
		//C::Dropbox(10, 10, 100, 50, 4, wWords, &meme);
		//C::TextBox("Memes", 10, 10, 200, 50, &str);
		//if (C::Button(10, 10, 150, 40, "Memes"))
		//	std::cout << "memes";
		C::CheckBox(10, 50, "CheckBox1", &tbool);
		std::cout << tbool << "\n";
	}
}