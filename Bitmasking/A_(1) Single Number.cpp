https://leetcode.com/problems/single-number/description/
https://drive.google.com/open?id=17rVVCaGwLtxExf0Fw9X1H1rRIn4mNH63

#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums)
{
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        ans=ans^nums[i];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<singleNumber(v);
}
