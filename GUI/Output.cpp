#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 75;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


						//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}




//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const	//MODIFIED 
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];


	//TODO: Prepare images for each menu item and add it to the list
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";	// WAS IN THE ORIGINAL CODE
																	//MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Rect.jpg";	// WAS IN THE ORIGINAL CODE
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\rhombus.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\ellipse.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\drawcolor.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\fillcolor.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_SAVET] = "images\\MenuItems\\figure.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";	//ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\playmode.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<DRAW_ITM_COUNT-1; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	
	pWind->DrawImage(MenuItemImages[ITM_EXIT], ITM_EXIT*UI.MenuItemWidth, 0, UI.MenuItemWidth - 40, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const   // MODIFIED
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	ClearToolBar(); //added
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_TYPE] = "images\\MenuItems\\figure.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\colortype.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_DRAW_MODE] = "images\\MenuItems\\drawmode.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\Menu_Exit.jpg"; //ADDED JUST CHOOSE AN ICON

																	//Draw menu item one image at a time
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePallete() const   // Added , draw pallete bar
{
	ClearToolBar(); //added
	UI.InterfaceMode = MODE_PALLETE;
	string MenuItemImages[Pallete_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";  //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg"; //ADDED JUST CHOOSE AN ICON
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg"; //ADDED JUST CHOOSE AN ICON

																//Draw menu item one image at a time
	for (int i = 0; i < Pallete_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const  //added, remove current toolbar
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.ToolBarHeight);

}

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
void Output::PrintMessage(int msg) const
{

	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawInteger(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


//ADDED, draw line
void Output::Draw_Line(Point P1, Point P2, GfxInfo LINEGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LINEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}


//ADDED ,draw ellipse
void Output::Draw_ELLIPSE(Point P1, GfxInfo ELLIPSEGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ELLIPSEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (ELLIPSEGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ELLIPSEGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x+75, P1.y+50, P1.x-75, P1.y-50, style);
}


//ADDED, draw triangle
void Output::Draw_TRIANGLE(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TRIGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TRIGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

//Added, draw rhombus
void Output::Draw_RHOMBUS(Point P, GfxInfo RhombusGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhombusGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhombusGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int arrx[4] = { P.x + 50,P.x  ,P.x - 50 ,P.x };
	int arry[4] = { P.y ,P.y + 75 ,P.y ,P.y - 75 };
	pWind->DrawPolygon(arrx, arry, 4, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

