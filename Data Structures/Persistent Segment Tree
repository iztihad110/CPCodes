#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
};
int a[100010];
Node* version[100010];
Node* build(int b,int e){
    Node* newcurr=new Node;
    if(b==e){
        newcurr->val=a[b];
        newcurr->left=NULL;
        newcurr->right=NULL;
        return newcurr; 
    }
    int mid=(b+e)/2;
    newcurr->left=build(b,mid);
    newcurr->right=build(mid+1,e);
    newcurr->val=newcurr->left->val+newcurr->right->val;
    return newcurr;
}
Node* update(Node* curr,int b,int e,int x,int num){
    Node* newcurr=new Node;
    if(b==e){
        newcurr->val=curr->val+num;
        newcurr->left=NULL;
        newcurr->right=NULL;
        return newcurr;   
    } 
    int mid=(b+e)/2;
    if(x<=mid){
        newcurr->left=update(curr->left,b,mid,x,num);
        newcurr->right=curr->right;
    }
    else{
        newcurr->left=curr->left;
        newcurr->right=update(curr->right,mid+1,e,x,num);
    }
    newcurr->val=newcurr->left->val+newcurr->right->val;
    return newcurr;
}
int query(Node* curr,int b,int e,int l,int r){
    if(b>r || e<l) return 0;
    if(b>=l && e<=r) return curr->val;
    int mid=(b+e)/2;
    int q1=query(curr->left,b,mid,l,r);
    int q2=query(curr->right,mid+1,e,l,r);
    return q1+q2;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int q;
    version[0]=build(1,n);    
    cin>>q;
    int cnt=0;
    for(int i=0;i<q;i++){
        int type,ver,l,r,num;
        cin>>type;
        if(type==1){
            cin>>ver>>l>>num;
            cnt++;
            version[cnt]=version[ver];
            version[cnt]=update(version[cnt],1,n,l,num);
        }
        else{
            cin>>ver>>l>>r;
            cout<<query(version[ver],1,n,l,r)<<endl; 
        }
    }
}
