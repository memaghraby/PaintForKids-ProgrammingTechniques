#ifndef ADDELLIPSEACTION_H
#define ADDELLIPSEACTION_H
#include "Actions\Action.h"
class AddEllipseAction :
	public Action
{
private:
	Point P1, P2; //Ellipse Drawing Points
	GfxInfo EllipseGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);
	
	//Reads Ellipse parameters
	virtual void ReadActionParameters();

	//Add Ellipse to the ApplicationManager
	virtual void Execute();

};
#endif
//Ahmed