#pragma once
#include "wx/wx.h"
#include "MainFrame.h"

class MainApp : public wxApp
{
public:
	MainApp();
	~MainApp();
	

private:
	MainFrame* frame = nullptr;
public:
	virtual bool OnInit();

};

