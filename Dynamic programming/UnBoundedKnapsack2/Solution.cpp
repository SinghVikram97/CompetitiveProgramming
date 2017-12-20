#include<bits/stdc++.h>
using namespace std;
long long int maximum_possible_sum(vector<int> numbers,int expected_sum)
{
   long long int dp[expected_sum+1]; /// dp[i] represents maximum possible sum if expected sum is 'i'
   dp[0]=0;  /// Select 0 numbers
   for(int i=1;i<=expected_sum;i++)
   {
     dp[i]=0;
   }
   long long int current_sum;
   for(int i=1;i<=expected_sum;i++)
   {
     /// At any point we can select any one number from our list
     for(int j=0;j<numbers.size();j++)
     {
       /// Subject to condition
       if(numbers[j]<=i)
       {
           current_sum=numbers[j]+dp[i-numbers[j]];
           if(current_sum>dp[i])
           {
             dp[i]=current_sum;
           }
       }
     }
   }
   if(dp[expected_sum]==0)  /// No element can be selected
   {
     return 0;  /// If we want sum=2 and all elements are greater than 2
   }
   else
   {
     return dp[expected_sum];
   }
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int no_of_numbers,expected_sum;
     cin>>no_of_numbers>>expected_sum;
     vector<int> numbers(no_of_numbers);
     for(int i=0;i<no_of_numbers;i++)
     {
       cin>>numbers[i];
     }
     cout<<maximum_possible_sum(numbers,expected_sum)<<endl;
   }
}
