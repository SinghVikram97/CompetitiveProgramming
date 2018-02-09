#include<bits/stdc++.h>
using namespace std;
void update(vector<int> &blockArray,vector<int> &v,int index,int value)
{
    int number_of_blocks=blockArray.size();
    int block_size=sqrt(v.size());
    /// Update the block sum
    blockArray[index/block_size]=blockArray[index/block_size]-v[index]+value;

    /// Update the original array
    v[index]=value;

    return;
}
int query(vector<int> &blockArray,vector<int> &v,int l,int r)
{
    int number_of_blocks=blockArray.size();
    int block_size=sqrt(v.size());

    /// 2 possibilities
    /// 1. If l is starting of some block and r is ending of some block
    /// 2. l and r in middle

    /// Check if l is starting of some block and r ending
    if(l%block_size==0 && (r+1)%block_size==0)
    {
        /// Sum of blocks between l to r
        int startingBlockNo=l/block_size;
        int endingBlockNo=r/block_size;

        int sum=0;
        for(int i=startingBlockNo;i<=endingBlockNo;i++)
        {
            sum=sum+blockArray[i];
        }
        return sum;
    }

    /// Check if only l is staring of some block
    else if(l%block_size==0)
    {
        int startingBlockNo=l/block_size;
        int endingBlockNo=(r/block_size)-1;       /// !! IMP

        int sum=0;
        for(int i=startingBlockNo;i<=endingBlockNo;i++)
        {
            sum=sum+blockArray[i];
        }

        /// Sum remaining elements
        /// 1st element is 1st element of block no of r
        int firstElement=(r/block_size)*(block_size);  /// !! IMP
        int lastElement=r;
        for(int i=firstElement;i<=lastElement;i++)
        {
            sum=sum+v[i];
        }
        return sum;
    }
    /// Check if r is ending of some block
    else if((r+1)%block_size==0)
    {
        int startingBlockNo=(l/block_size)+1;
        int endingBlockNo=(r/block_size);

        int sum=0;
        for(int i=startingBlockNo;i<=endingBlockNo;i++)
        {
            sum=sum+blockArray[i];
        }

        /// Sum remaining elements
        int firstElement=l;
        /// Last element of block of l
        /// Starting is (l/block_size)*block_size
        int lastElement=((l/block_size)*block_size)+(block_size-1);

        for(int i=firstElement;i<=lastElement;i++)
        {
            sum=sum+v[i];
        }
        return sum;
    }
    else
    {
        int startingBlockNo=(l/block_size)+1;
        int endingBlockNo=(r/block_size)-1;

        int sum=0;
        for(int i=startingBlockNo;i<=endingBlockNo;i++)
        {
            sum=sum+blockArray[i];
        }

        /// Sum remaining elements of l block
        int firstElement=l;
        int lastElement=((l/block_size)*block_size)+(block_size-1);
        for(int i=firstElement;i<=lastElement;i++)
        {
            sum=sum+v[i];
        }

        /// Sum remaining element of r block
        firstElement=(r/block_size)*block_size;
        lastElement=r;
        for(int i=firstElement;i<=lastElement;i++)
        {
            sum=sum+v[i];
        }
        return sum;
    }
}
int main()
{
    /// Input the array

    cout<<"Enter number of elements in array"<<endl;
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    /// Block size
    int block_size=sqrt(n);

    /// Number of blocks
    int number_of_blocks=n/block_size;

    /// Fix the number of blocks (ex n=13)
    if(number_of_blocks*(n/number_of_blocks)!=n)
    {
        number_of_blocks++;
    }

    /// Initialize block array
    vector<int> blockArray(number_of_blocks);

    /// Initialize it's values
    for(int i=0;i<n;i++)
    {
        blockArray[i/block_size]=blockArray[i/block_size]+v[i];
    }

    /// Input the number of queries
    cout<<"Enter the number of queries"<<endl;
    int q;
    cin>>q;

    /// Process the queries
    while(q--)
    {
        cout<<"Enter your choice"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            /// Query the sum from l to r
            cout<<"Enter range l and r"<<endl;
            int l,r;
            cin>>l>>r;
            cout<<query(blockArray,v,l,r)<<endl;
        }
        else
        {
            /// Update the element at index i to val
            cout<<"Enter index and value"<<endl;
            int index,val;
            cin>>index>>val;
            update(blockArray,v,index,val);
        }
    }
}
