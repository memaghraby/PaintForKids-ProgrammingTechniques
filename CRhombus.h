#ifndef CRHOMBUS_H
#define CRHOMBUS_H
#include "Function.h"
#include "Figures\CFigure.h"
class CRhombus :
	public CFigure
{
private:
	Point Center;//Ahmed

public:
	CRhombus(Point C, GfxInfo FigureGfxInfo);//Ahmed
	virtual void Draw(Output* pOut) const;//Ahmed
	Point getPoint1()const;//Ahmed
	Point getcenter()const;//Mahmoud
	virtual bool IsPointInside(int x, int y)const;//Ahmed

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	CRhombus();
	//Heba
};
#endif
