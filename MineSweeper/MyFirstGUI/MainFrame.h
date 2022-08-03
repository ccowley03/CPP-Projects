#pragma once
#include "wx/wx.h"
#include "GridButton.h"
#include <vector>
class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();
	void OnButtonClick(wxCommandEvent& event);
	void GameReset();
	void GameStart(int x, int y);
	int MineCount(int x,int y);
	int width = 10;
	int height = 10;
	wxButton** buttons;
	int* fields = nullptr;

	bool bclick = true;
	

	wxDECLARE_EVENT_TABLE();
};

