#ifndef CELLIPSE_H
#define CELLIPSE_H
#include "Figures\CFigure.h"
class CEllipse :
	public CFigure
{
private:
	Point Point1;
//	Point Point2;
public:
	//CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	CEllipse(Point, GfxInfo FigureGfxInfo);//Ahmed
	Point getcenter()const; //Mahmoud
	virtual void Draw(Output* pOut) const;//Ahmed
	virtual Point getPoint1()const;//Ahmed
	virtual bool IsPointInside(int x, int y)const;//Ahmed

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	CEllipse();
	//Heba
};

#endif

