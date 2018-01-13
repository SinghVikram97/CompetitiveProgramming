https://drive.google.com/open?id=1oTsnU4cRPRo3TgFDS6V_uBscZH6KUosB
https://drive.google.com/open?id=1oTsnU4cRPRo3TgFDS6V_uBscZH6KUosB
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
      void DFS();
      void DFS_helper(T starting_vertex,map<T,bool> &visited,list<T> &topological_list);
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2)
{
    adjList[v1].push_back(v2);  /// Directed Graph
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
void Graph<T>::DFS_helper(T starting_vertex,map<T,bool> &visited,list<T> &topological_list)
{
   /// Visit this vertex and mark as visited
   visited[starting_vertex]=true;
   /// Visit all its children if not visited already
   for(auto it=adjList[starting_vertex].begin();it!=adjList[starting_vertex].end();it++)
   {
       if(!visited[(*it)])
       {
           DFS_helper((*it),visited,topological_list);
       }
   }
   /// Sare visit hogye ab aage nhi ja skte
   /// So push it at front of the list
   topological_list.push_front(starting_vertex);
}
template<typename T>
void Graph<T>::DFS()
{
    map<T,bool> visited;
    list<T> topological_list;
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        /// it->first is a vertex
        /// If not visited please visit
        if(!visited[(it->first)])
        {
            DFS_helper(it->first,visited,topological_list);
        }
    }
    /// Print the list
    for(auto it=topological_list.begin();it!=topological_list.end();it++)
    {
        cout<<(*it)<<"-->";
    }
    return;
}
int main()
{
    int number_of_vertices;
    cout<<"Enter the no of vertices"<<endl;
    cin>>number_of_vertices;
    Graph<string> g(number_of_vertices);
    int number_of_edges;
    cout<<"Enter the no of edges"<<endl;
    cin>>number_of_edges;
    for(int i=0;i<number_of_edges;i++)
    {
        cout<<"Enter v1 and v2"<<endl;
        string vertex1,vertex2;
        cin>>vertex1>>vertex2;
        g.addEdge(vertex1,vertex2);
    }
    cout<<endl;
    g.DFS();
}
