#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "Function.h"
#include "Figures\CFigure.h"
class CTriangle :
	public CFigure
{
private:
	Point Point1, Point2, Point3;//Ahmed
	Point center; //mahmoud
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);//Ahmed
	virtual void Draw(Output* pOut) const;//Ahmed
	Point getcenter(); //Mahmoud
	Point getPoint1()const;//Ahmed
	Point getPoint2()const;//Ahmed
	Point getPoint3()const;//Ahmed
	virtual bool IsPointInside(int x, int y)const;//Ahmed

	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	CTriangle();
	//Heba
};

#endif