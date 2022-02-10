#include "CopyAction.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include"DeleteFigureAction.h"
#include "CRhombus.h"
#include "Figures/CRectangle.h"
#include "CLine.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "GUI\input.h"
#include "GUI\Output.h"

CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp)
{
}
void CopyAction::ReadActionParameters()
{

}
void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* ptr = (pManager->GetSelecetedFigure());
	pManager->Setdown(ptr);
	CFigure* pdown = pManager->Getdown();
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		if (pManager->GetFigure(i)->getfillcolor() == GRAY) {
			pOut->ClearDrawArea();
			pOut->CreateDrawToolBar();
			pOut->CreateStatusBar();
			pManager->DecrementIDafter(i + 1);
		}
	}
	if (pdown != NULL && pdown->GetID() >= 1)
	{
		pOut->PrintMessage("Copied to clipboard");
		printf("Fig Of ID: %d\n", pdown->GetID());
		if (dynamic_cast<CRhombus*>(pdown) != NULL) {
			CRhombus *Rh = new CRhombus(pdown->getPoint1(), pdown->getinfo());
			pManager->SetCopyFigure(Rh);
			pManager->AddFigure(Rh);
			pManager->DecrementIDafter(ptr->GetID());
		}
		else if (dynamic_cast<CEllipse*>(pdown) != NULL) {
			CEllipse *E = new CEllipse(pdown->getPoint1(), pdown->getinfo());
			pManager->SetCopyFigure(E);
			pManager->AddFigure(E);
			pManager->DecrementIDafter(ptr->GetID());
		}
		else if (dynamic_cast<CTriangle*>(pdown) != NULL) {
			CTriangle *E = new CTriangle(pdown->getPoint1(), pdown->getPoint2(), pdown->getPoint3(), pdown->getinfo());
			pManager->SetCopyFigure(E);
			pManager->AddFigure(E);
			pManager->DecrementIDafter(ptr->GetID());
		}
		else if (dynamic_cast<CRectangle*>(pdown) != NULL) {
			CRectangle *E = new CRectangle(pdown->getPoint1(), pdown->getPoint2(), pdown->getinfo());
			pManager->SetCopyFigure(E);
			pManager->AddFigure(E);
			pManager->DecrementIDafter(ptr->GetID());
		}
		else if (dynamic_cast<CLine*>(pdown) != NULL) {
			CLine *E = new CLine(pdown->getPoint1(), pdown->getPoint2(), pdown->getinfo());
			pManager->SetCopyFigure(E);
			pManager->AddFigure(E);
			pManager->DecrementIDafter(ptr->GetID());
		}
		pManager->setcopypaste(0);
	}
	else
	{
		pOut->PrintMessage("No Figure Selected to copy!");
	}
}