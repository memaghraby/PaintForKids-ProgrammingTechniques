#include"LoadAction.h"
#include <fstream>
#include"Figures/CFigure.h"
#include"Figures/\CRectangle.h"
#include"CTriangle.h"
#include"CEllipse.h"
#include"CLine.h"
#include"CRhombus.h"
LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp)
{
}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter File name.");
	name = pIn->GetString(pOut);
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	pOut->ClearDrawArea();
	pManager->DeleteAllFigures();
	ifstream File(name + ".txt");

	if (File.is_open())
	{
		pManager->SetID(0);

		string Drawcolor;
		string Fillcolor;

		File >> Drawcolor >> Fillcolor;

		UI.DrawColor = StringToColor(Drawcolor);

		if (Fillcolor == "NO_FILL")
		{
			UI.Filled = false;
		}
		else {
			UI.FillColor = StringToColor(Fillcolor); 
			UI.Filled = true;
		}

		int count;
		File >> count;

		CFigure* Temp;
		string type;

		int tempID;

		for (int i = 0; i<count; i++)
		{
			File >> type;
			if (type == "RECT")
				Temp = new CRectangle;

			else if (type == "TRIANG")
				Temp = new CTriangle;

			else if (type == "ELLIPSE")
				Temp = new CEllipse;

			else if (type == "RHOMBUS")
				Temp = new CRhombus;

			else
				Temp = new CLine;

			Temp->Load(File);
			tempID = Temp->GetID();
			pManager->SetID(tempID - 1);
			pManager->AddFigure(Temp);

		}

		pManager->SetID(count);
		pOut->ClearStatusBar();

		pOut->PrintMessage("File loaded. Have Fun :)");
	}

	else
		pOut->PrintMessage("There is no File with that name!");
}
//Heba