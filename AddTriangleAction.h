#ifndef ADDTRIANGLEACTION_H
#define ADDTRIANGLEACTION_H
#include "Actions\Action.h"
class AddTriangleAction :
	public Action
{
private:
	Point P1, P2 ,P3; //Triangle Corners
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager *pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();
};

#endif
//Ahmed