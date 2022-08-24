#include<bits/stdc++.h>
using namespace std;
int k,last,node,ord;
struct state{
    int len,link;
    map<int,int>next;    
};
state Automata[200010];
int freq[200010];
vector<pair<int,int>>nodes;
string ans;
void Init(){
    last=node=Automata[0].len=0;
    Automata[0].link=-1;    
}
void Insert(int c){
    node++;
    int curr=node;
    Automata[curr].len=Automata[last].len+1;
    int p;
    p=last;
    while(p!=-1 && !Automata[p].next.count(c)){
        Automata[p].next[c]=curr;
        p=Automata[p].link;
    }
    if(p==-1) Automata[curr].link=0;
    else{
        int q=Automata[p].next[c];
        if(Automata[p].len+1==Automata[q].len) Automata[curr].link=q;
        else{
            node++;
            int clone=node;
            Automata[clone].len=Automata[p].len+1;
            Automata[clone].next=Automata[q].next;
            Automata[clone].link=Automata[q].link;
            while(p!=-1 && Automata[p].next[c]==q){
                Automata[p].next[c]=clone;
                p=Automata[p].link;
            }
            Automata[q].link=Automata[curr].link=clone;
            nodes.push_back({Automata[clone].len,clone});
        }
    }
    nodes.push_back({Automata[curr].len,curr});
    freq[curr]++;
    last=curr;
}
void KLEX(int vertex){
    for(int i=0;i<26;i++){
        if(Automata[vertex].next.count(i)){
            ord+=freq[Automata[vertex].next[i]];
            if(ord>=k){
                ans+=char(i+'a');
                return;
            }
            KLEX(Automata[vertex].next[i]);
            if(ord>=k){
                ans+=char(i+'a');
                return;
            }
        }
    }
}
int main(){
    string s;
    cin>>s>>k;
    Init();
    for(int i=0;i<s.size();i++){
        Insert(s[i]-'a');
    }
    sort(nodes.begin(),nodes.end());
    reverse(nodes.begin(),nodes.end());
    for(int i=0;i<nodes.size();i++) freq[Automata[nodes[i].second].link]+=freq[nodes[i].second];
    //for(int i=0;i<nodes.size();i++) cout<<freq[nodes[i].second]<<" ";
    KLEX(0);
    reverse(ans.begin(),ans.end());
    if(ans.size()==0) cout<<"No such line.";
    else cout<<ans<<endl;
}
