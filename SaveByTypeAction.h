#pragma once
#ifndef SaveByTypeAction_H
#define SaveByTypeAction_H
#include"Actions/Action.h"
#include <fstream>
#include"string"
class SaveByTypeAction : public Action
{
private:

	string name;
	ofstream OutFile;
	string type;

public:

	SaveByTypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
//Heba
