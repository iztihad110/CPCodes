void Manacher(int n,string s){
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r) ? 1:min(d1[l+r-i],r-i+1);
        while(0<=i-k && i+k<n && s[i-k]==s[i+k]) {
           k++;
        }
        d1[i]=k--;
        if(i+k>r) {
            l=i-k;
            r=i+k;
        }
    }
}
