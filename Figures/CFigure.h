#ifndef CFIGURE_H
#define CFIGURE_H
#include "..\defs.h"
#include "..\GUI\Output.h"

color StringToColor(string S);
string GetColorName(color c);
//Base class for all figures
class CFigure

{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool IsPointInside(int, int) const { return false; }

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	virtual Point getPoint1()const; //Ahmed
	virtual Point getPoint2()const; //Ahmed
	virtual Point getPoint3()const; //Ahmed
	color getdrawcolor();
	color getfillcolor();
	GfxInfo getinfo()const;
	void SetID(int); //Ahmed
	int GetID()const; //Ahmed

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color



	virtual void Save(ofstream &OutFile) = 0;	
	virtual void Load(ifstream &Infile) = 0;
	color GetColor() const;
	CFigure();
	//Heba
};


#endif