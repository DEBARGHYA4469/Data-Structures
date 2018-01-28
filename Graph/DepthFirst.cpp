// Write a c++ code for DFS traversal from a given vertex directed graph

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Graph{
	int V; // no of vertices
	list<int> *adj; // pointer to an array containing adjacency list
	void DFSUtil(int v,bool visited[]); // edge and visit record
    public:  // publicly available routines
    	Graph(int V); // constructor
    	void addEdge(int v,int w); // add a directed edge
    	void DFS(int v);//Depth First Search
};	

Graph :: Graph(int V){
	this->V=V; // mark the no of vertex of a given graph object
	adj = new list<int>[V];//dynamic allocation of V-slot array
}

void Graph::addEdge(int v,int w){ // add w to v's adjacency list
	adj[v].push_back(w);
}

void Graph :: DFSUtil(int v,bool visited[]){
	visited[v] = true;
	cout << v << " ";
	list<int> :: iterator i;//Recur through all vertex adjacent to a vertex
	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i])
			DFSUtil(*i,visited);	
}

void Graph::DFS(int v){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			DFSUtil(i,visited);
}

int main(){
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,3);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	cout << "Depth First traversal of the Graph" << endl;
	g.DFS(0);
	return 0;
}