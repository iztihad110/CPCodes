const long long MAX=200010;
long long arr[MAX],tree[3*MAX];
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
long long query(int node,int b,int e,int i,int j){
    if(j<b || i>e){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    long long q1=query(left,b,mid,i,j);
    long long q2=query(right,mid+1,e,i,j);
    return q1+q2;
}
void update(int node,int b,int e,int i,int val){
    if(i<b || i>e){
        return;
    }
    if(b>=i && e<=i){
        tree[node]=val;
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=tree[left]+tree[right];
}
