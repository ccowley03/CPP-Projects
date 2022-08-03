#include "MainFrame.h"

#include <stdlib.h>
wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_BUTTON(10001,OnButtonClick)
wxEND_EVENT_TABLE()



MainFrame::MainFrame()
	: wxFrame(nullptr, wxID_ANY, "MINESWEEPER V1.0", wxPoint(40, 40), wxSize(800, 600))
{

	buttons = new wxButton * [width * height];
	wxGridSizer* grid = new wxGridSizer(width, height, 0, 0);
	
	fields = new int[width * height];
	
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			
			buttons[y * width + x] = new wxButton(this, 10000 + (y * width + x));
			grid->Add(buttons[y * width + x], 1, wxEXPAND | wxALL);

			buttons[y * width + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonClick, this);
			fields[y * width + x] = 0;

		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

MainFrame::~MainFrame()
{
	delete[]buttons;
	delete[]fields;
}

void MainFrame::OnButtonClick(wxCommandEvent& event)
{
	
	int x = (event.GetId() - 10000) % width;
	int y = (event.GetId() - 10000) / width;
	
	
	GameStart(x, y);

	
	event.Skip();

}

void MainFrame::GameReset()
{
	bclick = true;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			fields[y * width + x] = 0;
			buttons[y * width + x]->SetLabel("");
			buttons[y * width + x]->Enable(true);
		}
	}
	

}


void MainFrame::GameStart(int x,int y)
{
	int mines = 30;

	if (bclick == true)
	{
		while (mines != 0)
		{
			int randX = rand() % width;
			int randY = rand() % height;

			if (fields[randY * width + randX] == 0 && randX != x && randY != y)
			{
				fields[randY * width + randX] = -1;
				mines--;
			}

		}
		bclick = false;
	}
	
	
	
	
	buttons[y * width + x]->Enable(false);

	if (fields[y * width + x] == -1)
	{
		wxMessageBox("GAME OVER");

		GameReset();
	}
	else
	{
		int Mcount = MineCount(x,y);
		if (Mcount == 1)
		{
			buttons[y * width + x]->SetLabel(std::to_string(Mcount));
			
			buttons[y * width + x]->SetForegroundColour(wxColour(70, 130, 180));
		}
		else if (Mcount == 2)
		{
			buttons[y * width + x]->SetLabel(std::to_string(Mcount));
			buttons[y * width + x]->SetOwnForegroundColour("GREEN");

		}
		else if (Mcount == 3)
		{
			buttons[y * width + x]->SetLabel(std::to_string(Mcount));
			buttons[y * width + x]->SetOwnForegroundColour("RED");
		}
		
	}
}

int MainFrame::MineCount(int x, int  y)
{
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((x + i >= 0) && (x + 1 < width) &&
				(y + j >= 0) && (y + j < height))
			{
				if (fields[(y + j) * width + (x + i)] == -1)
				{
					count++;

				}
			}
		}
	}
	return count;

};