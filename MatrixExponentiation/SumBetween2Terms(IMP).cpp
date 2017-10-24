http://www.spoj.com/problems/SPP/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> f,c;
int k;
ll m;
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B)
{
    /// 1 based matrices of order k*k
    ll K=A.size()-1;
    vector<vector<ll> > C(K+1,vector<ll>(K+1));
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=K;j++)
        {
            C[i][j]=0;
            for(int k=1;k<=K;k++)
            {
                C[i][j]=(C[i][j]+((A[i][k]%m)*(B[k][j]%m))%m)%m;
            }
        }
    }
    return C;
}
vector<vector<ll> > power(vector<vector<ll>> A,ll n)
{
    if(n==1)
    {
        return A;
    }
    vector<vector <ll>> smallPower=power(A,n/2);
    smallPower=multiply(smallPower,smallPower);
    if(n%2==0)
    {
        return smallPower;
    }
    else
    {
        return multiply(smallPower,A);
    }

}
ll compute(ll n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<=k)
    {
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans=((ans%m)+(f[i]%m))%m;
        }
        return ans%m;
    }
    /// Construct F1 vector
    vector<ll> F1(k+2); /// 1 based indexing
    /// S(1)=S(k)
    ll ans=0;
    for(int i=0;i<k;i++)
    {
        ans=((ans%m)+(f[i]%m))%m;
    }
    F1[1]=ans%m;
    for(int i=2;i<=k+1;i++)
    {
        F1[i]=f[i-2];
    }
    /// Transformation matrix
    vector<vector<ll> > T(k+2,vector<ll>(k+2));
    for(int i=1;i<=k+1;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            if(i==1)
            {
                if(j==1)
                {
                    T[i][j]=1;
                }
                else
                {
                    T[i][j]=c[k+1-j];
                }
            }
            else
            {
                if(j==i+1)
                {
                    T[i][j]=1;
                }
            }
            if(i==k+1)
            {
                if(j==1)
                {
                    T[i][j]=0;
                }
                else
                {
                    T[i][j]=c[k+1-j];
                }
            }

        }
    }
    /// Compute T^n-1
    T=power(T,n-k);
    ll ans1=0;
    for(int i=1;i<=k+1;i++)
    {
        ans1=(ans1+((T[1][i]%m)*(F1[i]%m))%m)%m;
    }
    return ans1%m;
}
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       cin>>k;
       for(int i=0;i<k;i++)
       {
           ll num;
           cin>>num;
           f.push_back(num);
       }
       for(int i=0;i<k;i++)
       {
           ll num;
           cin>>num;
           c.push_back(num);
       }
       ll p,q;
       cin>>p>>q>>m;
       ll ans2=compute(q);
       ll ans1=compute(p-1);
       cout<<(((ans2-ans1)%m)+m)%m<<endl;
       f.clear();
       c.clear();
   }
}
