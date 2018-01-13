#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

  private:
      int number_of_vertices;
      map<T,list<T>> adjList;
  public:
      Graph(int no_of_vertices);
      void addEdge(T v1,T v2);
      void printAdjList();
      void DFS(T starting_vertex);
      void DFS_Helper(T starting_vertex,map<T,bool> &visited);
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2)
{
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}
template<typename T>
void Graph<T>::printAdjList()
{
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        cout<<it->first<<"-->";
        for(auto it1=it->second.begin();it1!=it->second.end();it1++)
        {
            cout<<(*it1)<<" ";
        }
        cout<<endl;
    }
}
template<typename T>
void Graph<T>::DFS_Helper(T starting_vertex,map<T,bool> &visited)
{
    visited[starting_vertex]=true;
    cout<<starting_vertex<<" ";
    /// Traverse in adjList of this vertex and push its children in stack
    for(auto it=adjList[starting_vertex].begin();it!=adjList[starting_vertex].end();it++)
    {
        if(!visited[(*it)])
        {
          visited[(*it)]=true;
          DFS_Helper((*it),visited);
        }
    }
}
template<typename T>
void Graph<T>::DFS(T starting_vertex)
{
    map<T,bool> visited;
    DFS_Helper(starting_vertex,visited);
}
int main()
{
    int number_of_vertices;
    cout<<"Enter the no of vertices"<<endl;
    cin>>number_of_vertices;
    Graph<int> g(number_of_vertices);
    int number_of_edges;
    cout<<"Enter the no of edges"<<endl;
    cin>>number_of_edges;
    for(int i=0;i<number_of_edges;i++)
    {
        cout<<"Enter v1 and v2"<<endl;
        int vertex1,vertex2;
        cin>>vertex1>>vertex2;
        g.addEdge(vertex1,vertex2);
    }
    cout<<endl;
    g.printAdjList();
    cout<<endl;
    cout<<"Enter starting vertex"<<endl;
    int starting_vertex;
    cin>>starting_vertex;
    cout<<endl;
    g.DFS(starting_vertex);
}
