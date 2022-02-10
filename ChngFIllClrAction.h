#pragma once
#include"Actions/Action.h"
class ChngFIllClrAction :public Action
{
private:
	color Color;
public:

	ChngFIllClrAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
//Heba