#include "nodes.h"

Node::Node(char id)
{
	iD = id;
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}

void Node::SetN(Node *n)
{
	north = n;
}

Node* Node::GetN()
{
	return this->north;
}	

void Node::SetE(Node *e)
{
	east = e;
}

Node* Node::GetE()
{
	return this->east;
}

void Node::SetS(Node *s)
{
	south = s;
}

Node* Node::GetS()
{
	return this->south;
}

void Node::SetW(Node *w)
{
	west = w;
}

Node* Node::GetW()
{
	return this->west;
}

char Node::GetNodeID()
{
	return this->iD;
}

string Node::GetMessage()
{
	return "You are sorounded by darkness yet you can just make out which ways to travel";
}

int Node::SoulsNeeded()
{
	return 0;
}

void Node::SetSecret(Node* n)
{
	
}

Node* Node::GetSecret()
{
	return NULL;
}

int Node::GetSouls()
{
	return 0;
}

void Node::RemoveSouls()
{

}

EndNode::EndNode(char id, int s) : Node(id)
{
	totalSouls = s;
}

char EndNode::GetNodeID()
{
	return this->iD;
}

string EndNode::GetMessage()
{
	return "You've found a bright light";
}
int EndNode::SoulsNeeded()
{
	return this->totalSouls;
}

SecretNode::SecretNode(char id) : Node (id)
{
	
}

void SecretNode::SetSecret(Node* n)
{
	secret = n;
}

Node* SecretNode::GetSecret()
{
	return this->secret;
}

string SecretNode::GetMessage()
{
	return "There's something hidden here";
}

char SecretNode::GetNodeID()
{
	return this->iD;
}

SoulNode::SoulNode(char id, int s) : Node (id)
{
	souls = s;
}

int SoulNode::GetSouls()
{
	return souls;
}

void SoulNode::RemoveSouls()
{
	this->souls -= this->souls;
}

char SoulNode::GetNodeID()
{
	return this->iD;
}

string SoulNode::GetMessage()
{
	if(this->GetSouls() > 0)
		return "There is a strange energy around you";
	else
		return "The energy you felt has been absorbed";
}