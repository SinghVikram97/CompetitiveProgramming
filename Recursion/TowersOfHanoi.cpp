/// For n discs total 2^n-1 moves
#include <bits/stdc++.h>
using namespace std;
/// Can't shift discs from below a disc
int steps(char source,char destination,char helper,int num_of_discs)
{
    if(num_of_discs==0 || num_of_discs==1)
        return num_of_discs;
    else
    {
        /// Move top n-1 discs to helper using destination
        int total_steps=steps(source,helper,destination,num_of_discs-1);
        /// Move last disc to destination from source
        total_steps=total_steps+1;
        /// Move n-1 discs from helper to destination using source
        total_steps=total_steps+steps(helper,destination,source,num_of_discs-1);
        return total_steps;
    }
}
void stepsSee(string source,string destination,string helper,int num_of_discs)
{
    if(num_of_discs==0 || num_of_discs==1)
    {
        cout<<"Move "<<1<<"th disc from "<<source<<" to "<<destination<<endl;
        return;
    }
    else
    {
        stepsSee(source,helper,destination,num_of_discs-1);
        cout<<"Move "<<num_of_discs<<"th disc from "<<source<<" to "<<helper<<endl;
        stepsSee(helper,destination,source,num_of_discs-1);
    }
}
int main()
{
    int n;
    cin>>n;
    stepsSee("T1","T2","T3",n);
    cout<<steps('A','B','C',n);
}
