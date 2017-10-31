#include<bits/stdc++.h>
using namespace std;
bool check(vector<unsigned long long int> a,unsigned long long int diff,long int c)
{
    long int i=0;
    long int j=1;
    long long count=1;
    long int n=a.size();
    while(j<n && count<c)
    {
        if(a[j]-a[i]<diff)
        {
            j++;
        }
        else
        {
            i=j;
            j=i+1;
            count++;
        }
    }
    if(count==c)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       long int n;
       cin>>n;
       long int c;
       cin>>c;
       vector<unsigned long long int> v(n);
       for(int i=0;i<n;i++)
       {
           cin>>v[i];
       }
       sort(v.begin(),v.end());
       unsigned long long int high=v[n-1]-v[0];
       unsigned long long int low=0;
       unsigned long long int mid;
       unsigned long long int maximum;
       /// Mid is our diff
       while(low<=high)
       {
           mid=low+(high-low)/2;
           if(check(v,mid,c))
           {
               /// Store it in temporary variable
               maximum=mid;
               low=mid+1;
           }
           else
           {
               high=mid-1;
           }
       }
       cout<<maximum<<endl;
   }
}
