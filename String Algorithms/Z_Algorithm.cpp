int Z[1000010];
void Z_Algo(string s){
    Z[0]=0;
    int n=s.size();
    for(int i=1,L=0,R=0;i<n;i++){
        if(i<R){
            Z[i]=min(Z[i-L],R-i+1);
        }
        else Z[i]=0;
        while(i+Z[i]<n && s[Z[i]]==s[Z[i]+i]){
            Z[i]++;
        }
        if(Z[i]+i-1>R){
            R=Z[i]+i-1;
            L=i;
        }
    }
}
