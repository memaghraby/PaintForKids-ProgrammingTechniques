#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_PALLETE
};

enum DrawMenuItem  //MODIFIED HIMA  //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	//Recangle item in menu



	//(Line, Rectangle, Triangle, Rhombus and Ellipse). 

	//TODO: Add more items names here
	ITM_LINE,		//ADDED
					//ITM_CIRC,		//Circle item in menu
					ITM_RECT,		//THIS WAS IN THE ORIGINAL CODE
					ITM_TRIANGLE,   //ADDED 
					ITM_RHOMBUS,	//ADDED
					ITM_ELLIPSE,	//ADDED
					ITM_SELECT,
					ITM_CHNG_DRAW_CLR,
					ITM_CHNG_FILL_CLR,
					ITM_DELETE,
					ITM_COPY,
					ITM_CUT,
					ITM_PASTE,
					ITM_SAVE,
					ITM_SAVET,
					ITM_LOAD,
					ITM_PLAY_MODE,	//ADDED FOR ADDED TO SWITCH BETWEEN MODES
					ITM_EXIT,		//Exit item

					DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem   //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_TYPE,          //added
	ITM_FILL_COLOR,
	ITM_DRAW_MODE,
	ITM_EXIT1,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PalleteMenuItem //added
{
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_YELLOW,
	ITM_BLACK,
	Pallete_ITM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu

	bool Filled;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

							/// Add more members if needed

}UI;	//create a global object UI

#endif