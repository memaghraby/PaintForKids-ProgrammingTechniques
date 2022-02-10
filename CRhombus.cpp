#include "CRhombus.h"
#include <string>
#include <fstream>
CRhombus::CRhombus(Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = C;
}

void CRhombus::Draw(Output * pOut) const
{
	//Call Output::Draw_RHOMBUS to draw a Rhombus on the screen	
	pOut->Draw_RHOMBUS(Center,FigGfxInfo, Selected);
}
Point CRhombus::getPoint1() const
{
	return Center;
}
Point CRhombus::getcenter()const {
	return getPoint1();
}
bool CRhombus::IsPointInside(int x, int y) const
{
	Point c = getPoint1();
	Point p1, p2, p3, p4;
	p1 = c; p1.x += 50;
	p2 = c; p2.x -= 50;
	p3 = c; p3.y += 75;
	p4 = c; p4.y -= 75;

	double a1 = Area(x, p2.x, p3.x, y, p2.y, p3.y);
	double a2 = Area(p1.x, x, p3.x, p1.y, y, p3.y);
	double totalArea = a1 + a2;
	a1 = Area(x, p2.x, p4.x, y, p2.y, p4.y);
	a2 = Area(p1.x, x, p4.x, p1.y, y, p4.y);
	totalArea = totalArea + a1 + a2;
	totalArea /= 2;


	double A1 = Area(c.x, p1.x, p2.x, c.y, p1.y, p2.y);
	double A2 = Area(c.x, p3.x, p2.x, c.y, p3.y, p2.y);
	double A3 = Area(c.x, p4.x, p3.x, c.y, p4.y, p3.y);
	double A4 = Area(c.x, p1.x, p4.x, c.y, p1.y, p4.y);

	if (totalArea == A1 + A2 + A3 + A4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Ahmed
void CRhombus::Save(ofstream &OutFile)
{
	OutFile << "RHOMBUS\t" << GetID() << "\t" << Center.x << "\t" << Center.y << "\t" << GetColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CRhombus::Load(ifstream &Infile)
{
	string Drawclr, Fillclr;
	Infile >> ID >> Center.x >> Center.y >> Drawclr >> Fillclr;
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
CRhombus::CRhombus()
{
}
//Heba