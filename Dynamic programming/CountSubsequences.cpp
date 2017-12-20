#include<bits/stdc++.h>
using namespace std;
set<string> subsequences;
void count_subsequences(string s,string output,int index)
{
   //cout<<output<<endl;
   if(index==s.length())
   {
     subsequences.insert(output);
     return;
   }
   /// Select or leave
   count_subsequences(s,output,index+1);
   output.push_back(s[index]);
   count_subsequences(s,output,index+1);
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     string s,output;
     cin>>s;
     output="";
     count_subsequences(s,output,0);
     cout<<subsequences.size()<<endl;
     subsequences.clear();
   }
}
