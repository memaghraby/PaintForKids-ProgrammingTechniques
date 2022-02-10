#include"Actions/Action.h"
#include"SaveGraphAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include<string.h>
SaveGraphAction::SaveGraphAction(ApplicationManager *pApp) :Action(pApp)
{
}
void SaveGraphAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file without spaces ");


	name = pIn->GetString(pOut) + ".txt";

	OutFile.open(name);

	if (OutFile.is_open())
	{
		pOut->PrintMessage("The file has been saved ");
	}
	else {
		pOut->PrintMessage("Unable to save file");
	}

}

void SaveGraphAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (OutFile.is_open())
	{
		int nfigures = pManager->GetFiguresCount();
		string DrawColor = GetColorName(UI.DrawColor);   //get the draw color
		OutFile << DrawColor;
		if (UI.Filled)                                   //check if there is a fill
		{
			string FillColor = GetColorName(UI.FillColor);  //get the fill color
			OutFile << '\t' << FillColor << endl;
		}
		else
		{
			OutFile << '\t' << "NO_FILL" << endl;
		}
		OutFile << nfigures << endl;
		pManager->SaveAll(OutFile);       //save all figures
		OutFile.close();                  //close the file
	}
}
//Heba