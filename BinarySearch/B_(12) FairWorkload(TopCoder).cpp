/// i can be equal to j as single element can also be there
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> a,int maximum,int workers)
{
    int i=0,count=0,sum;
    int n=a.size();
    //cout<<"Hi"<<endl;
    while(i<n && count<workers)
    {
        if(a[i]>maximum)
            return false;
        sum=0;
        while(((sum+a[i])<=maximum) && i<n)
        {
            sum=sum+a[i];
            i++;
        }
        if(sum>0)
        {
            count++;
        }
        //cout<<maximum<<" Hi"<<endl;
    }
   //cout<<maximum<<" "<<i<<endl;
   if(i<n)
    return false;
   else
    return true;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       vector<int> v(n);
       int workers;
       cin>>workers;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           cin>>v[i];
           sum=sum+v[i];
       }
       //cout<<sum<<endl;
       int low=0;
       int high=sum; /// Ek banda sare utha le
       int mid;  /// Maximum load
       int maximum=-1;
       while(low<=high)
       {
         mid=(high+low)/2;
         if(check(v,mid,workers)) /// Possible
         {
            /// Store and reduce
            maximum=mid;
            high=mid-1;
         }
         else  /// Not possible increase maximum
         {
             low=mid+1;
         }
         //cout<<"H"<<endl;
       }
       cout<<maximum<<endl;
   }
}
