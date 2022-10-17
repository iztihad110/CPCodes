#include<bits/stdc++.h>
using namespace std;
bool vis[20010];
int grundy[20010];
int FindGrundy(int n){
    memset(vis,0,sizeof(vis));
    if(n==1 || n==2) return 0;
    if(grundy[n]!=-1) return grundy[n];
    int mid=n/2;
    if(n%2==0) mid--;
    for(int i=1;i<=mid;i++){
        int XOR=grundy[i]^grundy[n-i];
        vis[XOR]=1;
    }
    int ret=0;
    for(int i=0;i<=20000;i++){
        if(!vis[i]){
            ret=i;
            break;
        }
    }
    return ret;
}
int main(){
    int T,n;
    memset(grundy,-1,sizeof(grundy));
    for(int i=1;i<=10000;i++) grundy[i]=FindGrundy(i);
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        int XOR=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            XOR^=grundy[x];
        }
        cout<<"Case"<<" "<<t<<": ";
        if(XOR) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}