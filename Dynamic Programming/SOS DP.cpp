#include<bits/stdc++.h>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define endl            "\n" 
long long dp[(1<<24)+10];
int main(){
    FastRead
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int OR=0;
        for(int j=0;j<3;j++){
            int x=s[j]-'a';
            OR|=(1<<x);
        }
        dp[OR]++;
    }
    for(int i=0;i<24;i++){
        for(int mask=0;mask<(1<<24);mask++){
            if(mask&(1<<i)){
                dp[mask]+=dp[mask^(1<<i)];
            }
        }
    }
    long long ans=0;
    for(int mask=0;mask<(1<<24);mask++){
        int cnt=n-dp[mask];
        ans^=(1LL*cnt*cnt);   
    }
    cout<<ans; 
}
