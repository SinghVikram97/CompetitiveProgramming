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
    bool BFS_Program(T startingVertex,map<T,bool> &visited,map<T,T> &parent);
    bool BFS();
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
bool Graph<T>::BFS_Program(T startingVertex,map<T,bool> &visited,map<T,T> &parent)  /// Passing by reference
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
       /// Push children of front element in the queue
       for(auto it=adjList[frontElement].begin();it!=adjList[frontElement].end();it++)
       {
              /// If not visited add to queue
               if(!visited[(*it)])
               {
                   myQueue.push((*it));
                   visited[(*it)]=true;
                   parent[*it]=frontElement;
               }
               else
               {
                   /// Given node is already visited
                   /// If current_node not visited by its neighbour
                   if(parent[frontElement]!=*it)
                   {
                       return true;
                   }
               }

       }
   }
   return false;
}
template<typename T>
bool Graph<T>::BFS()
{
     map<T,T> parent;
     map<T,bool> visited;
     for(auto it=adjList.begin();it!=adjList.end();it++)
     {
         if(!visited[it->first])
         {
            if(BFS_Program((it->first),visited,parent))
               {
                   return true;
               }
         }
     }
     return false;
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
    if(g.BFS())
    {
        cout<<"Cycle";
    }
    else
    {
        cout<<"Not Cycle";
    }
}
