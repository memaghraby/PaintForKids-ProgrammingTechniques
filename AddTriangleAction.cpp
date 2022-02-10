#include "AddTriangleAction.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


AddTriangleAction::AddTriangleAction(ApplicationManager * pApp) : Action(pApp)
{
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Corner");

	//Read 1st Corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second Corner");

	//Read 2nd Corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third Corner");

	//Read 2nd Corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled
										//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTriangle *T = new CTriangle(P1, P2, P3,TriangleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(T);
}
