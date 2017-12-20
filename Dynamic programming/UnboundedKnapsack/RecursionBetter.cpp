#include<bits/stdc++.h>
using namespace std;
int maximum_value(int capacity,vector<int> size,vector<int> value)
{
   /// Base cases
   if(capacity==0)
   {
     return 0;
   }
   int finalAns=-1;
   int currentAns=-1;
   /// At any step we can select any one item (As repetition is allowed)
   for(int i=0;i<value.size();i++)
   {
     if(size[i]<=capacity)
     {
          /// Can be selected
           currentAns=value[i]+maximum_value(capacity-size[i],size,value);
           if(currentAns>finalAns)
           {
             finalAns=currentAns;
           }
     }
   }
   return finalAns;
}
int main()
{
   int no_of_items,capacity;
   cin>>no_of_items>>capacity;
   vector<int> size(no_of_items);
   vector<int> value(no_of_items);
   for(int i=0;i<no_of_items;i++)
   {
     cin>>size[i];
   }
   for(int i=0;i<no_of_items;i++)
   {
     cin>>value[i];
   }
   cout<<maximum_value(capacity,size,value);
}
