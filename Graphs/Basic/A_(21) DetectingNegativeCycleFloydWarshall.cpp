3
3
1 2 -1
2 3 2
3 1 -3
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

  private:
      int number_of_vertices;
      map<pair<T,T>,int > adjMatrix;
      set<T> vertexList;
  public:
      Graph(int no_of_vertices);
      void addEdge(T v1,T v2,int distance,bool bidirectional);
      void printAdjmatrix();
      bool floydWarshal();
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T v1,T v2,int distance,bool bidirectional)
{
    adjMatrix[make_pair(v1,v2)]=distance;
    if(bidirectional)
        adjMatrix[make_pair(v2,v1)]=distance;
    vertexList.insert(v1);
    vertexList.insert(v2);
}
template<typename T>
void Graph<T>::printAdjmatrix()
{
    for(auto it=adjMatrix.begin();it!=adjMatrix.end();it++)
    {
        cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
    }
    for(auto it=vertexList.begin();it!=vertexList.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
}
template<typename T>
bool Graph<T>::floydWarshal()
{
   /// k is equal to number of vertex
   /// Initialize the matrix of size vertex*vertex
   map< pair<T,T>,long long int> distance;
   map< pair<T,T>,int> predecessor;
   /// Iterate over v*v
   for(auto it=vertexList.begin();it!=vertexList.end();it++)
   {
       for(auto it1=vertexList.begin();it1!=vertexList.end();it1++)
       {
           /// Check if Edge from (*it) to (*it1)
           auto mila=adjMatrix.find(make_pair(*it,*it1));
           if(mila!=adjMatrix.end())
           {
               /// Edge exists of length mila->second from *it to *it1
               distance[make_pair(*it,*it1)]=mila->second;
               predecessor[make_pair(*it,*it1)]=*it;
           }
           else
           {
               /// Can be same vertex
               if(*it==*it1)
               {
                   distance[make_pair(*it,*it1)]=0;
               }
               else
               {
                   /// No edge exits
                   distance[make_pair(*it,*it1)]=INT_MAX;
               }
               predecessor[make_pair(*it,*it1)]=-1; /// It denotes NIL
           }
       }
   }
   /// Now begins the algorithm
   /// 3 loops
   /// For k=0 we have already calculated so start from k=1
   for(auto k=vertexList.begin();k!=vertexList.end();k++)
   {
       for(auto i=vertexList.begin();i!=vertexList.end();i++)
       {
           for(auto j=vertexList.begin();j!=vertexList.end();j++)
           {
               /// Edge from *i to *j
               /// Check if there is need to update
               /// min( k-1Dij ,k-1Dik + k-1Dkj)
               /// k-1Dij already stored in previous matrix so only need to check
               auto it1=distance.find(make_pair(*i,*j));
               auto it2=distance.find(make_pair(*i,*k));
               auto it3=distance.find(make_pair(*k,*j));
               if(it2->second+it3->second<it1->second)
               {
                   /// Update distance between *i and *j
                   distance[make_pair(*i,*j)]=it2->second+it3->second;
                   /// Update predecessor
                   predecessor[make_pair(*i,*j)]=*k;
               }
           }
       }
   }
   /// If distance of a vertex from itself becomes negative than negative cycle is present
   for(auto it=vertexList.begin();it!=vertexList.end();it++)
   {
       if(distance[make_pair(*it,*it)]<0)
       {
           return true;
       }
   }
   return false;
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
    g.printAdjmatrix();
    cout<<endl;
    if(g.floydWarshal())
    {
        cout<<"Negative cycle present"<<endl;
    }
    else
    {
        cout<<"Negative cycle not present"<<endl;
    }
}
