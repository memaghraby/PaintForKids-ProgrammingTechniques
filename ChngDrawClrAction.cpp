#include"ChngDrawClrAction.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Actions\Action.h"

ChngDrawClrAction::ChngDrawClrAction(ApplicationManager *pApp) : Action(pApp) { Color = pApp->GetOutput()->getCrntDrawColor(); }

void ChngDrawClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType Act;
	if (pManager->GetSelecetedFigure())
	{
		pOut->PrintMessage("Choose a color");
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

void ChngDrawClrAction::Execute()
{
	ReadActionParameters();
	if (pManager->GetSelecetedFigure()) {
		pManager->GetSelecetedFigure()->ChngDrawClr(Color);
		UI.DrawColor = Color;
	}
}

//Heba