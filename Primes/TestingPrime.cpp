#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
bool isPrime(ll num)
{
   if(num==0 || num==1)
   {
       return false;
   }
   else if(num==2)
   {
       return true;
   }
   else if(num%2==0)
   {
       return false;
   }
   for(int i=3;i*i<=num;i=i+2)
   {
       if(num%i==0)
       {
           return false;
       }
   }
   return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
   int n;
   cin>>n;
   while(n--)
   {
       ll m;
       cin>>m;
       if(isPrime(m))
       {
           cout<<"YES";
       }
       else
       {
           cout<<"NO";
       }
       cout<<endl;
   }
}
