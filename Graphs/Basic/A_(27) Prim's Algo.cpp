https://drive.google.com/open?id=1RQ6N4QaGuHDW_t0CImjJUAeiO1GJ1eO7
https://drive.google.com/open?id=1dY8W0NTsfu7dq_jmkZJdenbMbDT2WOAh
https://drive.google.com/open?id=1FEwDqQMazpjFDgrJ1LDT5xk48h2C8Kca
https://drive.google.com/open?id=1KVUX0J9oxVAm5AYQXNfwpfRCcR8uLwOG
https://drive.google.com/open?id=1UhAwjsR_1xm1cxCa7docOyLeusJWzD2V
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

   private:
       map<pair<T,T>,int> adjList;
       int number_of_edges;
   public:
       Graph(int number_of_edges);
       void addEdge(T v1,T v2,int distance);
       void printAdjList();
       void primsMST();
};
template<typename T>
Graph<T>::Graph(int number_of_edges)
{
    number_of_edges=number_of_edges;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2,int distance)
{
    /// Undirected graph so
    adjList[make_pair(v1,v2)]=distance;
}
template<typename T>
void Graph<T>::printAdjList()
{
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        cout<<(it->first).first<<" "<<(it->first).second<<" "<<(it->second)<<endl;
    }
}
template<typename T>
void Graph<T>::primsMST()
{
    /// Take 2 sets
    set<T> mst_set;
    set<T> not_visited_set;
    map<T,long long int> distance;
    /// Initialize all of these
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        not_visited_set.insert(it->first.first);
        not_visited_set.insert(it->first.second);
    }
    for(auto it=not_visited_set.begin();it!=not_visited_set.end();it++)
    {
        distance[*it]=INT_MAX;
    }
    /// Set distance of 1 vertex as 0
    auto intial=not_visited_set.begin();
    distance[*intial]=0;
    /// Mst has V vertices
    int totalVertices=not_visited_set.size();
    int vertexAdded=0;
    vector<T> mstFinal;
    long long int totaldistance=0;
    cout<<totalVertices<<endl;
    while(vertexAdded<totalVertices)       /// Breaks when vertex added becomes equal to V
    {
        auto selected=not_visited_set.begin();
        long long int minimumDistance=INT_MAX;
        /// Select vertex with minimum distance in not_visited_set
        for(auto it=not_visited_set.begin();it!=not_visited_set.end();it++)
        {
            if(distance[*it]<minimumDistance)
            {
                minimumDistance=distance[*it];
                selected=it;

            }
        }
        totaldistance=totaldistance+minimumDistance;
        mstFinal.push_back(*selected);
        /// Insert this vertex in mst_set and remove from not_visited_set
        mst_set.insert(*selected);
        not_visited_set.erase(*selected);
        /// Update distance of remaining vertices in not_visited_set
        for(auto it=not_visited_set.begin();it!=not_visited_set.end();it++)
        {
            if(adjList[make_pair(*selected,*it)]<distance[*it] && adjList[make_pair(*selected,*it)]!=0)
            {
                distance[*it]=adjList[make_pair(*selected,*it)];
            }
        }
        vertexAdded++;
    }
    for(int i=0;i<mstFinal.size();i++)
    {
        cout<<mstFinal[i]<<" ";
    }
    cout<<endl;
    cout<<totaldistance<<endl;
}
int main()
{
    cout<<"Enter number of edges"<<endl;
    int number_of_edges;
    cin>>number_of_edges;
    Graph<int> g(number_of_edges);
    for(int i=1;i<=number_of_edges;i++)
    {
        cout<<"Enter edge no "<<i<<endl;
        cout<<"Enter vertex1 and vertex2"<<endl;
        int v1,v2,distance;
        cin>>v1>>v2;
        cout<<"Enter distance between them"<<endl;
        cin>>distance;
        g.addEdge(v1,v2,distance);
    }
    g.printAdjList();
    cout<<endl;
    g.primsMST();
}

