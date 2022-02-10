#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window * pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreatePallete() const; //added,draw palette bar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //added, delete toolbar

							   // -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

																						  ///Make similar functions for drawing all other figures.

	void Draw_Line(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const; //ADDED   //Draw a Line

	void Draw_ELLIPSE(Point P1, GfxInfo, bool selected = false) const;//ADDED  //Draw an Ellipse

	void Draw_TRIANGLE(Point P1, Point P2, Point p3, GfxInfo, bool selected = false) const;//ADDED  //Draw a Triangle

	void Draw_RHOMBUS(Point P, GfxInfo, bool selected = false) const;  //Draw a rhombus

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PrintMessage(int msg) const;

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif