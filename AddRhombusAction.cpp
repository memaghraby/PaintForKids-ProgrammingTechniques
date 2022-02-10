#include "AddRhombusAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{
}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at Center");

	//Read Center and store in point C
	pIn->GetPointClicked(C.x, C.y);

	RhombusGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *Rh = new CRhombus(C, RhombusGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(Rh);
}
//Ahmed

