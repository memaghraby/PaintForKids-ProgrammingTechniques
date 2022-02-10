#include "CRectangle.h"
#include "../ApplicationManager.h"
#include <string>
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

Point CRectangle::getPoint1() const
{
	return Corner1;
}

Point CRectangle::getPoint2() const
{
	return Corner2;
}


bool CRectangle::IsPointInside(int x, int y) const
{
	if (getPoint1().x <= getPoint2().x && getPoint1().y >= getPoint2().y && y <= getPoint1().y && y >= getPoint2().y && x >= getPoint1().x && x <= getPoint2().x)
	{
		return true;
	}
	else if (getPoint1().x <= getPoint2().x && getPoint1().y <= getPoint2().y && y >= getPoint1().y && y <= getPoint2().y && x >= getPoint1().x && x <= getPoint2().x)
	{
		return true;
	}
	else if (getPoint1().x >= getPoint2().x && getPoint1().y <= getPoint2().y && y >= getPoint1().y && y <= getPoint2().y && x <= getPoint1().x && x >= getPoint2().x)
	{
		return true;
	}
	else if (getPoint1().x >= getPoint2().x && getPoint1().y >= getPoint2().y && y <= getPoint1().y && y >= getPoint2().y && x <= getPoint1().x && x >= getPoint2().x)
	{
		return true;
	}
	return false;
}
void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "RECT\t" << GetID() << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << GetColorName(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CRectangle::Load(ifstream &Infile)
{
	string Drawclr, Fillclr;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Drawclr >> Fillclr;

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
CRectangle::CRectangle()
{
}
//Heba
