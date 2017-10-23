https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/staircase/description/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > multiply(vector<vector<int> > A,vector<vector<int> > B)
{
    /// 1 based matrices of order k*k
    int K=A.size()-1;
    vector<vector<int> > C(K+1,vector<int>(K+1));
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=K;j++)
        {
            C[i][j]=0;
            for(int k=1;k<=K;k++)
            {
                C[i][j]=(C[i][j]+((A[i][k])*(B[k][j])));
            }
        }
    }
    return C;
}
vector<vector<int> > power(vector<vector<int>> A,int n)
{
    if(n==1)
    {
        return A;
    }
    vector<vector <int>> smaintPower=power(A,n/2);
    smaintPower=multiply(smaintPower,smaintPower);
    if(n%2==0)
    {
        return smaintPower;
    }
    else
    {
        return multiply(smaintPower,A);
    }
}
int computeJack(int n)
{
    if(n<0)
    {
        cout<<"ERROR";
        return -1;
    }
    /// Jack ka
    vector<int> F1(4); /// k=3 so 1 2 3 (1 based indexing)
    F1[0]=0;
    for(int i=1;i<=3;i++)
    {
        F1[i]=pow(2,i-1);
    }
    if(n<=3)
    {
        return F1[n];
    }
    vector<vector<int> > T(4,vector<int>(4)); /// k*k and 1 based indexing
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j==i+1)
            {
                T[i][j]=1;
            }
            if(i==3)  /// kth row ie. last row
            {
                T[i][j]=1;
            }
        }
    }
    /// T^n-1
    T=power(T,n-1);
    /// 1st term in T^n-1 * F1
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        ans=ans+(T[1][i]*F1[i]);
    }
    return ans;
}
int computeJill(int n)
{
    if(n<0)
    {
        cout<<"ERROR";
        return -1;
    }
    /// Jack ka
    vector<int> F1(3); /// k=2 so 1 2  (1 based indexing)
    F1[0]=0;
    for(int i=1;i<=2;i++)
    {
        F1[i]=pow(2,i-1);
    }
    if(n<=2)
    {
        return F1[n];
    }
    vector<vector<int> > T(3,vector<int>(3)); /// k*k and 1 based indexing
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(j==i+1)
            {
                T[i][j]=1;
            }
            if(i==2)  /// kth row ie. last row
            {
                T[i][j]=1;
            }
        }
    }
    /// T^n-1
    T=power(T,n-1);
    /// 1st term in T^n-1 * F1
    int ans=0;
    for(int i=1;i<=2;i++)
    {
        ans=ans+(T[1][i]*F1[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    if(n<0)
    {
        cout<<"ERROR";
        return 0;
    }
    cout<<"Jack-"<<computeJack(n)<<endl;
    cout<<"Jill-"<<computeJill(n);
}
