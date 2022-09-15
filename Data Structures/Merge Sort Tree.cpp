#include<bits/stdc++.h>
using namespace std;
int a[100010],idx[100010],pos[100010];
vector<int>mst[400010];
void build(int node,int b,int e){
    if(b==e){
        mst[node].push_back(idx[b]);
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    build(left,b,mid);
    build(right,mid+1,e);
    int i,j;
    i=j=0;
    while(i<mst[left].size() && j<mst[right].size()){
        if(mst[left][i]<mst[right][j]){
            mst[node].push_back(mst[left][i]);
            i++;
        }
        else{
            mst[node].push_back(mst[right][j]);
            j++;
        }
    }
    while(i<mst[left].size()){
        mst[node].push_back(mst[left][i]);
        i++;
    }
    while(j<mst[right].size()){
        mst[node].push_back(mst[right][j]);
        j++;
    }
}
int query(int node,int b,int e,int l,int r,int val){
    if(l>e || r<b) return 0;
    if(b>=l && e<=r){
        int sz=mst[node].size();
        int ub=upper_bound(mst[node].begin(),mst[node].end(),val)-mst[node].begin();
        return sz-ub;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    int q1=query(left,b,mid,l,r,val);
    int q2=query(right,mid+1,e,l,r,val);
    return q1+q2;
}
