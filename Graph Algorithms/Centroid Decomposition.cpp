#include<bits/stdc++.h>
using namespace std;
set<int>adj[100010];
int up[100010][20],sub[100010],cenTree[100010];
int dep[100010],c,comp,dis[100010];
void dfs(int s,int p){
    if(p!=-1) up[s][0]=p;
    for(int i=1;i<=18;i++) up[s][i]=up[up[s][i-1]][i-1];
    for(auto v: adj[s]){
        if(v==p) continue;
        dep[v]=dep[s]+1;
        dfs(v,s);
    }
}
void dfs2(int s,int p){
    int ret=0;
    for(auto v: adj[s]){
        if(v==p) continue;
        dfs2(v,s);
        ret+=sub[v];
    }
    sub[s]=ret+1;
}
void FindCentroid(int s,int p,int n){
    int mx=0;
    for(auto v: adj[s]){
        if(v==p) continue;
        mx=max(sub[v],mx);
        FindCentroid(v,s,n); 
    }
    mx=max(n-sub[s],mx);
    if(mx<=n/2) c=s;
}
void decompose(int s,int p){
    dfs2(s,-1);
    int n=sub[s];
    FindCentroid(s,-1,n);
    int centroid=c;
    cenTree[centroid]=p;
    for(auto v: adj[centroid]){
        adj[v].erase(centroid);
        decompose(v,centroid);
    }
}
int LCA(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    int d=dep[b]-dep[a];
    for(int i=18;i>=0;i--){
        if(d&(1<<i)) b=up[b][i];
    }
    if(a==b) return a;
    for(int i=18;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
int GetDistance(int a,int b){
    return dep[a]+dep[b]-2*dep[LCA(a,b)];
}
void update(int v){
    int curr=v;
    while(curr!=-1){
        dis[curr]=min(dis[curr],GetDistance(curr,v));
        curr=cenTree[curr];
    }
}
int query(int v){
    int curr=v;
    int ret=1e9+7;
    while(curr!=-1){
        ret=min(ret,dis[curr]+GetDistance(curr,v));
        curr=cenTree[curr];
    }
    return ret;
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs(1,-1);
    decompose(1,-1);
    for(int i=1;i<=n;i++) dis[i]=1e9+7;
    update(1);
    while(q--){
        int type,v;
        cin>>type>>v;
        if(type==1) update(v);
        else cout<<query(v)<<endl;
    }
}
