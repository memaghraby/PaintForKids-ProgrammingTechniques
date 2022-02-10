#include "DeleteFigureAction.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


DeleteFigureAction::DeleteFigureAction(ApplicationManager *pApp): Action(pApp)
{
}
void DeleteFigureAction::ReadActionParameters()
{
	
}
void DeleteFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* ptr = (pManager->GetSelecetedFigure());
	if (ptr != NULL&&ptr->GetID()>=1)
	{
		pOut->PrintMessage("Figure Deleted");
		printf("Fig Of ID: %d\n", ptr->GetID());
		pOut->ClearDrawArea();
		pOut->CreateDrawToolBar();
		pOut->CreateStatusBar();
		pManager->DecrementIDafter((ptr->GetID()));
	}
	else
	{
		pOut->PrintMessage("No Figure Selected to delete!");
	}
}


