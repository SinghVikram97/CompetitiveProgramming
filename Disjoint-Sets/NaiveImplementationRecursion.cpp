https://drive.google.com/open?id=1uAqc2HhTZm8g8_XGDUmA-4lsJ8EfZTaE
https://drive.google.com/open?id=1ursBlvS7A8yUtacgAt3hBuq3f8k_MePr
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class disjointSet
{
public:
    void make_set(T x);
    void union_set(T x,T y);
    T find_set(T x);
    void print();
    map<T,T> representative;
};
template<typename T>
void disjointSet<T>::make_set(T x)
{
    /// Set a element as representative of itself
    representative[x]=x;
}
template<typename T>
void disjointSet<T>::union_set(T x,T y)
{
    /// Find representative of x and representative of y
    T representativeX=find_set(x);
    T representativeY=find_set(y);
    /// Set representative of representative of y as representative of x
    representative[representativeY]=representativeX;
}
template<typename T>
T disjointSet<T>::find_set(T x)
{
    /// Returns representative of a set
    if(representative[x]==x)
        return x;
    else
        return find_set(representative[x]);
}
template<typename T>
void disjointSet<T>::print()
{
    for(auto it=representative.begin();it!=representative.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
int main()
{
    disjointSet<int> s;
    cout<<"Enter number of elements in set"<<endl;
    int number_of_elements;
    cin>>number_of_elements;
    cout<<"Enter elements of set"<<endl;
    for(int i=0;i<number_of_elements;i++)
    {
        int element;
        cout<<"Enter element "<<(i+1)<<endl;
        cin>>element;
        s.make_set(element);
    }
    cout<<"Enter number of operations"<<endl;
    int number_of_operations;
    cin>>number_of_operations;
    for(int i=0;i<number_of_operations;i++)
    {
        cout<<"1.Union 2.Find-set"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter 2 elements"<<endl;
            int x,y;
            cin>>x>>y;
            s.union_set(x,y);
        }
        else
        {
            cout<<"Enter element to find in which set it lies"<<endl;
            int x;
            cin>>x;
            cout<<s.find_set(x)<<endl;
        }
         cout<<endl;
    }
    s.print();
}
