#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define endl            "\n"
const int N=500010;  
struct Node{
    int val,left,right;
};
int a[500010],cnt=0,versions[500010];
Node tree[25*N+15];
int build(int b,int e){
    cnt++;
    int curr=cnt;
    if(b==e){
        tree[curr].val=1e9+7;
        return curr;
    }
    int mid=(b+e)/2;
    tree[curr].left=build(b,mid);
    tree[curr].right=build(mid+1,e);
    tree[curr].val=min(tree[tree[curr].left].val,tree[tree[curr].right].val);
    return curr;
}
int update(int prev,int b,int e,int idx,int x){
    cnt++;
    int curr=cnt;
    if(b==e){
        tree[curr].val=x;
        return curr;
    }
    int mid=(b+e)/2;
    if(idx<=mid){
        tree[curr].left=update(tree[prev].left,b,mid,idx,x);
        tree[curr].right=tree[prev].right;
    }
    else{
        tree[curr].left=tree[prev].left;
        tree[curr].right=update(tree[prev].right,mid+1,e,idx,x);
    }
    tree[curr].val=min(tree[tree[curr].left].val,tree[tree[curr].right].val);
    return curr;
}
int query(int curr,int b,int e,int l,int r){
    if(e<l || b>r) return 1e9+7;
    if(b>=l && e<=r) return tree[curr].val;
    int mid=(b+e)/2;
    int q1=query(tree[curr].left,b,mid,l,r);
    int q2=query(tree[curr].right,mid+1,e,l,r);
    return min(q1,q2);
}
int main(){
    FastRead
    int n,m;
    cin>>n>>m;
    map<int,int>last;
    versions[0]=build(1,n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!last[a[i]]) versions[i]=versions[i-1];
        else versions[i]=update(versions[i-1],1,n,last[a[i]],i-last[a[i]]);
        last[a[i]]=i; 
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        int ans=query(versions[r],1,n,l,r);
        if(ans==1e9+7) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
