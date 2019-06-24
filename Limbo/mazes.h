#ifndef MAZES_H
#define MAZES_H

#include "nodes.h"
#include "methods.h"
#include <fstream>
#include <cstring>

class Maze
{
protected:
	Node* startNode;
	Node* endNode;
	int id;
public:
	Maze(int i);
	virtual int GetID();
	virtual void ConstructNodes() = 0;
	Node* GetStartNode();
	Node* GetEndNode();
};

class Maze1 : public Maze
{
public:
	Maze1(int i);
	int GetID();
	void ConstructNodes();
};

class Maze2 : public Maze
{
public:
	Maze2(int i);
	int GetID();
	void ConstructNodes();
};

class Maze3 : public Maze
{
public:
	Maze3(int i);
	int GetID();
	void ConstructNodes();
};

#endif