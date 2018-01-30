https://drive.google.com/open?id=1dB4qqWKd3xXkb9ZytpZ8y_eeodyXnUFu
https://drive.google.com/open?id=1g1tAwrTw4H9Dndm-KZvVN359B4NYhPNe
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the no of elements in array"<<endl;
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter element to search"<<endl;
    int element;
    cin>>element;
    auto it=lower_bound(v.begin(),v.end(),element);
    cout<<"Lower bound of "<<element<<" is "<<it-v.begin()<<endl;
    auto it1=upper_bound(v.begin(),v.end(),element);
    cout<<"Upper bound of "<<element<<" is "<<it1-v.begin()<<endl;
    cout<<"Total occurrence of element is "<<it1-it<<endl;
}
