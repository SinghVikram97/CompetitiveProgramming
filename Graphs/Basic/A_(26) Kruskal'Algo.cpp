/// Imp Link
https://stackoverflow.com/questions/33913305/must-use-or-to-call-pointer-to-member-function-in-lessthan-e
/// Images
https://drive.google.com/open?id=1aQYs3xJo8WCVMsA1RLZEX9jIJjGVCE5S
https://drive.google.com/open?id=1Y35kvbPevP06hI-neroDRWHrTStx0BPu
https://drive.google.com/open?id=1OJsY5r1RuEdMp12-lFE1UKnTPqHQ9z4U
/// Input
14
0 1 
4
1 2
8
2 3
7
3 4
9
4 5
10
5 6
2
6 7
1
0 7
8
1 7 
11
7 8 
7
2 8
2
6 8
6
2 5
4
3 5
14

#include<bits/stdc++.h>
using namespace std;
bool myComp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
    return p1.second<=p2.second;
}
template<typename T>
class disjointSet
{
private:
    map<T,T> representative;
    map<T,int> rank_element;
public:
    void make_set(T x);
    void union_set(T x,T y);
    T find_set(T x);
};
template<typename T>
void disjointSet<T>::make_set(T x)
{
    /// Initialize representative as itself
    /// And rank as 0
    representative[x]=x;
    rank_element[x]=0;
}
template<typename T>
void disjointSet<T>::union_set(T x,T y)
{
    /// Find representative of x and y
    T representativeX=find_set(x);
    T representativeY=find_set(y);
    /// Check ranks of both representatives
    if(rank_element[representativeX]==rank_element[representativeY])
    {
        /// Increment rank by 1
        /// Add 2nd to bottom of 1
        /// Make representative of 2 as 1
        representative[representativeY]=representative[representativeX];
        rank_element[representativeX]=rank_element[representativeX]+1;
    }
    else
    {
        /// ranks not equal
        if(rank_element[representativeX]>rank_element[representativeY])
        {
            /// Add Y to bottom of x
            /// Make x as representative
            representative[representativeY]=representative[representativeX];
        }
        else
        {
            representative[representativeX]=representative[representativeY];
        }
    }
}
template<typename T>
T disjointSet<T>::find_set(T x)
{
    /// if element representative of itself return
    if(representative[x]==x)
        return x;
    /// Store the result and make it to point to representative
    T result=find_set(representative[x]);
    representative[x]=result;
    return result;
}
template<typename T>
class Graph{

private:
    vector<pair<pair<T,T>,int> > edgeList;
    int number_of_edges;
    set<T> vertices;

public:
   Graph(int number_of_edges);
   void addEdge(T v1,T v2,int weight);
   void printEdgeList();
   void kruskalMST();
};
template<typename T>
Graph<T>::Graph(int number_of_edges)
{
    number_of_edges=number_of_edges;
    vector<pair<pair<T,T>,int> > edgeList=vector<pair<pair<T,T>,int> > (number_of_edges);
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2,int weight)
{
    vertices.insert(v1);
    vertices.insert(v2);
    edgeList.push_back(make_pair(make_pair(v1,v2),weight));
}
template<typename T>
void Graph<T>::printEdgeList()
{
    for(int i=0;i<edgeList.size();i++)
    {
        cout<<edgeList[i].first.first<<" "<<edgeList[i].first.second<<" "<<edgeList[i].second<<endl;
    }
    cout<<endl;
    sort(edgeList.begin(),edgeList.end(),myComp);
        for(int i=0;i<edgeList.size();i++)
    {
        cout<<edgeList[i].first.first<<" "<<edgeList[i].first.second<<" "<<edgeList[i].second<<endl;
    }
    cout<<vertices.size();
}
template<typename T>
void Graph<T>::kruskalMST()
{
   disjointSet<int> s;
   /// Initially all vertices in different set
   /// Call make set on each vertex
   for(auto it=vertices.begin();it!=vertices.end();it++)
   {
       s.make_set(*it);
   }
   /// Traverse the edge list one edge at a time
   int edgesInMst=0;
   int edgeIndex=0;
   vector<pair<pair<T,T>,int> > mst;
   while(edgesInMst<=vertices.size()-1 && edgeIndex<edgeList.size())
   {
       /// Find if vertices in same set or not
       T representativeV1=s.find_set(edgeList[edgeIndex].first.first);
       T representativeV2=s.find_set(edgeList[edgeIndex].first.second);
       if(representativeV1==representativeV2)
       {
           /// Already in same set so it forms cycle don't include
       }
       else
       {
           /// Include
           s.union_set(edgeList[edgeIndex].first.first,edgeList[edgeIndex].first.second);
           /// Increase no of edges in MST
           edgesInMst++;
           /// Add edge in mst
           mst.push_back(make_pair(make_pair(edgeList[edgeIndex].first.first,edgeList[edgeIndex].first.second),edgeList[edgeIndex].second));
       }
       edgeIndex++;
   }
   /// Check if can form the MST
   /// MST WILL BE FORMED EVERYTIME
   /// EVERY GRAPH HAS AN MST EXCEPT DISCONNECTED GRAPH
   if(edgesInMst!=vertices.size()-1)
   {
       cout<<"Can't form MST"<<endl;
       return;
   }
   else
   {
       /// Print the mst
      for(int i=0;i<mst.size();i++)
     {
       cout<<mst[i].first.first<<" "<<mst[i].first.second<<" "<<mst[i].second<<endl;
     }
   }
}
int main()
{
    cout<<"Enter the number of edges in graph"<<endl;
    int number_of_edges;
    cin>>number_of_edges;
    Graph<int> g(number_of_edges);
    for(int i=1;i<=number_of_edges;i++)
    {
        cout<<"Enter edge number "<<i<<endl;
        cout<<"Enter vertex1 and vertex2"<<endl;
        int v1,v2;
        cin>>v1>>v2;
        cout<<"Enter distance between them"<<endl;
        int distance;
        cin>>distance;
        g.addEdge(v1,v2,distance);
    }
    g.printEdgeList();
    cout<<endl;
    g.kruskalMST();
}
