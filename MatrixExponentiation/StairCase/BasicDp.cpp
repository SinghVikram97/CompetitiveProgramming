https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/staircase/description/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<0)
    {
        cout<<"ERROR";
        return 0;
    }
    int jack[n+1];
    int jill[n+1];
    jack[0]=0;
    jill[0]=0;
    /// nth index denotes no of ways to reach there
    for(int i=1;i<=3;i++)
    {
        jack[i]=pow(2,i-1);
    }
    for(int i=1;i<=2;i++)
    {
        jill[i]=pow(2,i-1);
    }
    /// Jack ka ans
    int jack_ans;
    if(n<=3)
    {
        jack_ans=jack[n];
    }
    else
    {
       for(int i=4;i<=n;i++)
       {
           jack[i]=0;
        for(int j=1;j<=3;j++)
        {
            jack[i]+=jack[i-j];
        }
       }
      jack_ans=jack[n];
    }
    /// Jill ka ans
    int jill_ans;
    if(n<=2)
    {
        jill_ans=jill[n];
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            jill[i]=0;
            for(int j=1;j<=2;j++)
            {
                jill[i]+=jill[i-j];
            }
        }
        jill_ans=jill[n];
    }
    cout<<"Jack-"<<jack_ans<<endl;
    cout<<"Jill-"<<jill_ans<<endl;
}
