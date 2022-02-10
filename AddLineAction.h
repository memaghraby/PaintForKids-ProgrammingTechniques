#ifndef ADDLINEACTION_H
#define ADDLINEACTION_H
#include "Actions/Action.h"
class AddLineAction :
	public Action
{
private:
	Point P1, P2; //Line terminals
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);
	//Reads line parameters
	virtual void ReadActionParameters();
	//Add line to the ApplicationManager
	virtual void Execute();
};
//Ahmed
#endif