#include<bits/stdc++.h>
using namespace std;
int start[30010],timer,head[30010],sub[30010];
int par[30010],val[30010],a[30010],dep[30010],n;
long long tree[120010];
vector<int>adj[30010];
void Clear(int n){
    for(int i=1;i<=n;i++){
        start[i]=0;
        head[i]=0;
        sub[i]=0;
        par[i]=0;
        val[i]=0;
        dep[i]=0;
        adj[i].clear();
    }
    for(int i=1;i<=4*n;i++) tree[i]=0;
    timer=0; 
}
void dfs(int s,int p){
    int ret=0,mx=0;
    par[s]=p;
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(v==p) continue;
        dep[v]=dep[s]+1;
        dfs(v,s);
        ret+=sub[v];
        if(sub[v]>mx){
            mx=sub[v];
            swap(adj[s][i],adj[s][0]);
        }
    }
    sub[s]=ret+1;
}
void dfsHLD(int s,int p){
    timer++;
    start[s]=timer;
    val[timer]=a[s];
    if(p!=-1 && adj[p][0]==s) head[s]=head[p];
    else head[s]=s;
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(v==p) continue;
        dfsHLD(v,s);
    }
}
void build(int node,int b,int e){
    if(b==e){
        tree[node]=val[b];
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int idx,int x){
    if(idx<b || idx>e) return;
    if(b==e){
        tree[node]=x;
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,b,mid,idx,x);
    update(right,mid+1,e,idx,x);
    tree[node]=tree[left]+tree[right];
}
long long query(int node,int b,int e,int l,int r){
    if(b>r || e<l) return 0;
    if(b>=l && e<=r) return tree[node];
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    long long q1=query(left,b,mid,l,r);
    long long q2=query(right,mid+1,e,l,r);
    return q1+q2;
}
long long PathProcess(int u,int v){
    long long ret=0;
    while(head[u]!=head[v]){
        if(dep[head[u]]>dep[head[v]]) swap(v,u);
        ret+=query(1,1,n,start[head[v]],start[v]);
        v=par[head[v]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    ret+=query(1,1,n,start[u],start[v]);
    return ret;
}
int main(){
    int T,q;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n;
        Clear(n);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            a++;
            b++;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        dfsHLD(1,-1);
        cin>>q;
        build(1,1,n);
        cout<<"Case"<<" "<<t<<":"<<endl;
        while(q--){
            int type,u,v;
            cin>>type>>u>>v;
            if(type==0) cout<<PathProcess(u+1,v+1)<<endl;
            else update(1,1,n,start[u+1],v);
        }
    }
}
