#include "CEllipse.h"
#include <string>
#include <fstream>
#include"Figures/CFigure.h"
/*CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}*/
CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
}
Point CEllipse::getcenter()const {
	return getPoint1();
}

void CEllipse::Draw(Output * pOut) const
{
	//Call Output::DrawEllipse to draw an Ellipse on the screen	
	pOut->Draw_ELLIPSE(Point1,FigGfxInfo, Selected);
}
Point CEllipse::getPoint1() const
{
	return Point1;
}
bool CEllipse::IsPointInside(int x, int y) const
{
	Point c = getPoint1();
	double ans = (pow((x - c.x), 2) / pow(75, 2)) + (pow((y - c.y), 2) / pow(50, 2));
	if (ans <= 1)
	{
		return true;
	}
	return false;
}
//Ahmed


void CEllipse::Save(ofstream &OutFile)
{
	OutFile << "ELLIPSE\t" << GetID() << "\t" << Point1.x << "\t" << Point1.y << "\t" << GetColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CEllipse::Load(ifstream &Infile)
{
	string Drawclr, Fillclr;
	Infile >> ID >> Point1.x >> Point1.y >> Drawclr >> Fillclr;
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
CEllipse::CEllipse()
{
}
//Heba