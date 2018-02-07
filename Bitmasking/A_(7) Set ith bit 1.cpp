https://drive.google.com/open?id=1IO3DS7RNF1ARcuvF2Vy6wbOhaJWV0UEB

#include<bits/stdc++.h>
using namespace std;
void setBit(int &a,int i)
{
    int temp=1<<i;
    a=a|temp;
    return;
}
int main()
{
    int a,i;
    cin>>a>>i;
    cout<<"Number before "<<a<<endl;
    setBit(a,i);
    cout<<"Number after "<<a<<endl;
}
