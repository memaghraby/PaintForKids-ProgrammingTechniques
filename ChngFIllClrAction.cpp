#include"ChngFIllClrAction.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Actions\Action.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include"DEFS.h"
ChngFIllClrAction::ChngFIllClrAction(ApplicationManager *pApp) : Action(pApp) { Color = pApp->GetOutput()->getCrntDrawColor(); }

void ChngFIllClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType Act;
	if (pManager->GetSelecetedFigure())
	{
		pOut->PrintMessage("Please choose a color");
		pOut->CreatePallete();
		Act = pIn->GetUserAction();
		switch (Act) {
		case R:
			Color = RED;
			break;
		case B:
			Color = BLUE;
			break;
		case BB:
			Color = BLACK;
			break;
		case Y:
			Color = YELLOW;
			break;
		case G:
			Color = DARKGREEN;
			break;
		default:
			break;
		}
		pOut->ClearToolBar();
		pOut->CreateDrawToolBar();
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage("Select a figure first");
	}
}

void ChngFIllClrAction::Execute()
{
	ReadActionParameters();
	if (pManager->GetSelecetedFigure()) {
		pManager->GetSelecetedFigure()->ChngFillClr(Color);
		UI.FillColor = Color;
		UI.Filled = true;
	}
}
//Heba