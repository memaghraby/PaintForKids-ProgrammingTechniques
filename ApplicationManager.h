#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* down;
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	int copypaste;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int LastID;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //modified by Ahmed          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void SetSelectedFigure(CFigure*);//Ahmed
	CFigure* GetSelecetedFigure()const;//Ahmed
	CFigure* GetFigure(int i);//Ahmed
	void DecrementIDafter(int);//Ahmed
	void SetCopyFigure(CFigure* modern);//Mahmoud
	void SetCutFigure(CFigure* gry);//Mahmoud
	CFigure* Getdown();
	void Setdown(CFigure* modern);//Mahmoud
	void setcopypaste(int x);
	int getcopypaste();
	void nullClipboard();//Mahmoud
	CFigure* GetClipboard()const;//Mahmoud
	int GetFiguresCount(); //Heba
	void SaveAll(ofstream&);//Heba
	void SetID(int);//Heba
	int GetID();//Heba
	void DeleteAllFigures();//Heba
	void SaveByType(ofstream & out, string);//Heba
	int CountType(string);//Heba
	int GetFigCount();//Heba
	void UpdateInterface() const;	//Redraws all the drawing window
};

#endif
