#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddLineAction.h"
#include "AddEllipseAction.h"
#include "AddTriangleAction.h"
#include "AddRhombusAction.h"
#include "SelectionAction.h"
#include"ChngDrawClrAction.h"
#include"ChngFIllClrAction.h"
#include"SaveByTypeAction.h"
#include"SaveGraphAction.h"
#include"LoadAction.h"
#include"ToPlayModeAction.h"
#include "CLine.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CRhombus.h"
#include "Figures/CRectangle.h"
#include "Figures/CFigure.h"
#include "DeleteFigureAction.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "CutAction.h"
#include "PasteAction.h"
#include "CopyAction.h"
//#include "Function.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	LastID = 0;
	FigCount = 0;
	SelectedFig = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLineAction(this);//Ahmed
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);//Ahmed
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);//Ahmed
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);//Ahmed
			break;

		case SELECT:
			pAct = new SelectionAction(this);//Ahmed
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChngDrawClrAction(this);//Heba
			break;

		case CHNG_FILL_CLR:
			pAct = new ChngFIllClrAction(this);//Heba
			break;

		case COPY:
			pAct = new CopyAction(this);//Mahmoud
			break;

		case CUT:
			pAct = new CutAction(this);//Mahmoud
			break;

		case DEL:
			pAct = new DeleteFigureAction(this);//Ahmed
			break;

		case PASTE:
			pAct = new PasteAction(this);//Mahmoud
			break;
		case SAVE:
			pAct = new SaveGraphAction(this);//Heba
			break;

		case LOAD:
			pAct = new LoadAction(this);//Heba
			break;
		case TO_PLAY:
			pAct = new PlayModeAction(this);//Heba
			break;
		case SAVET:
			pAct = new SaveByTypeAction(this); //Heba
			break;

		case EXIT:
			///create ExitAction here
			int x, y;
			pOut->PrintMessage("Action: EXIT,click anywhere to exit");
			pIn->GetPointClicked(x, y);
			pAct = NULL;
			return;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		LastID++;
		pFig->SetID(LastID);
		printf("ID : %d\n", pFig->GetID());
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const//Ahmed
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (dynamic_cast<CLine*>(FigList[i]) != NULL)
		{
			bool ans = FigList[i]->IsPointInside(x, y);
			if (ans == true)
			{
				
				/*pOut->PrintMessage("Line ");
				_sleep(200);
				pOut->PrintMessage("ID : ");
				_sleep(200);
				pOut->PrintMessage(FigList[i]->GetID());
				_sleep(200);
				pOut->PrintMessage("Point1-x : ");
				_sleep(200);
				pOut->PrintMessage(FigList[i]->getPoint1().x);
				_sleep(200);
				pOut->PrintMessage("Point1-y : ");
				_sleep(200);
				pOut->PrintMessage(FigList[i]->getPoint1().y);
				_sleep(200);
				pOut->PrintMessage("Point2-x : ");
				pOut->PrintMessage(FigList[i]->getPoint2().x);
				_sleep(200);
				pOut->PrintMessage("Point2-y : ");
				_sleep(200);
				pOut->PrintMessage(FigList[i]->getPoint2().y);
				_sleep(200);
				pOut->PrintMessage("Length : ");
				_sleep(200);
				pOut->PrintMessage(sqrt((pow((FigList[i]->getPoint1().x- FigList[i]->getPoint2().x),2))+ pow((FigList[i]->getPoint1().y - FigList[i]->getPoint2().y), 2)));*/
				ofstream output;
				output.open("test.txt", ios::out);
				output << "Line ID: " << FigList[i]->GetID() << " (" << FigList[i]->getPoint1().x << "," << FigList[i]->getPoint1().y << ") " << "(" << FigList[i]->getPoint2().x << "," << FigList[i]->getPoint2().y << ")" << " Length :" << sqrt((pow((FigList[i]->getPoint1().x - FigList[i]->getPoint2().x), 2)) + pow((FigList[i]->getPoint1().y - FigList[i]->getPoint2().y), 2));
				output.close();
				ifstream input("test.txt", ios::in);
				if (input.is_open())
				{
					char* text = new char[100];
					input.getline(text, 100, '\n');
					pOut->PrintMessage(text);
				}
				return FigList[i];
			}
			/*{
				if (FigList[i]->getPoint1().x == FigList[i]->getPoint2().x && FigList[i]->getPoint1().y < FigList[i]->getPoint2().y)
				{
					if (y >= FigList[i]->getPoint1().y && y <= FigList[i]->getPoint2().y)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					
				}
				else if (FigList[i]->getPoint1().x == FigList[i]->getPoint2().x && FigList[i]->getPoint1().y > FigList[i]->getPoint2().y)
				{
					if (y <= FigList[i]->getPoint1().y && y >= FigList[i]->getPoint2().y)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					
				}
				else if ((((FigList[i]->getPoint2()).y - y) / ((FigList[i]->getPoint2()).x - x)) == (((FigList[i]->getPoint2()).y - (FigList[i]->getPoint1()).y) / ((FigList[i]->getPoint2()).x - (FigList[i]->getPoint1()).x)))
				{
					if (FigList[i]->getPoint1().x <= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y >= this->FigList[i]->getPoint2().y && y <= FigList[i]->getPoint1().y && y >= FigList[i]->getPoint2().y && x >= FigList[i]->getPoint1().x && x <= FigList[i]->getPoint2().x)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					else if (FigList[i]->getPoint1().x <= FigList[i]->getPoint2().x &&FigList[i]->getPoint1().y <= FigList[i]->getPoint2().y && y >= FigList[i]->getPoint1().y && y <= FigList[i]->getPoint2().y && x >= FigList[i]->getPoint1().x && x <= FigList[i]->getPoint2().x)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					else if (FigList[i]->getPoint1().x >= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y <= FigList[i]->getPoint2().y && y >= FigList[i]->getPoint1().y && y <= FigList[i]->getPoint2().y && x <= FigList[i]->getPoint1().x && x >= FigList[i]->getPoint2().x)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					else if (FigList[i]->getPoint1().x >= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y >= FigList[i]->getPoint2().y && y <= FigList[i]->getPoint1().y && y >= FigList[i]->getPoint2().y && x <= FigList[i]->getPoint1().x && x >= FigList[i]->getPoint2().x)
					{
						pOut->PrintMessage("Line !!");
						return FigList[i];
					}
					
				}
			}*/
		}
		else if (dynamic_cast<CRectangle*>(FigList[i]) != NULL)
		{
			if (FigList[i]->IsPointInside(x, y))
			{
				ofstream output;
				output.open("test.txt", ios::out);
				output << "Rectangle ID: " << FigList[i]->GetID() << " (" << FigList[i]->getPoint1().x << "," << FigList[i]->getPoint1().y << ") " << "(" << FigList[i]->getPoint2().x << "," << FigList[i]->getPoint2().y << ")" << " Length :" << sqrt((pow((FigList[i]->getPoint1().x - FigList[i]->getPoint2().x), 2)))<<" Width :" << sqrt((pow((FigList[i]->getPoint1().y - FigList[i]->getPoint2().y), 2)));
				output.close();
				ifstream input("test.txt", ios::in);
				if (input.is_open())
				{
					char* text = new char[100];
					input.getline(text, 100, '\n');
					pOut->PrintMessage(text);
				}
				return FigList[i];
			}
			/*if (FigList[i]->getPoint1().x <= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y >= FigList[i]->getPoint2().y && y <= FigList[i]->getPoint1().y && y >= FigList[i]->getPoint2().y && x >= FigList[i]->getPoint1().x && x <= FigList[i]->getPoint2().x)
			{
				pOut->PrintMessage("Rectangle selected");
				return FigList[i];
			}
			else if (FigList[i]->getPoint1().x <= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y <= FigList[i]->getPoint2().y && y >= FigList[i]->getPoint1().y && y <= FigList[i]->getPoint2().y && x >= FigList[i]->getPoint1().x && x <= FigList[i]->getPoint2().x)
			{
				pOut->PrintMessage("Rectangle selected");
				return FigList[i];
			}
			else if (FigList[i]->getPoint1().x >= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y <= FigList[i]->getPoint2().y && y >= FigList[i]->getPoint1().y && y <= FigList[i]->getPoint2().y && x <= FigList[i]->getPoint1().x && x >= FigList[i]->getPoint2().x)
			{
				pOut->PrintMessage("Rectangle selected");
				return FigList[i];
			}
			else if (FigList[i]->getPoint1().x >= FigList[i]->getPoint2().x && FigList[i]->getPoint1().y >= FigList[i]->getPoint2().y && y <= FigList[i]->getPoint1().y && y >= FigList[i]->getPoint2().y && x <= FigList[i]->getPoint1().x && x >= FigList[i]->getPoint2().x)
			{
				pOut->PrintMessage("Rectangle selected");
				return FigList[i];
			}*/
		}
		else if (dynamic_cast<CRhombus*>(FigList[i]) != NULL)
		{
			if (FigList[i]->IsPointInside(x, y))
			{
				ofstream output;
				output.open("test.txt", ios::out);
				output << "Rhombus ID: " << FigList[i]->GetID() << " (" << FigList[i]->getPoint1().x << "," << FigList[i]->getPoint1().y << ") " << "Side length : " << 90;
				output.close();
				ifstream input("test.txt", ios::in);
				if (input.is_open())
				{
					char* text = new char[100];
					input.getline(text, 100, '\n');
					pOut->PrintMessage(text);
				}
				return FigList[i];
			}
			/*Point c = FigList[i]->getPoint1();
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

			if (totalArea == A1+A2+A3+A4)
			{
				pOut->PrintMessage("Rhombous selected");
				return FigList[i];
			}*/
		}

		else if (dynamic_cast<CEllipse*>(FigList[i]) != NULL)
		{
			if (FigList[i]->IsPointInside(x, y))
			{
				ofstream output;
				output.open("test.txt", ios::out);
				output << "Ellipse ID: " << FigList[i]->GetID() << " (" << FigList[i]->getPoint1().x << "," << FigList[i]->getPoint1().y << ") " << "R1 : " << 75 << " R2 :" << " 50";
				output.close();
				ifstream input("test.txt", ios::in);
				if (input.is_open())
				{
					char* text = new char[100];
					input.getline(text, 100, '\n');
					pOut->PrintMessage(text);
				}
				return FigList[i];
			}
			/*Point c = FigList[i]->getPoint1();
			double ans = (pow((x - c.x), 2) / pow(75, 2))+ (pow((y - c.y), 2) / pow(50, 2));
			if (ans <= 1)
			{
				pOut->PrintMessage("Ellipse selected");
				return FigList[i];
			}*/

		}

		else if (dynamic_cast<CTriangle*>(FigList[i]) != NULL)
		{
			if (FigList[i]->IsPointInside(x,y))
			{
				ofstream output;
				output.open("test.txt", ios::out);
				output << "Triangle ID: " << FigList[i]->GetID() << " (" << FigList[i]->getPoint1().x << "," << FigList[i]->getPoint1().y << ") " << "(" << FigList[i]->getPoint2().x << "," << FigList[i]->getPoint2().y << ")" << "(" << FigList[i]->getPoint3().x << "," << FigList[i]->getPoint3().y << ")" << " Length1 :" << sqrt((pow((FigList[i]->getPoint1().x - FigList[i]->getPoint2().x), 2)) + pow((FigList[i]->getPoint1().y - FigList[i]->getPoint2().y), 2))<<" Length2 :" << sqrt((pow((FigList[i]->getPoint2().x - FigList[i]->getPoint3().x), 2)) + pow((FigList[i]->getPoint2().y - FigList[i]->getPoint3().y), 2))<< " Length3 :" << sqrt((pow((FigList[i]->getPoint1().x - FigList[i]->getPoint3().x), 2)) + pow((FigList[i]->getPoint1().y - FigList[i]->getPoint3().y), 2));
				output.close();
				ifstream input("test.txt", ios::in);
				if (input.is_open())
				{
					char* text = new char[100];
					input.getline(text, 100, '\n');
					pOut->PrintMessage(text);
				}
				return FigList[i];
			}
			/*Point P1, P2, P3;
			P1 = FigList[i]->getPoint1();
			P2 = FigList[i]->getPoint3();
			P3 = FigList[i]->getPoint2();
			Point temp;
			
			if (P1.x < P2.x)
			{
				temp = P2;
				P2 = P1;
				P1 = temp;
			}
			if (P1.x < P3.x)
			{
				temp = P3;
				P3 = P1;
				P1 = temp;
			}
			if (P2.x < P3.x)
			{
				temp = P2;
				P2 = P1;
				P1 = temp;
			}
			double L1,L2,L3,M1,M2,M3;
			L1 = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
			L3= sqrt(pow((P1.x - P3.x), 2) + pow((P1.y - P3.y), 2));
			L2 = sqrt(pow((P2.x - P3.x), 2) + pow((P3.y - P2.y), 2));
			M1 = sqrt(pow((x - P1.x), 2) + pow((y - P1.y), 2));
			M2 = sqrt(pow((x - P2.x), 2) + pow((y - P2.y), 2));
			M3 = sqrt(pow((x - P3.x), 2) + pow((y - P3.y), 2));
			double a1 = Area(x, P2.x, P3.x, y, P2.y, P3.y);
			double a2 = Area(P1.x, x, P3.x, P1.y, y, P3.y);
			double a3 = Area(P1.x, P2.x, x, P1.y, P2.y, y);
			double totalArea = a1 + a2 + a3;
			printf("%f\n", totalArea);
			double sOriginal = (int)(L1 + L2 + L3)/2;
			double OriginalArea = Area(P1.x, P2.x, P3.x, P1.y, P2.y, P3.y);
			printf("%f\n", OriginalArea);
			if (totalArea == OriginalArea)
			{
				pOut->PrintMessage("Triangle Selected");
				return FigList[i];
			}*/
		}
		
	}
		return NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	if (FigList[0] != NULL)
	{
		for (int i = 0; i < FigCount; i++)
			FigList[i]->Draw(pOut);
	}	//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
void ApplicationManager::SetSelectedFigure(CFigure* ptr)
{
	if (SelectedFig != NULL && ptr !=NULL)
	{
		SelectedFig->SetSelected(!(SelectedFig->IsSelected()));
		SelectedFig = (SelectedFig == ptr) ? NULL : ptr;
		if (SelectedFig == ptr)
		{
			SelectedFig->SetSelected(true);
		}
		else
		{
			pOut->PrintMessage(" ");
		}
	}
	else if(ptr !=NULL)
	{
		SelectedFig = ptr;
		SelectedFig->SetSelected(true);
	}
	else if(SelectedFig != NULL && ptr == NULL)
	{
		SelectedFig->SetSelected(false);
		SelectedFig = NULL;
		pOut->PrintMessage(" ");
	}
	else
	{
		pOut->PrintMessage("No Figure Selected!");
	}
}
CFigure* ApplicationManager::GetFigure(int i) {
	return FigList[i];
}

void ApplicationManager::SetCopyFigure(CFigure* modern) {
	Clipboard = modern;
}
void ApplicationManager::SetCutFigure(CFigure* gry) {
	Clipboard = gry;
}
void ApplicationManager::Setdown(CFigure* modern) {
	down = modern;
}
CFigure* ApplicationManager::GetClipboard()const {
	return Clipboard;
}
void ApplicationManager::nullClipboard() {
	Clipboard = NULL;
}
CFigure * ApplicationManager::GetSelecetedFigure() const
{
	return SelectedFig;
}
void ApplicationManager::setcopypaste(int x) {
	copypaste = x;
}
CFigure* ApplicationManager::Getdown() {
	return down;
}
int ApplicationManager::getcopypaste() {
	return copypaste;
}
int ApplicationManager::GetFigCount() {
	return FigCount;
}
void ApplicationManager::DecrementIDafter(int ID)
{
	if (ID >= 1)
	{
		for (int i = ID; i < FigCount; i++)
		{
			FigList[i]->SetID((FigList[i]->GetID()) - 1);
			FigList[i - 1] = FigList[i];
		}
		LastID--;
		FigList[FigCount - 1] = NULL;
		FigCount--;
		SelectedFig = NULL;
	}
	else if (ID == 0)
	{
		FigList[0] = NULL;
		SelectedFig = NULL;
	}
}
int ApplicationManager::GetFiguresCount()
{
	return FigCount;
}

void ApplicationManager::SaveAll(ofstream & out)
{
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i]->Save(out);
	}
}
void ApplicationManager::SetID(int id)
{
	LastID = id;
}
int ApplicationManager::GetID()
{
	return LastID;
}
void ApplicationManager::DeleteAllFigures()
{
	//Heba
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;//Added by Ahmed
	LastID = 0;//Added by Ahmed
}

int ApplicationManager::CountType(string s)
{
	if (s == "rect")
	{
		int count = 0;
		for (int i = 0; i < FigCount; i++)
		{
			CRectangle * pS = dynamic_cast<CRectangle *>(FigList[i]);
			if (pS) // means if NOT NULL
				count++;
		}
		return count;
	}
	else if (s == "line")
	{
		int count = 0;
		for (int i = 0; i < FigCount; i++)
		{
			CLine * pS = dynamic_cast<CLine *>(FigList[i]);
			if (pS) // means if NOT NULL
				count++;
		}
		return count;
	}
	else if (s == "ellipse")
	{
		int count = 0;
		for (int i = 0; i < FigCount; i++)
		{
			CEllipse * pS = dynamic_cast<CEllipse *>(FigList[i]);
			if (pS) // means if NOT NULL
				count++;
		}
		return count;
	}
	else if (s == "triangle")
	{
		int count = 0;
		for (int i = 0; i < FigCount; i++)
		{
			CTriangle * pS = dynamic_cast<CTriangle *>(FigList[i]);
			if (pS) // means if NOT NULL
				count++;
		}
		return count;
	}
	else if (s == "rhombus")
	{
		int count = 0;
		for (int i = 0; i < FigCount; i++)
		{
			CRhombus * pS = dynamic_cast<CRhombus *>(FigList[i]);
			if (pS) // means if NOT NULL
				count++;
		}
		return count;
	}
}

void ApplicationManager::SaveByType(ofstream & out, string s)
{
	if (s == "rect")
	{
		for (int i = 0; i < FigCount; i++)
		{
			CRectangle * pS = dynamic_cast<CRectangle *>(FigList[i]);
			if (pS)
				pS->Save(out);
		}

	}
	else if (s == "line")
	{
		for (int i = 0; i < FigCount; i++)
		{
			CLine * pS = dynamic_cast<CLine *>(FigList[i]);
			if (pS) // means if NOT NULL
				pS->Save(out);
		}

	}
	else if (s == "ellipse")
	{
		for (int i = 0; i < FigCount; i++)
		{
			CEllipse * pS = dynamic_cast<CEllipse *>(FigList[i]);
			if (pS) // means if NOT NULL
				pS->Save(out);
		}

	}
	else if (s == "triangle")
	{
		for (int i = 0; i < FigCount; i++)
		{
			CTriangle * pS = dynamic_cast<CTriangle *>(FigList[i]);
			if (pS) // means if NOT NULL
				pS->Save(out);
		}

	}
	else if (s == "rhombus")
	{
		for (int i = 0; i < FigCount; i++)
		{
			CRhombus * pS = dynamic_cast<CRhombus *>(FigList[i]);
			if (pS) // means if NOT NULL
				pS->Save(out);
		}

	}
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
