long long tree[800010],Lazy[800010],a[200010];
void build(int node,int b,int e){
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
void update(int node,int b,int e,int x,int y,long long val){
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    tree[node]+=Lazy[node];
    if(Lazy[node]!=0){
        if(e>b){
            Lazy[left]+=Lazy[node];
            Lazy[right]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(y<b || x>e) return;
    if(b>=x && e<=y){
        tree[node]+=val;
        if(e>b){
            Lazy[left]+=val;
            Lazy[right]+=val;
        }
        return;
    }
    update(left,b,mid,x,y,val);
    update(right,mid+1,e,x,y,val);
    tree[node]=min(tree[left],tree[right]);
}
long long query(int node,int b,int e,int x,int y){
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    tree[node]+=Lazy[node];
    if(Lazy[node]!=0){
        if(e>b){
            Lazy[left]+=Lazy[node];
            Lazy[right]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(y<b || x>e) return INT_MAX;
    if(b>=x && e<=y) return tree[node];
    long long q1=query(left,b,mid,x,y);
    long long q2=query(right,mid+1,e,x,y);
    return min(q1,q2);
}
