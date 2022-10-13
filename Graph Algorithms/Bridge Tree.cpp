#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define endl            "\n"
vector<int>adj[100010];
bool vis[100010];
int start[100010],low[100010],dep[100010],par[100010],timer,up[100010][20];
vector<pair<int,int>>bridges;
int FindPar(int n){
    if(par[n]==n) return par[n];
    par[n]=FindPar(par[n]);
    return par[n];
}
void Merge(int u,int v){
    u=FindPar(u);
    v=FindPar(v);
    if(u!=v) par[v]=u;
}    
void dfs(int s,int p){
    vis[s]=1;
    timer++;
    start[s]=timer;
    low[s]=timer;
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(v==p) continue;
        if(vis[v]){
            low[s]=min(low[s],start[v]);
            continue;
        }
        else{
            dfs(v,s);
            low[s]=min(low[s],low[v]);
            if(low[v]>start[s]) bridges.push_back({s,v});
            else Merge(s,v);
        }
    }

}
void MakeBridgeTree(int n){
    for(int i=1;i<=n;i++) adj[i].clear();
    for(auto p: bridges){
        int u=FindPar(p.first);
        int v=FindPar(p.second);
        if(u!=v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}
void dfs2(int s,int p){
    if(p!=-1) up[s][0]=p;
    for(int i=1;i<=18;i++) up[s][i]=up[up[s][i-1]][i-1];
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(v==p) continue;
        dep[v]=dep[s]+1;
        dfs2(v,s);
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
int GetDistance(int u,int v){
    return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
int Intersect(int lca_ab,int lca_cd,int x,int y){ // x= a or b and y= c or d
    int lca_xy=LCA(x,y);
    if(dep[lca_xy]<dep[lca_ab] || dep[lca_xy]<dep[lca_cd]) return 0;
    int ret=min(dep[lca_xy]-dep[lca_ab],dep[lca_xy]-dep[lca_cd]);
    return ret;
}
int main(){
    FastRead
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) par[i]=i;
    dfs(1,-1);
    MakeBridgeTree(n);
    int root=FindPar(1);
    dfs2(root,-1);
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a=FindPar(a);
        b=FindPar(b);
        c=FindPar(c);
        d=FindPar(d);
        int lca_ab=LCA(a,b);
        int lca_cd=LCA(c,d);
        int ans=GetDistance(c,d);
        ans=ans-(Intersect(lca_ab,lca_cd,a,c)+Intersect(lca_ab,lca_cd,a,d)+Intersect(lca_ab,lca_cd,b,c)+Intersect(lca_ab,lca_cd,b,d));
        cout<<ans<<endl;
    }
}
