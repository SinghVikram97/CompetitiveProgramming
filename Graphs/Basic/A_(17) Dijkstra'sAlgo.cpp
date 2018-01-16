https://drive.google.com/open?id=1HMBFipbuyXl1C0jp5rv8PWPItC9oCCGe
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
      void dijkstra(T sourceNode);
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
        /// it-> first is parent
        /// it->second is a list
        cout<<it->first<<"-->";
        for(auto it1=it->second.begin();it1!=it->second.end();it1++)
        {
            cout<<it1->first<<" ";
        }
        cout<<endl;
    }
}
template<typename T>
void Graph<T>::dijkstra(T sourceNode)
{
    /// Initialize distance of all nodes from source node
    /// Infinity in all except distance b/w source node and itself
    map<T,int> distance;
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        if(it->first!=sourceNode)
        {
            distance[it->first]=INT_MAX;
        }
        else
        {
            distance[it->first]=0;
        }
    }
    /// Take a set of vertices whose distance is not fixed yet
    /// These should be in sorted order as we want to take vertex with least distance
    set<pair<int,T> > notVisited;  /// Sorted according to distance
    /// This set is for choosing minimum distance node and not for storing distance
    /// Push source node into the set
    notVisited.insert(make_pair(0,sourceNode));
    while(!notVisited.empty())
    {
        /// This is the least distance node
        auto p=*(notVisited.begin());               /// Very imp infinite loop if we use auto p=notVisited.begin()
        /// Fix it's distance
        distance[p.second]=p.first;     /// p is pair
        notVisited.erase(make_pair(p.first,p.second));
        /// Update distance of it's neighbours
        for(auto it=adjList[p.second].begin();it!=adjList[p.second].end();it++)
        {
            if(distance[p.second]+it->second<distance[it->first])
            {
                /// Update the distance
                /// We can't update in set so 1st erase and then put in set
                /// Handle condition if this is 1st time node is entered into the set
                auto mila=notVisited.find(make_pair(distance[it->first],it->first));
                /// IMP STEP pair with distance as previously stored distance
                if(mila!=notVisited.end())
                {
                    notVisited.erase(make_pair(distance[it->first],it->first));
                }
                distance[it->first]=distance[p.second]+it->second;  /// Update the distance(IMP)
                notVisited.insert(make_pair(distance[it->first],it->first));
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
    g.dijkstra(sourceNode);
}
