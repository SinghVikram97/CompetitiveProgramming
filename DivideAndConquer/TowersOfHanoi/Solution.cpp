#include<bits/stdc++.h>
using namespace std;
void towers_of_hanoi(char source,char destination,char helper,int number_of_discs)
{
    if(number_of_discs==1)
    {
        cout<<"Moving ring "<<1<<" from "<<source<<" to "<<destination<<endl;
        return;
    }
    else
    {
        /// 1. Move n-1 rings source to helper using destination
        towers_of_hanoi(source,helper,destination,number_of_discs-1);
        /// 2. Move 1 ring from A to B
        cout<<"Moving ring "<<number_of_discs<<" from "<<source<<" to "<<destination<<endl;
        /// 3. Move n-1 ring from helper to destination using source
        towers_of_hanoi(helper,destination,source,number_of_discs-1);
    }
}
int main()
{
    int n;
    cin>>n;
    towers_of_hanoi('A','B','C',n);
}
