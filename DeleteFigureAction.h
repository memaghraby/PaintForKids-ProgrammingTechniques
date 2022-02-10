#ifndef DELETEFIGRUEACTION_H
#define DELETEFIGRUEACTION_H
#include "Actions\Action.h"
class DeleteFigureAction :public Action
{
public:
	DeleteFigureAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
//Ahmed
#endif
