// Write a program to check if there exits a  path between two nodes in a graph(connected) using BFS.
#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;// no of vertices
	list<int> *adj;	
	public:
		Graph(int V); // Constructor
		void addEdge(int v,int w);
		bool isReachable(int s,int d);
};
Graph ::Graph(int V){
	this->V=V;
	adj =new list<int>[V]; //list of adjacent
}
void Graph :: addEdge(int v,int w){
	adj[v].push_back(w);
}

bool Graph :: isReachable(int s,int d){
	if(s==d)
		return true;
	bool *visited=new bool[V];
	for(int i=0;i < V;i++)
		visited[i]=false;
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	  // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then 
            // return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
     
    // If BFS is complete without visiting d
    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}

