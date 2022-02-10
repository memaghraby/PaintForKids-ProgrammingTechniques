#include"SaveByTypeAction.h"
#include"Actions/Action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
SaveByTypeAction::SaveByTypeAction(ApplicationManager *pApp) :Action(pApp)
{

}
void SaveByTypeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose a figure type to save: ");
	ActionType Act;
	Act = pIn->GetUserAction();
	switch (Act)
	{
	case DRAW_RECT:
		type = ("rect");
		break;
	case DRAW_LINE:
		type = ("line");
		break;

	case DRAW_ELLIPSE:
		type = ("ellipse");
		break;
	case DRAW_TRI:
		type = ("triangle");
		break;
	case DRAW_RHOMBUS:
		type = ("rhombus");
		break;
	default:
		pOut->PrintMessage("Error! You didn't choose a figure type");
		break;
		}

		pOut->PrintMessage("Enter the name of the file without spaces ");
		name = pIn->GetString(pOut) + ".txt";
		OutFile.open(name);

		if (OutFile.is_open())
		{
			pOut->PrintMessage("Your file has been Successfully Saved");
		}
		else {
			pOut->PrintMessage("Unable to save file");
		}
}
void SaveByTypeAction::Execute()
{
	ReadActionParameters();

	if (OutFile.is_open())
	{
		int nfigures = pManager->CountType(type);
		string DrawColor = GetColorName(UI.DrawColor);   //get the draw color
		OutFile << DrawColor;
		string FillColor = GetColorName(UI.FillColor);  //get the fill color
		OutFile << '\t' << FillColor << endl;
		OutFile << nfigures << endl;
		pManager->SaveByType(OutFile,type);         //save all figures
		OutFile.close();                            //close the file
	}

}
//Heba