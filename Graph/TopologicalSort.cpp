// C++ program to perform topological sorting...
#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
	int V;
	list<int> *adj;

	void topologicalSortUtil(int v,bool visited[],stack<int> &stack);
    public:
    	Graph(int V);
    	void addEdge(int v,int w);
    	void topologicalSort();
};
Graph::Graph(int V){
	this->V = V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v,bool visited[],stack<int> &stack){
	visited[v]=true;
	list<int> :: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
		if(!visited[*i])
			topologicalSortUtil(*i,visited,stack);
	stack.push(v);
}

void Graph :: topologicalSort(){
	stack<int> stack;
	bool *visited =new bool[V];
	for(int i=0;i<V;++i)
		if(visited[i]==false)
			topologicalSortUtil(i,visited,stack);
	while(stack.empty()==false){
		cout << stack.top() << " ";
		stack.pop();
	}

}

int main()
{
	Graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.topologicalSort();
	return 0;

}