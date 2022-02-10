#include "PasteAction.h"
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

PasteAction::PasteAction(ApplicationManager *pApp) : Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at point to paste");

	//Read Center and store in point C
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* ptr = (pManager->GetSelecetedFigure());
	CFigure* ptrr = (pManager->GetClipboard());
	CFigure* pdown = pManager->Getdown();
	Point p1, p2;
	if (ptrr != NULL && pdown !=NULL) {
		ReadActionParameters();
		if (dynamic_cast<CRhombus*>(pdown) != NULL) {
			CRhombus *Rh = new CRhombus(p, pdown->getinfo());
			pManager->AddFigure(Rh);
			pOut->PrintMessage("paste done");
		}
		else if (dynamic_cast<CEllipse*>(pdown) != NULL) {
			CEllipse *E = new CEllipse(p, pdown->getinfo());
			pManager->AddFigure(E);
			pOut->PrintMessage("paste done");
		}
		else if (dynamic_cast<CTriangle*>(pdown) != NULL) {
			double dx = p.x - (ptrr->getPoint1().x);
			double dy = p.y - (ptrr->getPoint1().y);
			p1.x = (ptrr->getPoint2().x) + dx;
			p1.y = (ptrr->getPoint2().y) + dy;
			p2.x = (ptrr->getPoint3().x) + dx;
			p2.y = (ptrr->getPoint3().y) + dy;
			CTriangle *E = new CTriangle(p, p1, p2, pdown->getinfo());
			pManager->AddFigure(E);
			pOut->PrintMessage("paste done");
		}
		else if (dynamic_cast<CRectangle*>(ptrr) != NULL) {
			double dx = p.x - (ptrr->getPoint1().x);
			double dy = p.y - (ptrr->getPoint1().y);
			p1.x = (ptrr->getPoint2().x) + dx;
			p1.y = (ptrr->getPoint2().y) + dy;
			CRectangle *E = new CRectangle(p, p1, pdown->getinfo());
			pManager->AddFigure(E);
			pOut->PrintMessage("paste done");
		}
		else if (dynamic_cast<CLine*>(ptrr) != NULL) {
			double dx = p.x - (pdown->getPoint1().x);
			double dy = p.y - (pdown->getPoint1().y);
			p1.x = (pdown->getPoint2().x) + dx;
			p1.y = (pdown->getPoint2().y) + dy;
			CLine *E = new CLine(p, p1, pdown->getinfo());
			pManager->AddFigure(E);
			pOut->PrintMessage("paste done");
		}
	}
	else { pOut->PrintMessage("nothing to paste"); }

	if (pdown != NULL && ptrr != NULL && pManager->getcopypaste()==1) {
			pOut->ClearDrawArea();
			pOut->CreateDrawToolBar();
			pOut->CreateStatusBar();
			pManager->DecrementIDafter((pdown->GetID()));
			pManager->DecrementIDafter((ptrr->GetID()));
			ptrr = NULL;
			pManager->setcopypaste(2);
	}
	if (ptr != NULL && ptrr != NULL && pManager->getcopypaste() == 0) {
		/*pOut->ClearDrawArea();
		pOut->CreateDrawToolBar();
		pOut->CreateStatusBar();
		pManager->DecrementIDafter((ptr->GetID()));
		//pManager->DecrementIDafter((ptrr->GetID()));
		ptrr = NULL;*/
		pManager->setcopypaste(2);
	}
}