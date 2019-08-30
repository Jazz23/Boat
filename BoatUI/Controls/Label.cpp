#include "Controls.h"

namespace C
{
	void Label(int x, int y, const std::string_view& str)
	{
		assert(fontContext);
		fontContext->PutText(str, x, y, LABEL_TEXT_COLOR);
	}
}