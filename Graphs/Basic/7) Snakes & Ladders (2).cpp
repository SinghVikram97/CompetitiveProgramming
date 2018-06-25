https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

#include<bits/stdc++.h>
using namespace std;
map<int,list<int> > adjList;
void addEdge(int v1,int v2){
    adjList[v1].push_back(v2);
}
int Bfs(int startingVertex){
    
    map<int,int> isVisited;  // Instead of storing true or false store distance. Everything else is same.
    for(auto it=adjList.begin();it!=adjList.end();it++){
        
        isVisited[it->first]=-1;
        
    }
    queue<int> q;
    q.push(startingVertex);
    isVisited[startingVertex]=0;
    
    while(!q.empty()){
        
        int frontElement=q.front();
        q.pop();
        
        for(auto it=adjList[frontElement].begin();it!=adjList[frontElement].end();it++){
            
            if(isVisited[(*it)]==-1){
                
                q.push(*it);
                isVisited[(*it)]=isVisited[frontElement]+1;
            }
        }
    }
    return isVisited[(30)];
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        
        // cout<<adjList.size()<<endl;
        
        int board[50]={0};
        
        for(int i=0;i<n;i++){
            
            int a,b;
            cin>>a>>b;
            board[a]=b-a;  // Ex. if 11 4 given store board[11]=-7 so if edge b/w 10 and 11. add edge 10,11+board[11]=11-7=4
        }
        
        for(int i=1;i<=30;i++){
            for(int j=1;j<=6;j++){
                addEdge(i,i+j+board[i+j]);
            }
        }
        
        cout<<Bfs(1)<<endl;
        
        adjList.clear();
    }
}
