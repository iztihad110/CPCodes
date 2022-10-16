#include<bits/stdc++.h>
using namespace std;
struct pt {
    double x, y;
};
vector<pt>ans;
int orientation(pt a, pt b, pt c) {
    double v=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if(v<0) return -1; // clockwise
    if(v>0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a,pt b,pt c,bool include_collinear) {
    int o=orientation(a, b, c);
    return o<0||(include_collinear && o==0);
}
bool collinear(pt a,pt b,pt c) { return orientation(a, b, c) == 0; }

vector<pt> convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x)+(p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x)+(p0.y-b.y)*(p0.y-b.y);
        return o<0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i=0;i<(int)a.size();i++) {
        while (st.size()>1 && !cw(st[st.size()-2],st.back(),a[i],include_collinear)) st.pop_back();
        st.push_back(a[i]);
    }
    return st;
}
int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0) break;
        vector<pt>v;
        map<pair<int,int>,bool>mark;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            pt point;
            point.x=x;
            point.y=y;
            if(!mark[{x,y}]){
                v.push_back(point);
                mark[{x,y}]=1;
            }
        }
        
        vector<pt>ans=convex_hull(v);
        cout<<ans.size()<<endl;
        cout<<ans[0].x<<" "<<ans[0].y<<endl;
        for(int i=(int)ans.size()-1;i>0;i--) cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
}