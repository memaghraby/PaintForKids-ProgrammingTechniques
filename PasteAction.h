#pragma once
#include "Actions\Action.h"

class PasteAction :public Action {
	Point p;
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};