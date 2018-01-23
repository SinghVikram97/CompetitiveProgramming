https://drive.google.com/open?id=17QZA2b84guexeDRE3K_0bBR4Hz0QpniP
https://drive.google.com/open?id=18MLPlHAvOZ41UERSlKgfQxzYcryj2OtY
https://drive.google.com/open?id=1J11qOyODrjMQtEL-QoyKeHbkdIlC-tO_
https://drive.google.com/open?id=13qZrNifNkqttM50o3lwSf_k4AKYO6eb6

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
int main()
{
    disjointSet<int> g;
    cout<<"Enter no of elements in set"<<endl;
    int no_of_elements;
    cin>>no_of_elements;
    for(int i=1;i<=no_of_elements;i++)
    {
        cout<<"Enter element no "<<(i)<<endl;
        int element;
        cin>>element;
        g.make_set(element);
    }
    cout<<"Enter number of operations"<<endl;
    int no_of_operations;
    cin>>no_of_operations;
    for(int i=1;i<=no_of_operations;i++)
    {
        cout<<"1.Union 2.FindSet"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the 2 elements"<<endl;
            int element1,element2;
            cin>>element1>>element2;
            g.union_set(element1,element2);
        }
        else
        {
            cout<<"Enter element to find in which set it is"<<endl;
            int element;
            cin>>element;
            cout<<g.find_set(element)<<endl;
        }
    }
}
