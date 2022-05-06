 //Harsh Bamotra AC-1216
//Program to implement BST

#include <iostream>
#include <list>
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
	void BFS(int source);
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
	cout<< endl <<"Enter number of edges present in the graph ::";
	cin >> edges;

	int v , u;

	for(int i=0 ; i<edges ; i++)
		{
			cout << "Enter vertices of edge " << i+1 << " ::";
			cin >> v >> u;
			addEdge(v,u);
		}
    }

template <class T>
void Graph<T> :: BFS(int s)
    {
	bool *visited = new bool[V];
    	for(int i = 0; i < V; i++)
        	visited[i] = false;

	list<T> queue;
    	visited[s] = true;
    	queue.push_back(s);

	list<int>::iterator i;
    
    	cout<< endl << "BFS Traversal ::";
	
    	while(!queue.empty())
    		{
        		s = queue.front();
        		cout << endl  << "Parent ::" << s << " ";
        		queue.pop_front();

 			cout << "Child ::";
        		for(i = ls[s].begin() ; i != ls[s].end() ; ++i)
        			{
            				if(!visited[*i])
						{	
							cout << *i << " , ";
                					visited[*i] = true;
                					queue.push_back(*i);
            					}
        			}
    		}
    	cout << endl;
    }

int main()
    {
	Graph<int> g;
	int src;	

	g.inputEdges();
	
	cout << endl << "Enter source vertex ::";
	cin >> src; 

	g.BFS(src); 
	return 0;
    }
