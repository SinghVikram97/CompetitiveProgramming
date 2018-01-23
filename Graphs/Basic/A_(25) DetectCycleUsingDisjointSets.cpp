https://drive.google.com/open?id=10_YL44bn2x2Mt7HyBxJda3wadV04gBh1
#include<bits/stdc++.h>
using namespace std;
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
     int number_of_edges;
     vector< pair<T,T> > edgeList;
 public:
    Graph(int no_of_edges);
    void addEdge(T v1,T v2);
    void printEdgeList();
};
template<typename T>
Graph<T>::Graph(int no_of_edges)
{
    number_of_edges=no_of_edges;
    vector<pair<T,T> > edgeList=vector<pair<T,T> >(no_of_edges);
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2)
{
    edgeList.push_back(make_pair(v1,v2));
}
template<typename T>
void Graph<T>::printEdgeList()
{
    for(int i=0;i<edgeList.size();i++)
    {
        cout<<edgeList[i].first<<" "<<edgeList[i].second<<endl;
    }
}
int main()
{
    disjointSet<int> s;
    cout<<"Enter no of vertices"<<endl;
    int number_of_vertices;
    cin>>number_of_vertices;
    for(int i=1;i<=number_of_vertices;i++)
    {
        cout<<"Enter value of "<<i<<" vertex"<<endl;
        int vertex;
        cin>>vertex;
        s.make_set(vertex);
    }
    cout<<"Enter number of edges"<<endl;
    int number_of_edges;
    cin>>number_of_edges;
    Graph<int> g(number_of_edges);
    for(int i=1;i<=number_of_edges;i++)
    {
        cout<<"Enter edge "<<i<<endl;
        cout<<"Enter vertex1 and vertex2"<<endl;
        int v1,v2;
        cin>>v1>>v2;
        g.addEdge(v1,v2);
        if(s.find_set(v1)==s.find_set(v2))
        {
            cout<<"Graph contains a cycle"<<endl;
            return 0;
        }
        else
        {
            s.union_set(v1,v2);
        }
    }
    cout<<"Graph doesn't contain a cycle"<<endl;
    return 0;
}
