https://drive.google.com/open?id=15FsrMEpaaVFU96YM1wvQbosqki7dcYA6
https://drive.google.com/open?id=1_sf9PM90ws9XIuz5l2FLunaN2kUAbd7R
https://drive.google.com/open?id=19xZZRNlEbsnWhspsKSCs8PnDO2hf45n0
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

 private:
    int number_of_vertices;
    map<T,list<T> > adjList;
    map<T,list<T> > reverseList;
    stack<T> myStack;
 public:
    Graph(int no_of_vertices);
    void addEdge(T V1,T V2,bool bidirectional);
    void printAdjList();
    void reverseAdjList();
    void DFS_helper(T startingVertex,map<T,bool> &visited);
    void DFS_helper1(T startingVertex,map<T,bool> &visited);
    void DFS();
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
void Graph<T>::DFS_helper(T startingVertex,map<T,bool> &visited)
{
    /// Mark it as visited
    visited[startingVertex]=true;
    /// Call Dfs on its neighbours
    for(auto it=adjList[startingVertex].begin();it!=adjList[startingVertex].end();it++)
    {
        if(!visited[*it])
        {
            DFS_helper(*it,visited);
        }
    }
    /// We can't go anywhere from this node so push it onto stack
    myStack.push(startingVertex);
}
template<typename T>
void Graph<T>::DFS_helper1(T startingVertex,map<T,bool> &visited)
{
    cout<<startingVertex<<" ";
    /// Mark it as visited
    visited[startingVertex]=true;
    /// Visit all it's neighbours if not visited
    for(auto it=reverseList[startingVertex].begin();it!=reverseList[startingVertex].end();it++)
    {
        if(!visited[*it])
        {
            DFS_helper1(*it,visited);
        }
    }
}
template<typename T>
void Graph<T>::DFS()
{
    /// Initialize visited array
    map<T,bool> visited;
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        visited[it->first]=false;
    }
    /// Call DFS for every node not visited
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        if(!visited[it->first])
        {
            DFS_helper(it->first,visited);
        }
    }
    /// Reverse the adjacency list
    reverseAdjList();
    /// Mark all nodes as not visited
    for(auto it=visited.begin();it!=visited.end();it++)
    {
        visited[it->first]=false;
    }
    /// Pop one by one from stack and call DFS from it if not visited
    while(!myStack.empty())
    {
        T start=myStack.top();
        myStack.pop();
        /// If not visited start DFS from this vertex
        if(!visited[start])
        {
            DFS_helper1(start,visited);
            cout<<endl;
        }
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
        cout<<"Is it bidirectional"<<endl;
        bool bidirectional;
        cin>>bidirectional;
        g.addEdge(v1,v2,bidirectional);
    }
    cout<<endl;
    g.DFS();
}
