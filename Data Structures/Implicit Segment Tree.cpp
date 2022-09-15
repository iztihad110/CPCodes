#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long val;
    Node *left,*right;
    Node(long long n){
        val=n;
        left=NULL;
        right=NULL;
    }    
};
struct Implicit_SegTree{
    Node *root;
    Implicit_SegTree(long long n){
        root=new Node(n);
    }
    void Update(Node *node,long long b,long long e,long long idx,long long add){
        if(b==e){
            node->val+=add;
            return;
        }
        long long mid=(b+e)/2;
        if(node->left==NULL) node->left=new Node(mid-b+1);
        if(node->right==NULL) node->right=new Node(e-mid);
        if(idx<=mid) Update(node->left,b,mid,idx,add);
        else Update(node->right,mid+1,e,idx,add);
        node->val=node->left->val+node->right->val;  
    }
    long long query(Node *node,long long b,long long e,long long k){
        if(b==e) return b;
        long long mid=(b+e)/2;
        if(node->left==NULL) node->left=new Node(mid-b+1);
        if(node->right==NULL) node->right=new Node(e-mid);
        if(k<=node->left->val) return query(node->left,b,mid,k);
        else return query(node->right,mid+1,e,k-node->left->val);
    }  
};
