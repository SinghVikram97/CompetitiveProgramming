https://www.youtube.com/watch?v=yCQN096CwWM

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int row,column;
  cin>>row>>column;
  vector<vector<int> > mat(row,vector<int>(column));
  for(int i=0;i<row;i++)
  {
     for(int j=0;j<column;j++)
     {
       cin>>mat[i][j];
     }
  }
  vector<int> temp(row);
  int left,right,max_left,max_right,max_up,max_down,total_max_sum=INT_MIN,cur_max_sum,cur_sum;
  for(int left=0;left<column;left++)
  {
      /// Initiazlize all elements of temp to 0
      for(int i_temp=0;i_temp<row;i_temp++)
      {
        temp[i_temp]=0;
      }
     for(int right=left;right<column;right++)
     {
          /// Add elements of right column to temp array
          for(int i=0;i<row;i++)
          {
             temp[i]=temp[i]+mat[i][right];
          }
          /// Update cur_sum by finding max_sum in temp array
          int start,end;
          cur_max_sum=INT_MIN;
          cur_sum=0;
          for(int i=0;i<row;i++)
          {
             /// 2 options either expand subarray or start afresh
             /// If cur_sum -ve or 0 no use of expanding
              if(cur_sum<=0)
              {
                cur_sum=temp[i];
                start=i;
              }
              else
              {
                cur_sum=cur_sum+temp[i];
              }
              if(cur_sum>cur_max_sum)
              {
                cur_max_sum=cur_sum;
                end=i;
              }
          }
          /// Compare current max sum with total max sum
          if(cur_max_sum>total_max_sum)
          {
             /// Update all
             total_max_sum=cur_max_sum;
             max_left=left;
             max_right=right;
             max_up=start;
             max_down=end;
          }
     }
  }
  cout<<total_max_sum;
}
