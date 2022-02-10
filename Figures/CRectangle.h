#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	//Ahmed
	Point Corner2;  //Ahmed
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo); //Ahmed
	virtual void Draw(Output* pOut) const; //Ahmed
	Point getPoint1()const;//Ahmed
	Point getPoint2()const;//Ahmed
	virtual bool IsPointInside(int x, int y)const;//Ahmed


	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	CRectangle();
	//Heba
};

#endif