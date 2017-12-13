RECURSION-CODES OF THE STRING
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. 
Write a recursive function (return type Arraylist) to print all possible codes for the string.
E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.


#include<bits/stdc++.h>
using namespace std;
#define start 96  /// Ascii value of a is 97
vector<string> answers;
void print(string s,string output,int index)
{
  if(index==s.length())
  {
    answers.push_back(output);
    return;
  }
  /// Take 1st character or take both if less than equal to 26
  /// Take 1st
  output.push_back(start+(s[index]-'0'));
  print(s,output,index+1);
  /// Take 1st and 2nd both
  if(index<=s.length()-2)
  {
    output.pop_back();
    int number=((s[index]-'0')*10)+(s[index+1]-'0');
    //cout<<number<<endl;
    if(number<=26)
    {
      output.push_back(start+number);
      print(s,output,index+2);
    }
  }
}
int main()
{
   string s,output;
   cin>>s;
   cout<<"[";
   print(s,output,0);
   for(int i=0;i<answers.size();i++)
   {
    cout<<answers[i];
    if(i!=answers.size()-1)
    {
      cout<<","<<" ";
    }
   }
   cout<<"]";
}
