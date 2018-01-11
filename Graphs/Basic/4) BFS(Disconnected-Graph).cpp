/// https://drive.google.com/open?id=12a9cA_KGAnfIak8-xA139ou55qxoKgG-
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

 private:
    int number_of_vertices;
    map<T,list<T> > adjList;
 public:
    Graph(int no_of_vertices);
    void addEdge(T V1,T V2);
    void printAdjList();
    void BFS_Program(T startingVertex,map<T,bool> &visited);
    void BFS();
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T V1,T V2)
{
    adjList[V1].push_back(V2);
    adjList[V2].push_back(V1);
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
void Graph<T>::BFS_Program(T startingVertex,map<T,bool> &visited)  /// Passing by reference
{
   /// Create a queue of type T
   queue<T> myQueue;
   /// Push starting vertex into queue
   myQueue.push(startingVertex);
   visited[startingVertex]=true;
   while(!myQueue.empty())
   {
       /// Take front element from queue and print int
       T frontElement=myQueue.front();
       myQueue.pop();
       cout<<frontElement<<" ";
       /// Push children of front element in the queue
       for(auto it=adjList[frontElement].begin();it!=adjList[frontElement].end();it++)
       {

               /// If not visited add to queue
               if(!visited[(*it)])
               {
                   myQueue.push((*it));
                   visited[(*it)]=true;
               }

       }
   }
}
template<typename T>
void Graph<T>::BFS()
{
    /// Start from every vertex which is not visited
    /// map by default initialized by false(0)
    /// Can't take array as values not integers
    /// Can't pass by value as we want to update it in BFS_Program
     map<T,bool> visited;
     for(auto it=adjList.begin();it!=adjList.end();it++)
     {
         /// 1st element of map is vertex and 2nd is connected vertices to it
         /// Call BFS if current vertex not visited yet
         if(!visited[it->first])
         BFS_Program((it->first),visited);
     }
}
int main()
{
    int no_of_vertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>no_of_vertices;
    Graph<int> g(no_of_vertices);
    cout<<"Enter the number of edges"<<endl;
    int no_of_edges;
    cin>>no_of_edges;
    for(int i=0;i<no_of_edges;i++)
    {
        cout<<"Enter vertex1 and vertex2"<<endl;
        int v1,v2;
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
    cout<<endl;
    g.printAdjList();
    cout<<endl;
    g.BFS();
}
