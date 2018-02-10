https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/

https://drive.google.com/open?id=1VtQtDqPPJSiWMAza2n6Gx5OWZqm2ANrY
https://drive.google.com/open?id=1zAIonZjyUbwRIDWIqibxqvtc7cd0mEWN
https://drive.google.com/open?id=1ljNQC_6Qj-sJ1M1uJWNKSly7m6trbmqn
https://drive.google.com/open?id=1g4pJHoo9c5xKicceYw_NuSRu94XGkEMW

#include<bits/stdc++.h>
using namespace std;
bool orientation(pair<int,int> points[],int leftMost,int i,int rightMost)
{
    /// Return true if i lies to right of line joining leftMost and rightMost
    int value=(points[rightMost].second - points[leftMost].second)*(points[i].first - points[rightMost].first) - (points[i].second - points[rightMost].second)*(points[rightMost].first - points[leftMost].first);
    if(value<0)
        return true;
    else
        return false;
}
void convexHull(pair<int,int> points[],int n)
{
    /// Not possible if less than 3 points
    if(n<3)
    {
        /// Minimum 3 points needed
        return;
    }

    /// 1.Select the leftmost point
    int leftMost=0;
    for(int i=1;i<n;i++)
    {
        if(points[i].first<points[leftMost].first)
        {
            leftMost=i;
        }
    }
    int startingPoint=leftMost;
    vector<int> convexHullPoints;
    /// 2. Repeat until rightMost point is leftMost we again reach the starting point
    do
    {
        /// 3. Push leftMost point in convex Hull
        convexHullPoints.push_back(leftMost);

        /// 4. Select a random point as rightMost
        int rightMost=(leftMost+1)%n;

        /// 5. Iterate over all points and see if any point lies to right of line joining leftMost and randomPoint
        for(int i=0;i<n;i++)
        {
            if(orientation(points,leftMost,i,rightMost))
            {
                rightMost=i;
            }
        }
        /// 6. Make this rightMost now as leftMost and search for rightMost point wrt to this
        leftMost=rightMost;

    }while(leftMost!=startingPoint);

    cout<<endl;
    /// 7. Print convex hull
    for(int i=0;i<convexHullPoints.size();i++)
    {
        cout<<points[convexHullPoints[i]].first<<" "<<points[convexHullPoints[i]].second<<endl;
    }
}
int main()
{
    cout<<"Enter the number of points"<<endl;
    int n;
    cin>>n;
    pair<int,int> points[n];
    cout<<"Enter the points"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first;
        cin>>points[i].second;
    }
    convexHull(points,n);
}
