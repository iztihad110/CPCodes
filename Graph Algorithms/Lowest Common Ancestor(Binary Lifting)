#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define endl            "\n"
vector<int>adj[100010];
int a[100010],up[100010][20],dep[100010];
void Clear(int n){
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dep[i]=0;
        for(int j=0;j<20;j++) up[i][j]=0;
    }
}
void dfs(int s,int p){
    if(p!=-1) up[s][0]=p;
    for(int i=1;i<=18;i++) up[s][i]=up[up[s][i-1]][i-1];
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(v==p) continue;
        dep[v]=dep[s]+1;
        dfs(v,s);
    }
}
int LCA(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    int d=dep[v]-dep[u];
    for(int i=18;i>=0;i--){
        if(d&(1<<i)) v=up[v][i];
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
