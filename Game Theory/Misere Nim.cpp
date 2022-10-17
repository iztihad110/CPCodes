#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int k,cnt=0;
        cin>>k;
        long long XOR=0;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            XOR^=x;
            if(x==1) cnt++;
        }
        cout<<"Case"<<" "<<t<<": ";
        if(cnt==k){
            if(cnt%2) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else{
            if(XOR) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
}
