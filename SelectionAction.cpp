#include "SelectionAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


SelectionAction::SelectionAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SelectionAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at the figure you want to select");

	pIn->GetPointClicked(SelectionPoint.x, SelectionPoint.y);
}

void SelectionAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	CFigure* ptr = (pManager->GetFigure(SelectionPoint.x, SelectionPoint.y));

	pManager->SetSelectedFigure(ptr);
	/*if ((pManager->GetSelecetedFigure()) == NULL)
	{
		ptr->SetSelected(true);
		pManager->SetSelectedFigure(ptr);
	}
	else if (ptr->IsSelected())
	{
		ptr->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}
	else
	{
		CFigure* C = pManager->GetSelecetedFigure();
		C->SetSelected(false);
		pManager->SetSelectedFigure(ptr);
	}*/
	
}

//Ahmed