#include "CLine.h"
#include "Function.h"
#include "ApplicationManager.h"
#include <string>
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

void CLine::Draw(Output * pOut) const
{
	//Call Output::Draw_Line to draw a Line on the screen	
	pOut->Draw_Line(Point1, Point2, FigGfxInfo, Selected);
}
Point CLine::getPoint1() const
{
	return Point1;
}
Point CLine::getPoint2() const
{
	return Point2;
}
/*Point CLine::getcenter()const {
	Point center;
	center.x = (Point1.x - Point2.x) / 2;
	center.y = (Point1.y - Point2.y) / 2;
	return center;
}*/

bool CLine::IsPointInside(int x,int y) const
{
	/*if (Point1.x == Point2.x && Point1.y < Point2.y)
	{
		if (y >= Point1.y && y <= Point2.y)
		{
			return true;
		}
		else { return false; }
	}
	else if (Point1.x == Point2.x && Point1.y > Point2.y)
	{
		if (y <= Point1.y && y >= Point2.y)
		{
			return true;
		}
		else { return false; }
	}
	else if ((((Point2).y - y) / ((Point2).x - x)) == (((Point2).y - (Point1).y) / ((Point2).x - (Point1).x)))
	{
		if (Point1.x <=Point2.x && Point1.y >= Point2.y && y <= Point1.y && y >= Point2.y && x >= Point1.x && x <= Point2.x)
		{
			return true;
		}
		else if (Point1.x <= Point2.x && Point1.y <=Point2.y && y >= Point1.y && y <= Point2.y && x >= Point1.x && x <=Point2.x)
		{
			return true;
		}
		else if (Point1.x >= Point2.x && Point1.y <=Point2.y && y >= Point1.y && y <=Point2.y && x <= Point1.x && x >= Point2.x)
		{
			return true;
		}
		else if (Point1.x >= Point2.x && Point1.y >= Point2.y && y <=Point1.y && y >= Point2.y && x <= Point1.x && x >= Point2.x)
		{
			return true;
		}
		else { return false; }
	}
	else return false;*/
	double a1 = Area(x, Point2.x, Point1.x+10, y, Point2.y, Point1.y+10);
	double a2 = Area(Point1.x, x, Point1.x+10, Point1.y, y, Point1.y+10);
	double a3 = Area(Point1.x, Point2.x, x, Point1.y, Point2.y, y);
	double A1 = Area(x, Point2.x, Point2.x + 10, y, Point2.y, Point2.y + 10);
	double A2 = Area(Point1.x, x, Point2.x + 10, Point1.y, y, Point2.y + 10);
	double A3 = Area(Point1.x, Point2.x, x, Point1.y, Point2.y, y);
	double b1 = Area(x, Point2.x, Point1.x + 10, y, Point2.y, Point1.y + 10);
	double b2 = Area(Point1.x, x, Point1.x + 10, Point1.y, y, Point1.y + 10);
	double b3 = Area(Point1.x, Point2.x, x, Point1.y, Point2.y, y);
	double B1 = Area(x, Point2.x, Point2.x - 10, y, Point2.y, Point2.y - 10);
	double B2 = Area(Point1.x, x, Point2.x - 10, Point1.y, y, Point2.y - 10);
	double B3 = Area(Point1.x, Point2.x, x, Point1.y, Point2.y, y);
	double totalArea1 = a1 + a2 + a3;
	double totalArea2 = A1 + A2 + A3;
	double totalArea3 = b1 + b2 + b3;
	double totalArea4 = B1 + B2 + B3;
	double OriginalArea = Area(Point1.x, Point2.x, Point1.x+10, Point1.y, Point2.y, Point1.y+10);
	if (totalArea1 == OriginalArea|| totalArea2 == OriginalArea || totalArea3 == OriginalArea || totalArea4 == OriginalArea)
	{
		return true;
	}
	return false;
}
//Ahmed
void CLine::Save(ofstream &OutFile)
{
	OutFile << "LINE\t" << GetID() << "\t" << Point1.x << "\t" << Point1.y << "\t" << Point2.x << "\t" << Point2.y << "\t" << GetColorName(GetColor()) << endl;
}
void CLine::Load(ifstream &Infile)
{
	string Drawclr;
	Infile >> ID >> Point1.x >> Point1.y >> Point2.x >> Point2.y >> Drawclr;
	FigGfxInfo.DrawClr = StringToColor(Drawclr);

	Selected = false;
	

}
CLine::CLine()
{
}
//Heba