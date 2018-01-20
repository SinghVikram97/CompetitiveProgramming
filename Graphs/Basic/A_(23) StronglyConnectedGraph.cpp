https://drive.google.com/open?id=1su6uREqMWXUGysu5sxhuqr3_MCRgHN0I

1) Initialize all vertices as not visited.

2) Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.

3) Reverse all arcs (or find transpose or reverse of graph)

4) Mark all vertices as not-visited in reversed graph.

5) Do a DFS traversal of reversed graph starting from SAME VERTEX V (Same as step 2). If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

 private:
    int number_of_vertices;
    map<T,list<T> > adjList;
    map<T,list<T> > reverseList;
 public:
    Graph(int no_of_vertices);
    void addEdge(T V1,T V2,bool bidirectional);
    void printAdjList();
    void reverseAdjList();
    void DFS_helper1(T startingVertex,map<T,bool> &visited);
    bool DFS1();
    void DFS_helper2(T startingVertex,map<T,bool> &visited);
    bool DFS2();
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T V1,T V2,bool bidirectional)
{
    adjList[V1].push_back(V2);
    if(bidirectional)
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
    cout<<endl;
    for(auto it=reverseList.begin();it!=reverseList.end();it++)
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
void Graph<T>::reverseAdjList()
{
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        /// Edge from it->first to *it
        for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++)
        {
            reverseList[*it1].push_back(it->first);
        }
    }
}
template<typename T>
void Graph<T>::DFS_helper1(T startingVertex,map<T,bool> &visited)
{
    /// Mark the node as visited
    visited[startingVertex]=true;
    /// Visit it's children if not visited already
    for(auto it=adjList[startingVertex].begin();it!=adjList[startingVertex].end();it++)
    {
        if(!visited[*it])
        {
            DFS_helper1(*it,visited);
        }
    }
}
template<typename T>
bool Graph<T>::DFS1()
{
    /// Chose the starting vertex as the 1st vertex
    auto start=adjList.begin();
    /// Initialize the visited array
    map<T,bool> visited;
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        visited[it->first]=false;
    }
    /// Call DFS starting from 1st vertex
    DFS_helper1(start->first,visited);
    /// Check if all vertices visited
    for(auto it=visited.begin();it!=visited.end();it++)
    {
        if(!visited[it->first])
        {
            return false;
        }
    }
    return true;
}
template<typename T>
void Graph<T>::DFS_helper2(T startingVertex,map<T,bool> &visited)
{
    visited[startingVertex]=true;
    for(auto it=reverseList[startingVertex].begin();it!=reverseList[startingVertex].end();it++)
    {
        if(!visited[*it])
        {
            DFS_helper2(*it,visited);
        }
    }
}
template<typename T>
bool Graph<T>::DFS2()
{
    /// Initialize visited array
    map<T,bool> visited;
    for(auto it=reverseList.begin();it!=reverseList.end();it++)
    {
        visited[it->first]=false;
    }
    /// Choose starting vertex
    auto start=reverseList.begin();
    /// Call DFS
    DFS_helper2(start->first,visited);
    /// Check if all vertices visited
    for(auto it=visited.begin();it!=visited.end();it++)
    {
        if(!visited[it->first])
        {
            return false;
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
        cout<<"Is it bidirectional"<<endl;
        bool bidirectional;
        cin>>bidirectional;
        g.addEdge(v1,v2,bidirectional);
    }
    cout<<endl;
    g.reverseAdjList();
    g.printAdjList();
    cout<<endl;
    cout<<endl;
    if(g.DFS1())
    {
        if(g.DFS2())
        {
            cout<<"Graph is strongly connected"<<endl;
        }
        else
        {
            cout<<"Graph is not strongly connected"<<endl;
        }
    }
    else
    {
        cout<<"Graph is not strongly connected"<<endl;
    }
}
