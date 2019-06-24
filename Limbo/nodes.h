#ifndef NODES_H
#define NODES_H

#include <cstring>
#include <iostream>

using namespace std;

class Node
{
protected:
	char iD; //Unique ID for this node
	Node* north; //Direction to next node
	Node* east;
	Node* south;
	Node* west;
	string message; //Message this node will display
public:
	Node(char id);
	void SetN(Node* n);
	Node* GetN();
	void SetE(Node* e);
	Node* GetE();
	void SetS(Node* s);
	Node* GetS();
	void SetW(Node* w);
	Node* GetW();
    virtual char GetNodeID(); 
	virtual string GetMessage();
	virtual int SoulsNeeded();
	virtual Node* GetSecret();
	virtual void SetSecret(Node* n);
	virtual int GetSouls();
	virtual void RemoveSouls();
};

class EndNode : public Node //Derived class from Node
{
private:
	int totalSouls;
public:
	EndNode(char id, int s);
	char GetNodeID();
	string GetMessage();
	int SoulsNeeded();
};

class SecretNode : public Node
{
private:
	Node* secret;
public:
	SecretNode(char id);
	string GetMessage();
	Node* GetSecret();
	void SetSecret(Node* n);
	char GetNodeID();
};

class SoulNode : public Node
{
private:
	int souls;
public:
	SoulNode(char id, int s);
	string GetMessage();
	int GetSouls();
	void RemoveSouls();
	char GetNodeID();
};
#endif


