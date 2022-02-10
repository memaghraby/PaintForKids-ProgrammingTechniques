#ifndef CLINE_H
#define CLINE_H
#include "Figures\CFigure.h"
class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);//Ahmed
	virtual void Draw(Output* pOut) const;//Ahmed
	Point getPoint1()const;//Ahmed
	Point getPoint2()const;//Ahmed
	//Point getcenter()const;
	virtual bool IsPointInside(int x, int y)const;//Ahmed

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	CLine();
	//Heba
};

#endif