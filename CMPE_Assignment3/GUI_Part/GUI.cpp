#include "GUI.h"


int WinMain() {
	GUI_Part::GUI^ g = gcnew GUI_Part::GUI();
	GUI_Part::Application::Run(g);
	return 0;
}
