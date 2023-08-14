#include<iostream>
#include <list>
using namespace std;
class Graph
{
	int E; 
	list<int> *adjac;
public:
	Graph(int E);
	void Edge(int v, int w); 
	bool Reachable(int s, int d);
};
Graph::Graph(int E)
{
	this->E = E;
	adjac = new list<int>[E];
}
void Graph::Edge(int v, int w)
{
	adjac[v].push_back(w); 
}
bool Graph::Reachable(int s, int d)
{
	if (s == d)
	return true;
	bool *vst = new bool[E];
	for (int i = 0; i < E; i++)
		vst[i] = false;
	list<int> que;
	vst[s] = true;
	que.push_back(s);
	list<int>::iterator ind;
	while (!que.empty())
	{
		s = que.front();
		que.pop_front();
		for (ind = adjac[s].begin(); ind != adjac[s].end(); ++ind)
		{
			if (*ind == d)
				return true;
			if (!vst[*ind])
			{
				vst[*ind] = true;
				que.push_back(*ind);
			}
		}
	}
	return false;
}
int main()
{
	Graph grap(4);
	grap.Edge(0, 2);
	grap.Edge(0, 1);
	grap.Edge(2, 0);
	grap.Edge(1, 2);
	grap.Edge(2, 3);
	grap.Edge(3, 3);
	int u_new = 2, v_new = 3;
	if(grap.Reachable(u_new, v_new))
		cout<< "A path exists from " << u_new << " to " << v_new;
	else
		cout<< "\n No path exists from " << u_new << " to " << v_new;
	u_new = 3, v_new = 1;
	if(grap.Reachable(u_new, v_new))
		cout<< "\n A path exists from " << u_new << " to " << v_new;
	else
		cout<< "\n No path exists from " << u_new << " to " << v_new;
	return 0;
}
