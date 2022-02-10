#include "AddEllipseAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



AddEllipseAction::AddEllipseAction(ApplicationManager *pApp): Action(pApp)
{
	
}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	EllipseGfxInfo.isFilled = false;	//default is not filled
										//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CEllipse *E = new CEllipse(P1, EllipseGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(E);
}
//Ahmed