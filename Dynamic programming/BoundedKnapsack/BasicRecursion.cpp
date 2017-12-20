4 5
1 8
2 4
3 0
2 5
2 3
17
#include<bits/stdc++.h>
using namespace std;
int maximum_value(int capacity,vector<int> size,vector<int> value,int index)
{
   ///Base cases
   if(capacity==0) /// Knapsack becomes full can't keep more items
   {
     return 0; /// Empty knapsack so value 0
   }
   else if(index==value.size())
   {
     return 0;
   }
   int max1=-1,max2=-1;
   /// 2 options select or don't select for keeping in knapsack
   /// 1.select
   /// Can select if
   if(size[index]<=capacity)
   {
     max1=value[index]+maximum_value(capacity-size[index],size,value,index+1);
   }   
   /// 2.don't select
   max2=maximum_value(capacity,size,value,index+1);
   return max(max1,max2);
}
int main()
{
   int capacity,no_of_items;
   cin>>capacity>>no_of_items;
   vector<int> size(no_of_items);
   vector<int> value(no_of_items);
   for(int i=0;i<no_of_items;i++)
   {
     cin>>size[i]>>value[i];
   }
   cout<<maximum_value(capacity,size,value,0); /// Maximum sum of values just smaller or equal to capacity
}
