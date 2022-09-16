#include<bits/stdc++.h>
using namespace std;
vector<int> SortCyclicShifts(string s){
    int n=s.size();
    const int alphabet=256;
    vector<int>Start(n),Freq(max(alphabet,n),0),EClass(n);
    for(int i=0;i<n;i++) Freq[s[i]]++;
    for(int i=1;i<alphabet;i++) Freq[i]+=Freq[i-1];
    for(int i=0;i<n;i++) Start[--Freq[s[i]]]=i;
    int Class=1;
    EClass[Start[0]]=0;
    for(int i=1;i<n;i++){
        if(s[Start[i]]!=s[Start[i-1]]) Class++;
        EClass[Start[i]]=Class-1;
    }
    for(int p=0;(1<<p)<n;p++){
        vector<int> STemp(n),ECTemp(n);
        for(int i=0;i<n;i++){
            STemp[i]=Start[i]-(1<<p);
            if(STemp[i]<0) STemp[i]+=n;
        }
        fill(Freq.begin(),Freq.begin()+Class,0);
        for(int i=0;i<n;i++) Freq[EClass[STemp[i]]]++;
        for(int i=1;i<Class;i++) Freq[i]+=Freq[i-1];
        for(int i=n-1;i>=0;i--){
            Start[--Freq[EClass[STemp[i]]]]=STemp[i];
        }
        ECTemp[Start[0]]=0;
        Class=1;
        for(int i=1;i<n;i++){
            pair<int,int>prev,curr;
            prev={EClass[Start[i-1]],EClass[(Start[i-1]+(1<<p))%n]};
            curr={EClass[Start[i]],EClass[(Start[i]+(1<<p))%n]};
            if(curr!=prev) Class++;
            ECTemp[Start[i]]=Class-1;
        }
        for(int i=0;i<n;i++){
            EClass[Start[i]]=ECTemp[Start[i]];
        }
    }
    return Start;
}
vector<int> BuildSuffixArray(string s){
    s+='$';
    vector<int>ret=SortCyclicShifts(s);
    ret.erase(ret.begin());
    return ret;
}
vector<int>BuildLCPArray(string s,vector<int>&v){
    int n=s.size();
    vector<int>rank(n),lcp(n-1,0);
    for(int i=0;i<n;i++) rank[v[i]]=i; 
    int k=0;
    for(int i=0;i<n;i++){
        if(rank[i]==n-1){
            k=0;
            continue;
        }
        int j=v[rank[i]+1];
        while (i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;    
    }
    return lcp;
}
int main(){
    string s;
    cin>>s;
    vector<int>SuffixArray=BuildSuffixArray(s);
    for(int i=0;i<SuffixArray.size();i++){
        cout<<SuffixArray[i]<<" "; 
    }
    cout<<endl;
    vector<int>LCP=BuildLCPArray(s,SuffixArray);
    for(int i=0;i<LCP.size();i++) cout<<LCP[i]<<" ";
}
