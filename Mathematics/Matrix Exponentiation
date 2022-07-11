#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
struct Matrix{
    vector<vector<int>>Mat=vector<vector<int>>(n,vector<int>(n));
    //memset(Mat,0,sizeof(Mat));
    Matrix operator *(const Matrix& other){
        Matrix product;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int temp=((long long)(Mat[i][k]%mod)*((long long)other.Mat[k][j]%mod))%mod;
                    product.Mat[i][j]=(product.Mat[i][j]%mod+temp%mod)%mod; 
                }
            }
        }
        return product;
    }
};
Matrix MatExpo(Matrix a,int p){
    Matrix product;
    for(int i=0;i<n;i++) product.Mat[i][i]=1;
    while(p>0){
        if(p%2) product=product*a;
        p/=2;
        a=a*a;
    }
    return product;
}
int main(){
    int m,k;
    cin>>n>>m>>k;
    Matrix x;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        x.Mat[a-1][b-1]=1;
    }
    Matrix ret=MatExpo(x,k);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) ans=(ans%mod+ret.Mat[i][j]%mod)%mod;
    }
    cout<<ans<<endl;
}
