#pragma once
#include "Actions\Action.h"

class CutAction :public Action {
public:
	CutAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};