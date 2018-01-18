https://drive.google.com/open?id=1alymxy95ZJLq1xgIOMwDo1PmoK_TaOag
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
bool Graph<T>::BFS()
{
   /// Start BFS from starting vertex
   auto start=adjList.begin();
   map<T,bool> visited;
   map<T,int> colors;
   stack<T> myStack;
   /// Push startingVertex into stack
   myStack.push(start->first);
   visited[start->first]=true;
   colors[start->first]=1;
   while(!myStack.empty())
   {
       ///Take 1st element out
       T first=myStack.top();
       myStack.pop();
       /// Visit neighbours of this vertex if not visited already
       for(auto it=adjList[first].begin();it!=adjList[first].end();it++)
       {
           if(!visited[*it])
           {
               visited[*it]=true;
               myStack.push(*it);
               /// Assign opposite color to its children
               colors[*it]=1-colors[first];  /// If 0 then 1 if 1 then 0
           }
           else
           {
               /// Already visited
               if(colors[*it]==colors[first])  /// Same color as adjacent vertex
               {
                   return false;
               }
           }
       }
   }
   return true;
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
        cout<<"Graph is Bipartite"<<endl;
    }
    else
    {
        cout<<"Graph is not Bipartite"<<endl;
    }
}
