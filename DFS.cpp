 //Harsh Bamotra AC-1216
//Program to implement DFS

#include <iostream>
#include <list>
#include <stack>
using namespace std;

template <class T>
class Graph
    {   
	private:
	int V;
        list<T> *ls;

        public:
	Graph();
        void addEdge(int v,int u);
	void inputEdges();
	void DFS(int source);
};

template <class T>
Graph<T> :: Graph()
    {
   	cout << "Enter number of vertices ::";
   	cin >> V;
   	ls = new list<T>[V];
    }

template <class T>
void Graph<T> :: addEdge(int v,int u)
    {
	    ls[v].push_back(u);
    }

template <class T>
void Graph<T> :: inputEdges()
    {
	int edges;	
	cout << endl << "Enter number of edges present in the graph ::";
	cin >> edges;

	int v,u;

	for(int i=0 ; i<edges ; i++)
		{
			cout << "Enter vertices of edge " << i+1 << " ::";
			cin >> v >> u;
			addEdge(v,u);
		}
    }

template <class T>
void Graph<T> :: DFS(int s)
    {
    	stack<T> stk;
    
   	bool *Explored = new bool[V];
    	for(int i = 0 ; i < V ; i++)
        	Explored[i] = false;

    	list<int>::iterator i;

    	stk.push(s);
    
    	while (stk.empty() !=1)
		{
       			T node = stk.top();       
       			stk.pop();
       			if(Explored[node] == false)
				{
           				Explored[node] = true;
           				cout << endl << "Parent ::" << node;
           				cout << endl << "Child ::";
           
           				for(i = ls[node].begin() ; i != ls[node].end() ; ++i)
           					{
               						if(!Explored[*i])
                    						cout << *i << " , ";
                					stk.push(*i);
           					}
           				cout << endl;
        			}
    		}
    }

int main()
    {
	Graph<int> g;
	int src;	

	g.inputEdges();
	
	cout << endl << "Enter source vertex ::";
	cin >> src; 

	g.DFS(src); 

	return 0;
}
