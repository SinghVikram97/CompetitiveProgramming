https://drive.google.com/open?id=1MS7h_UtmaU5cw4EhSZ74mT4TYscqmcbO
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

  private:
      int number_of_vertices;
      map<T,list<pair<T,int> > >adjList;
  public:
      Graph(int no_of_vertices);
      void addEdge(T v1,T v2,int distance,bool bidirectional);
      void printAdjList();
      void bellmanFord(T sourceNode);
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2,int distance,bool bidirectional)
{
    adjList[v1].push_back(make_pair(v2,distance));
    if(bidirectional)
        adjList[v2].push_back(make_pair(v1,distance));
}
template<typename T>
void Graph<T>::printAdjList()
{
   for(auto it=adjList.begin();it!=adjList.end();it++)
   {
       cout<<it->first<<"-->";
       for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++)
       {
           cout<<(*it1).first<<" ";
       }
       cout<<endl;
   }
}
template<typename T>
void Graph<T>::bellmanFord(T sourceNode)
{
    /// Distance array
    map<T,long long int> distance;
    /// Initialize it to INT_MAX
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        distance[it->first]=INT_MAX;
    }
    distance[sourceNode]=0;
    /// We need to do V-1 iterations
    for(int i=0;i<number_of_vertices-1;i++)
    {
        /// Relax every edge(u,v)
        /// Traverse the adjacency list for edges
        for(auto it=adjList.begin();it!=adjList.end();it++)
        {
            for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++)
            {
                /// Edge from it->first to (*it1).first of weight (*it1).second
                if(distance[it->first]+(*it1).second<distance[(*it1).first])
                {
                    distance[(*it1).first]=distance[it->first]+(*it1).second;
                }
            }
        }
    }
    for(auto it=distance.begin();it!=distance.end();it++)
    {
        cout<<"Distance of "<<it->first<<" from "<<sourceNode<<" is "<<it->second<<endl;
    }
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
        cout<<"Enter distance between them"<<endl;
        int distance;
        cin>>distance;
        cout<<"Is it bidirectional"<<endl;
        bool bidirectional;
        cin>>bidirectional;
        g.addEdge(vertex1,vertex2,distance,bidirectional);
    }
    cout<<endl;
    g.printAdjList();
    cout<<endl;
    cout<<"Enter the source node";
    int sourceNode;
    cin>>sourceNode;
    g.bellmanFord(sourceNode);
}
