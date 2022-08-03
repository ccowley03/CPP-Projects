#include "MainApp.h"

wxIMPLEMENT_APP(MainApp);

MainApp::MainApp()
{
}

MainApp::~MainApp()
{
}

bool MainApp::OnInit()
{
	frame = new MainFrame();
	frame->Show();
	return true;
}
