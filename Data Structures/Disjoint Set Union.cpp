int FindPar(int n){
    if(par[n]==n) return n;
    par[n]=FindPar(par[n]);
    return par[n];
}
void Merge(int u,int v){
    u=FindPar(u);
    v=FindPar(v);
    if(u!=v) par[v]=u;
}
