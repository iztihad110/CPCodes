#include<bits/stdc++.h>
using namespace std;
long long curr,cnt[1000010],a[200010],ans[200010];
struct query{
    int left,right,idx,Size;
    bool operator <(query other){
        return make_pair(left/Size,right)<make_pair(other.left/Size,other.right);
    } 
};
query Q[200010];
void Add(int idx){
    curr-=(cnt[a[idx]]*cnt[a[idx]]*a[idx]);
    cnt[a[idx]]++;
    curr+=(cnt[a[idx]]*cnt[a[idx]]*a[idx]);
}
void Delete(int idx){
    curr-=(cnt[a[idx]]*cnt[a[idx]]*a[idx]);
    cnt[a[idx]]--;
    curr+=(cnt[a[idx]]*cnt[a[idx]]*a[idx]); 
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int Left=1,Right=0;
    int sz=sqrt(n);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        Q[i].left=l;
        Q[i].right=r;
        Q[i].Size=sz;
        Q[i].idx=i;
    }
    sort(Q,Q+q);
    for(int i=0;i<q;i++){
        while(Right<Q[i].right){
            Right++;
            Add(Right);
        }
        while(Left>Q[i].left){
            Left--;
            Add(Left);
        }
        while(Left<Q[i].left){
            Delete(Left);
            Left++;
        }
        while(Right>Q[i].right){
            Delete(Right);
            Right--;
        }
        ans[Q[i].idx]=curr;
        
    } 
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}
