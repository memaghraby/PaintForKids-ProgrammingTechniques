#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}


Point CFigure::getPoint1() const
{
	return Point();
}

Point CFigure::getPoint2() const
{
	return Point();
}
color CFigure::getdrawcolor() {
	return FigGfxInfo.DrawClr;
}

color CFigure::getfillcolor() {
	return FigGfxInfo.FillClr;
}
GfxInfo CFigure::getinfo()const {
	return FigGfxInfo;
}

Point CFigure::getPoint3() const
{
	return Point();
}

void CFigure::SetID(int x)
{
	ID = x;
}

int CFigure::GetID() const
{
	return ID;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
void CFigure::Save(ofstream &OutFile)
{
}
void CFigure::Load(ifstream &Infile)
{
}
color CFigure::GetColor() const
{
	if (FigGfxInfo.isFilled)
		return FigGfxInfo.FillClr;
	return GREY;
}
CFigure::CFigure()
{

}
color StringToColor(string S)
{
	if (S == "red")
	{
		return RED;
	}
	else if (S == "green")
	{
		return GREEN;
	}
	else if (S == "blue")
	{
		return BLUE;
	}
	else if (S == "yellow")
	{
		return YELLOW;
	}
	else if (S == "black")
	{
		return BLACK;
	}
}
string GetColorName(color c)
{
	if (c == RED)
	{
		return "red";
	}
	else if (c == GREEN)
	{
		return "green";
	}
	else if (c == BLUE)
	{
		return "blue";
	}
	else if (c == YELLOW)
	{
		return "yellow";
	}
	else if (c == BLACK)
	{
		return "black";
	}
}
