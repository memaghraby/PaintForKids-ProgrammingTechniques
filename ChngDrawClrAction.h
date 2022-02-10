#pragma once
#ifndef ChngDrawClrAction_H
#define ChngDrawClrAction_H
#include"Actions/Action.h"

class ChngDrawClrAction :public Action
{
private:
	color Color;
public:

	ChngDrawClrAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
//Heba