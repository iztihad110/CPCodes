int trie[260010][26],fail[260010],freq[260010],node,pos[260010];
void Clear(){
    for(int i=0;i<260000;i++){
        for(int j=0;j<26;j++) trie[i][j]=0;
        freq[i]=0;
        fail[i]=0;
        pos[i]=0;
    }
    node=0;
}
int Insert(string s){
    int curr=0;
    for(int i=0;i<s.size();i++){
        int letter=s[i]-'a';
        if(!trie[curr][letter]){
            node++;
            trie[curr][letter]=node;
        }
        curr=trie[curr][letter];
    }
    return curr;
}
void bfs(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            int v=trie[u][i];
            if(v==0) continue;
            q.push(v);
            int f=fail[u];
            while(f && trie[f][i]==0) f=fail[f];
            fail[v]=trie[f][i];
        }
    }
}
void Aho_Corasick(string s){
    bfs();
    int curr=0;
    for(int i=0;i<s.size();i++){
        int letter=s[i]-'a';
        while(curr && trie[curr][letter]==0) curr=fail[curr];
        curr=trie[curr][letter];
        int temp=curr;
        while(temp>0){
            freq[temp]++;
            temp=fail[temp];
        }
    }
}
