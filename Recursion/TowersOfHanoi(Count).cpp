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
int main()
{
    int n;
    cin>>n;
    cout<<steps('A','B','C',n);
}
