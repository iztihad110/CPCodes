#include<bits/stdc++.h>
using namespace std;
int cap[110][110],par[110];
vector<int>adj[110];
void Clear(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            cap[i][j]=0;
        }
        par[i]=0;
        adj[i].clear();
    }
}
int bfs(int s,int t){
    memset(par,-1,sizeof(par));
    par[s]=-2;
    queue<pair<int,int>>q;
    q.push({s,1e9+7});
    while(!q.empty()){
        int curr=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            int v=adj[curr][i];
            if(par[v]==-1 && cap[curr][v]){
                int newflow=min(flow,cap[curr][v]);
                par[v]=curr;
                if(v==t) return newflow;
                q.push({v,newflow});
            }
        }
    }
    return 0;
}
int MaxFlow(int s,int t){
    int TotalFlow=0;
    while(1){
        int newflow=bfs(s,t);
        if(newflow==0) break;
        int curr=t;
        TotalFlow+=newflow;
        while(curr!=s){
            int prev=par[curr];
            cap[prev][curr]-=newflow;
            cap[curr][prev]+=newflow;
            curr=prev;
        }
    }
    return TotalFlow; 
}
