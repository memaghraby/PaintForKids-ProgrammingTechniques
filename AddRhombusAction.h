#ifndef ADDRHOMBUSACTION_H
#define ADDRHOMBUSACTION_H
#include "Actions\Action.h"

class AddRhombusAction :
	public Action
{
private:
	Point C; //Rhombus Center
	GfxInfo RhombusGfxInfo;

public:
	AddRhombusAction(ApplicationManager *pApp);
	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();
};

#endif
//Ahmed