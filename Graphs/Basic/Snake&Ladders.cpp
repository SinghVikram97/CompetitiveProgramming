/// https://drive.google.com/open?id=1IpVFv4Uq9SpR-V-AZcoqmth5XIhz7OU1
/// https://drive.google.com/open?id=1c2dwySNppZhTRFnrMA01iUd7Y87orNow
#include<bits/stdc++.h>
using namespace std;
int board[50]={0};
template<typename T>
class Graph{

 private:
    int number_of_vertices;
    map<T,list<T> > adjList;
 public:
    Graph(int no_of_vertices);
    void addEdge(T V1,T V2);
    void printAdjList();
    int BFS(T startingVertex);
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T V1,T V2)
{
   /// Edge from v1 to v2
   adjList[V1].push_back(V2);
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
int Graph<T>::BFS(T startingVertex)
{
    /// Start from every vertex which is not visited
    /// map by default initialized by false(0)
    /// Can't take array as values not integers
    /// Can't pass by value as we want to update it in BFS_Program
    map<T,int> visited;
    /// Intialize distance with -1 initially
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
         visited[it->first]=-1;
    }
   /// Create a queue of type T
   queue<T> myQueue;
   /// Push starting vertex into queue
   myQueue.push(startingVertex);
   visited[startingVertex]=0;
   while(!myQueue.empty())
   {
       /// Take front element from queue and print int
       T frontElement=myQueue.front();
       myQueue.pop();
       /// Push children of front element in the queue
       for(auto it=adjList[frontElement].begin();it!=adjList[frontElement].end();it++)
       {
        /// If not visited add to queue
          if(visited[(*it)]==-1)   /// Distance not calculated yet
          {
             myQueue.push((*it));
             visited[(*it)]=visited[frontElement]+1;
          }
       }
   }
//   for(auto it=visited.begin();it!=visited.end();it++)
//   {
//       cout<<"Distance of "<<(it->first)<<" from "<<startingVertex<<" is "<<(it->second)<<endl;
//   }
      return visited[36];
}
int main()
{
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    Graph<int> g(37);  /// 37 nodes starting from 0
    for(int i=0;i<=36;i++)
    {
      for(int j=1;j<=6;j++)
      {
          //cout<<i<<" "<<j<<endl;
          g.addEdge(i,i+j+board[i+j]);
      }
    }
    cout<<g.BFS(0);
}
