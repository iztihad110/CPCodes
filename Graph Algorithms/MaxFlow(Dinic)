#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,rev,flow,cap;    
};
const int MaxNodes=10010;
int src,sink,lev[MaxNodes],Work[MaxNodes];
vector<edge>adj[MaxNodes];
void AddEdge(int u,int v,int c){
    edge f={v,(int)adj[v].size(),0,c};
    edge r={u,(int)adj[u].size(),0,0};
    adj[u].push_back(f);
    adj[v].push_back(r);
}
bool Dinic_bfs(){
    memset(lev,-1,sizeof(lev));
    lev[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            edge &v=adj[u][i];
            if(lev[v.to]<0 && v.flow<v.cap){
                lev[v.to]=lev[u]+1;
                q.push(v.to);
            }
        }
    }
    return lev[sink]>=0;
}
int Dinic_dfs(int s,int Totalflow){
    if(s==sink) return Totalflow;
    for(int &i=Work[s];i<adj[s].size();i++){
        edge &e=adj[s][i];
        if(e.cap<=e.flow) continue;
        if(lev[e.to]==lev[s]+1){
            int Flow=Dinic_dfs(e.to,min(Totalflow,e.cap-e.flow));
            if(Flow>0){
                e.flow+=Flow;
                adj[e.to][e.rev].flow-=Flow;
                return Flow;
            }
        }
    }
    return 0;
}
int MaxFlow(){
    int ret=0;
    while(Dinic_bfs()){
        memset(Work,0,sizeof(Work));
        while(1){
            int ret2=Dinic_dfs(src,1e9+7);
            if(ret2==0) break;
            ret+=ret2;
        } 
    }
    return ret;
}
int main(){
    int n,m;
    cin>>n>>src>>sink>>m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        AddEdge(u,v,c);
        AddEdge(v,u,c); //If Bidirectional
    }
    cout<<MaxFlow()<<endl;
}
