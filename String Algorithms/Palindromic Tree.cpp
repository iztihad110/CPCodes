#include<bits/stdc++.h>
using namespace std;
int tree[100010][26],len[100010],link[100010],node,curr;
string s;
void Clear(int n){
    for(int i=0;i<=n;i++){
        len[i]=0;
        link[i]=0;
        for(int j=0;j<26;j++) tree[i][j]=0;
    }
}
void Init(){
    node=2;
    curr=2;
    len[1]=-1;
    len[2]=0;
    link[1]=1;
    link[2]=1;
}
void Extend(int pos){
    while(s[pos-len[curr]-1]!=s[pos]) curr=link[curr];
    int c=s[pos]-'a',x=link[curr];
    while(s[pos-len[x]-1]!=s[pos]) x=link[x];
    if(!tree[curr][c]){
        node++;
        tree[curr][c]=node;
        len[node]=len[curr]+2;
        if(len[node]==1) link[node]=2;
        else link[node]=tree[x][c];
    }
    curr=tree[curr][c];
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>s;
        s='$'+s;
        int n=s.size();
        Clear(n);
        Init();
        for(int i=1;i<s.size();i++) Extend(i);
        cout<<"Case "<<"#"<<t<<": ";
        cout<<node-2<<endl;
    }
}
