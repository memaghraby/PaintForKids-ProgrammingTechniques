#ifndef SELECTIONACTION_H
#define SELECTIONACTION_H
#include "Actions\Action.h"
class SelectionAction :public Action
{
private:
	Point SelectionPoint;
public:
	SelectionAction(ApplicationManager *pApp);
	//Read Parameters
	virtual void ReadActionParameters();

	//Selecting the figure
	virtual void Execute();
};
//Ahmed
#endif 
