#pragma once
#ifndef SaveGraphAction_H
#define SaveGraphAction_H
#include"Actions/Action.h"
#include <fstream>
class SaveGraphAction :public Action
{
private:

	string name;
	ofstream OutFile;

public:

	SaveGraphAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
//Heba