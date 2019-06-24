#include "mazes.h"

Maze::Maze(int i)
{
	id = i;
}

int Maze::GetID()
{
	return id;
}

Node* Maze::GetStartNode()
{
	return startNode;
}

Node* Maze::GetEndNode()
{
	return endNode;
}

Maze1::Maze1(int i) : Maze(i)
{
	
}

int Maze1::GetID()
{
	return id;
}

void Maze1::ConstructNodes()
{
	Node* a = new Node('A');
	Node* b = new Node('B');
	Node* c = new Node('C');
	Node* d = new Node('D');
	Node* e = new Node('E');
	Node* f = new Node('F');
	Node* g = new Node('G');
	Node* h = new Node('H');
	Node* i = new Node('I');
	Node* j = new Node('J');
	Node* k = new Node('K');
	Node* l = new EndNode('L', 0);

	a->SetE(b);
	a->SetS(e);
	b->SetS(f);
	b->SetW(a);
	c->SetE(d);
	c->SetS(g);
	d->SetW(c);
	e->SetN(a);
	e->SetS(i);
	f->SetN(b);
	f->SetE(g);
	g->SetN(c);
	g->SetE(h);
	g->SetS(k);
	g->SetW(f);
	h->SetS(l);
	h->SetW(g);
	i->SetN(e);
	i->SetE(j);
	j->SetW(i);
	k->SetN(g);
	l->SetN(h);

	startNode = a;
	endNode = l;
}

Maze2::Maze2(int i) : Maze(i)
{
	
}

int Maze2::GetID()
{
	return id;
}

void Maze2::ConstructNodes()
{
	ifstream maze;
	string fileName;
	cout << "Input file and its location. Example: c:\\Users\\Name\\Desktop\\MazeName.txt" << endl;
	cin >> fileName;
	maze.open(fileName);
	if(!maze.is_open())
	{
		cout << "Failed to find file, Restart application" << endl;
		system("PAUSE");
		exit(0);
	}
	Node *array[21];

	char nodeID;
	char north;
	char east;
	char south;
	char west;
	char secret;
	int souls;
	int totalSouls;
	int count = 0;

	while(maze.good())
	{
		maze >> nodeID >> north >> east >> south >> west >> secret >> souls >> totalSouls;
		if(secret != '*')
		{
			array[count] = new SecretNode(nodeID);
		}
		else if(souls > 0)
		{
			array[count] = new SoulNode(nodeID, souls);
		}

		else if(totalSouls > 0)
		{
			array[count] = new EndNode(nodeID, totalSouls);
			endNode = array[count];
		}
		else
		{
			array[count] = new Node(nodeID);
		}
		if(nodeID == 'A')
			startNode = array[count];
		count++;
	}
	maze.clear();
	maze.seekg(0, maze.beg);
	while (maze.good())
	{
		maze >> nodeID >> north >> east >> south >> west >> secret >> souls >> totalSouls;
		for (int j = 0; j < 20; j++)
		{
			if(array[j]->GetNodeID() == nodeID)
			{
				for (int k = 0; k < 20; k++)
				{
					if(array[k]->GetNodeID() == north)
						array[j]->SetN(array[k]);
					else if(array[k]->GetNodeID() == east)
						array[j]->SetE(array[k]);
					else if(array[k]->GetNodeID() == south)
						array[j]->SetS(array[k]);
					else if(array[k]->GetNodeID() == west)
						array[j]->SetW(array[k]);
					else if(array[k]->GetNodeID() == secret)
						array[j]->SetSecret(array[k]);
				}
				break;
			}
		}
	}
	maze.close();
}

Maze3::Maze3(int i) : Maze(i)
{
	
}

int Maze3::GetID()
{
	return id;
}

void Maze3::ConstructNodes()
{
	Node* a = new Node('A');
	Node* b = new SoulNode('B', 1);
	Node* c = new Node('C');
	Node* d = new Node('D');
	Node* e = new SecretNode('E');
	Node* f = new SoulNode('F', 1);
	Node* g = new Node('G');
	Node* h = new Node('H');
	Node* i = new Node('I');
	Node* j = new Node('J');
	Node* k = new Node('K');
	Node* l = new Node('L');
	Node* m = new SecretNode('M');
	Node* n = new Node('N');
	Node* o = new SoulNode('O', 1);
	Node* p = new Node('P');
	Node* q = new EndNode('Q', 5);
	Node* r = new Node('R');
	Node* s = new Node('S');
	Node* t = new Node('T');
	Node* u = new Node('U');
	Node* v = new Node('V');
	Node* w = new Node('W');
	Node* x = new SoulNode('X', 1);
	Node* y = new SoulNode('Y', 1);
	Node* z = new SecretNode('Z');
	a->SetE(b);
	b->SetE(c);
	b->SetS(i);
	b->SetW(a);
	c->SetE(d);
	c->SetW(b);
	d->SetE(e);
	d->SetS(j);
	d->SetW(c);
	e->SetE(f);
	e->SetW(d);
	e->SetSecret(o);
	f->SetE(g);
	f->SetS(k);
	f->SetW(e);
	g->SetE(h);
	g->SetW(f);
	h->SetS(r);
	h->SetW(g);
	i->SetN(b);
	i->SetE(m);
	j->SetN(d);
	j->SetE(k);
	j->SetS(l);
	k->SetN(f);
	k->SetE(q);
	k->SetW(j);
	l->SetN(j);
	l->SetS(n);
	l->SetW(m);
	m->SetE(l);
	m->SetS(n);
	m->SetW(i);
	m->SetSecret(h);
	n->SetN(m);
	n->SetE(o);
	o->SetW(n);
	p->SetE(q);
	q->SetN(k);
	q->SetW(p);
	r->SetN(h);
	r->SetS(s);
	s->SetN(r);
	s->SetW(t);
	t->SetE(s);
	t->SetS(u);
	u->SetN(t);
	u->SetE(v);
	v->SetE(w);
	v->SetW(u);
	w->SetE(x);
	w->SetS(z);
	w->SetW(v);
	x->SetS(y);
	x->SetW(w);
	y->SetN(x);
	y->SetW(z);
	z->SetN(w);
	z->SetE(y);
	z->SetSecret(a);

	startNode = a;
	endNode = x;
}

