#pragma once
#ifndef PlayModeAction_H
#define PlayModeAction_H

#include"Actions/Action.h"

class PlayModeAction :public Action
{
public:
	PlayModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif