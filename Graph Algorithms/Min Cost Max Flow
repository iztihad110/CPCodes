#include<bits/stdc++.h>
using namespace std;
int a[52],b[52];
struct edge{
    int v,rev;
    int cap,cost,flow;
    edge(){}
    edge(int v, int rev, int cap, int cost) : v(v),rev(rev),cap(cap),cost(cost),flow(0){}
};

struct mcmf{
    int src, sink, nodes;
    const int inf = 1e9;
    vector<int> par, idx;
    vector<bool> inq;
    vector<int> dis;
    vector<vector<edge>> g;

    mcmf(){}
    mcmf(int src, int sink, int nodes) :
     src(src), sink(sink), nodes(nodes),
     par(nodes), idx(nodes), inq(nodes),
     dis(nodes), g(nodes){}

    void addEdge(int u,int v,int cap,int cost,bool directed = true){
        edge _u=edge(v,g[v].size(),cap,cost);
        edge _v=edge(u,g[u].size(),0,-cost);
        g[u].push_back(_u);
        g[v].push_back(_v);
        if(!directed) addEdge(v,u,cap,cost,true);
    }

    bool spfa(){
        for(int i = 0; i <nodes; i++){
            dis[i]=inf, inq[i]=false;
        }

        queue<int>q;
        q.push(src);
        dis[src]=0, par[src]=-1, inq[src]=true;
        while(!q.empty()){
            int u=q.front(); q.pop();
            inq[u]=false;
            for(int i=0;i<g[u].size();i++){
                edge &e=g[u][i];
                if(e.cap<=e.flow) continue;
                if(dis[e.v]>dis[u]+e.cost){
                    dis[e.v]=dis[u]+e.cost;
                    par[e.v]=u, idx[e.v]=i;
                    if(!inq[e.v]) inq[e.v]=true,q.push(e.v);
                }
            }
        }

        return (dis[sink]!=inf);
    }

    pair<int,int> solve(){
        int mincost=0,maxflow=0;
        while(spfa()){
            int bottleneck = inf;
            for(int u=par[sink],v=idx[sink];u!=-1;v=idx[u],u=par[u]){
                edge &e = g[u][v];
                bottleneck=min(bottleneck,e.cap-e.flow);
            }

            for(int u =par[sink],v=idx[sink];u!=-1;v=idx[u],u=par[u]){
                edge &e=g[u][v];
                e.flow+=bottleneck;
                g[e.v][e.rev].flow-=bottleneck;
            }

            mincost+=bottleneck*dis[sink],maxflow+=bottleneck;
        }

        return make_pair(mincost, maxflow);
    }
};
int main(){
    int T,n;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        mcmf Flow(0,2*n+1,2*n+2);
        for(int i=1;i<=n;i++){
            Flow.addEdge(0,i,1,0);
            Flow.addEdge(i+n,2*n+1,1,0);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]>b[j]){
                    Flow.addEdge(i,j+n,1,-2);
                }
                else if(a[i]==b[j]){
                    Flow.addEdge(i,j+n,1,-1);
                }
                else Flow.addEdge(i,j+n,1,0);

            }
        }
        cout<<"Case"<<" "<<t<<": ";
        cout<<-Flow.solve().first<<endl;
    }
}
