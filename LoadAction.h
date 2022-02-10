#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#ifndef LoadAction_H
#define LoadAction_H
class LoadAction :public Action
{
private:
	string name;
public:

	LoadAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
//Heba