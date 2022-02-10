#include "CTriangle.h"
#include "Function.h"
#include <string>
#include <fstream>
CTriangle::CTriangle(Point P1, Point P2,Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}

void CTriangle::Draw(Output * pOut) const
{
	//Call Output::Draw_TRIANGLE to Draw a Triangle on the screen
	pOut->Draw_TRIANGLE(Point1, Point2, Point3, FigGfxInfo, Selected);
}
Point CTriangle::getPoint1() const
{
	return Point1;
}
Point CTriangle::getPoint2() const
{
	return Point2;
}
Point CTriangle::getPoint3() const
{
	return Point3;
}
Point CTriangle::getcenter(){
	center.x = (Point1.x+(2/3)*((Point2.x+Point3.x)/2-Point1.x));
	center.y = (Point1.y + (2 / 3)*((Point2.y + Point3.y) / 2 - Point1.y));
	return center;
}
bool CTriangle::IsPointInside(int x, int y) const
{
	Point P1, P2, P3;
	P1 = getPoint1();
	P2 = getPoint3();
	P3 = getPoint2();
	Point temp;

	if (P1.x < P2.x)
	{
		temp = P2;
		P2 = P1;
		P1 = temp;
	}
	if (P1.x < P3.x)
	{
		temp = P3;
		P3 = P1;
		P1 = temp;
	}
	if (P2.x < P3.x)
	{
		temp = P2;
		P2 = P1;
		P1 = temp;
	}
	double a1 = Area(x, P2.x, P3.x, y, P2.y, P3.y);
	double a2 = Area(P1.x, x, P3.x, P1.y, y, P3.y);
	double a3 = Area(P1.x, P2.x, x, P1.y, P2.y, y);
	double totalArea = a1 + a2 + a3;
	double OriginalArea = Area(P1.x, P2.x, P3.x, P1.y, P2.y, P3.y);
	if (totalArea == OriginalArea)
	{
		return true;
	}
	return false;
}
//Ahmed
void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "TRIANG \t" << GetID() << "\t" << Point1.x << "\t" << Point1.y << "\t" << Point2.x << "\t" << Point2.y << "\t" << Point3.x << "\t" << Point3.y << "\t" << GetColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CTriangle::Load(ifstream &Infile)
{
	string Drawclr, Fillclr;
	Infile >> ID >> Point1.x >> Point1.y >> Point2.x >> Point2.y >> Point3.x >> Point3.y >> Drawclr >> Fillclr;
	FigGfxInfo.DrawClr = StringToColor(Drawclr);

	if (Fillclr == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = StringToColor(Fillclr);
		FigGfxInfo.isFilled = true;
	}

	Selected = false;
}
CTriangle::CTriangle()
{
}
//Heba