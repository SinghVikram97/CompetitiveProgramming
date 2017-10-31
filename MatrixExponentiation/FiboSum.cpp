The Fibonacci sequence is defined by the following relation:

F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2 
Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Source: FIBOSUM (SPOJ)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B)
{
    /// Each matrix of size k*k
    /// Here k=2;
    vector<vector<ll> > C(3,vector<ll>(3));
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            for(int k=1;k<=2;k++)
            {
                C[i][j]=(C[i][j]+((A[i][k]%m)*(B[k][j]%m))%m)%m;
            }
        }
    }
    return C;
}
vector<vector<ll> >power(vector<vector<ll> > A,ll n)
{
   if(n==1)
   {
       return A;
   }
   vector<vector<ll> > smallPower=power(A,n/2);
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
    ///F1 matrix
    vector<ll> F(3);
    F[1]=0;
    F[2]=1;
    if(n<=2)
    {
        return F[n];
    }
    /// Transformation matrix
    vector<vector<ll> > T(3,vector<ll>(3));
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(j==i+1)
            {
                T[i][j]=1;
            }
            if(i==2)
            {
                T[i][j]=1;  /// Not T[i][j]=F[3-j]
            }
        }
    }
    /// Compute T^n-1
    T=power(T,n-1);
    /// Calculate nth term
    ll ans=0;
    for(int i=1;i<=2;i++)
    {
        ans=(ans+((T[1][i]%m)*(F[i]%m))%m)%m;
    }
    return ans%m;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        ll ans=0;
        cin>>n>>p;
        ll ans1=compute(n+2);
        ll ans2=compute(p+3);
        cout<<(((ans2-ans1)%m)+m)%m<<endl; /// Negative mod
    }
}
