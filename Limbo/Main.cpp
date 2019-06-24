#include "nodes.h"
#include "methods.h"
#include "mazes.h"

using namespace std;

int main()
{
	Maze* maze1 = new Maze1(1);
	Maze* maze2 = new Maze2(2);
	Maze* maze3 = new Maze3(3);
	Maze* currentMaze = NULL;
	Node* currentNode = NULL;
	int steps = 0;
	int souls = 0;
	bool playing = true;
	bool menu = true;
	bool playerInfo = false;
	bool complete = false;

	int menuOption;
	while (playing)
	{
		if(menu)
		{
			CenterText("===========================================================");
			CenterText("Limbo!");
			CenterText("Escape from the nightmare that is Limbo");
			CenterText("===========================================================");
			cout << endl;
			CenterText("Easy - 1");
			CenterText("Normal - 2");
			CenterText("Hard - 3");
			CenterText("Quit - 4");
			cin >> menuOption;
			switch (menuOption)
			{
				case 1: 
					currentMaze = maze1;
					maze1->ConstructNodes();
					currentNode = currentMaze->GetStartNode();
					playing = true;
					menu = false;
					system("CLS");
					break;
				case 2: 
					currentMaze = maze2;
					currentMaze->ConstructNodes();
					currentNode = currentMaze->GetStartNode();
					playing = true;
					menu = false;
					system("CLS");
					break;
				case 3: 
					currentMaze = maze3;
					currentMaze->ConstructNodes();
					currentNode = currentMaze->GetStartNode();
					playing = true;
					menu = false;
					system("CLS");
					break;
				case 4: 
					exit(0);
				default: 
					system("CLS");
					CenterText("Please enter an option (Numerical value)");
					cout << endl;
					break;
			}
		}

		if(!playerInfo)
		{
			cout << endl;
			CenterText(currentNode->GetMessage());
			CenterText("Your options are to move:");
			cout << endl;
			if(currentNode->GetN() != NULL)
				CenterText("North - 1");
			if(currentNode->GetE() != NULL)
				CenterText("East - 2");
			if(currentNode->GetS() != NULL)
				CenterText("South - 3");
			if(currentNode->GetW() != NULL)
				CenterText("West - 4");
			if(currentNode->GetSecret() != NULL)
				CenterText("??? - 5");
			CenterText("Search Area - 6");
			if(currentNode == currentMaze->GetEndNode())
			{
				CenterText("Escape! - 7");
			}
			CenterText("Player Info - 8");
			CenterText("Quit Game - 9");
			cin >> menuOption;
			switch (menuOption)
			{
				case 1:
					if(currentNode->GetN() == NULL)
					{
						system("CLS");
						CenterText("North is not an option");
					}
					else
					{
						steps += 1;
						currentNode = currentNode->GetN();
						system("CLS");
					}
					break;
				case 2: 
					if(currentNode->GetE() == NULL)
					{
						system("CLS");
						CenterText("East is not an option");
					}
					else
					{
						steps += 1;
						currentNode = currentNode->GetE();
						system("CLS");
					}
					break;
				case 3: 
					if(currentNode->GetS() == NULL)
					{
						system("CLS");
						CenterText("South is not an option");
					}
					else
					{
						steps += 1;
						currentNode = currentNode->GetS();
						system("CLS");
					}
					break;
				case 4: 
					if(currentNode->GetW() == NULL)
					{
						system("CLS");
						CenterText("West is not an option");
					}
					else
					{
						steps += 1;
						currentNode = currentNode->GetW();
						system("CLS");
					}
					break;
				case 5:
					if(currentNode->GetSecret() == NULL)
					{
						system("CLS");
						CenterText("??? is not an option");
					}
					else
					{
						steps += 1;
						currentNode = currentNode->GetSecret();
						system("CLS");
					}
					break;
				case 6: 
					system("CLS");
					if(currentNode->GetSouls() > 0)
					{
						CenterText("You found a soul fragment");
						souls += currentNode->GetSouls();
						currentNode->RemoveSouls();
					}
					else
						CenterText("Nothing Was Found");
					break;
				case 7: 
					if(currentNode == currentMaze->GetEndNode() && souls >= currentNode->SoulsNeeded())
					{
						complete = true;
						system("CLS");
						break;
					}

					else
					{
						system("CLS");
						CenterText("More souls are needed before you can escape");
						break;
					}
				case 8: 
					system("CLS");
					playerInfo = true;
					break;
				case 9: 
					exit(0);
				default: 
					system("CLS");
					CenterText("Please enter an option (Numerical value)");
					break;
			}
		}

		if(playerInfo)
		{
			CenterText("===========================================================");
			CenterText("Soul Fragments Found:" + IntToString(souls));
			CenterText("===========================================================");
			CenterText("Back To Game - 1");
			cin >> menuOption;
			switch (menuOption)
			{
				case 1: 
					playerInfo = false;
					system("CLS");
					break;
				default: 
					system("CLS");
					CenterText("Please enter an option (Numerical value)");
					break;
			}
		}

		if(complete)
		{
			CenterText("You have escaped limbo, Congrats!");
			CenterText("Steps Taken:" + IntToString(steps));
			cout << endl;
			CenterText("Play Again? - 1");
			CenterText("Quit - 2");
			cin >> menuOption;
			switch (menuOption)
			{
				case 1:
					complete = false;
					menu = true;
					system("CLS");
					break;
				case 2:
					exit(0);
				default:
					CenterText("Please enter an option (Numerical value)");
					system("CLS");
					break;
			}
		}
	}
	return 0;
}