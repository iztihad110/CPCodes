#include<bits/stdc++.h>
using namespace std;
struct point {
    int x,y;
    point(){}
    point(int a,int b){x=a,y=b;}
};
inline int crossproduct(point a , point b , point p ){
    return ((a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x)) ;
}
bool PIP(vector<point>p ,point sample , int n ){
    bool f = 0 ,cnt=0;
    for( int i = 0 , j = n-1 ; i < n ; j = i++ ){
        f=0;
        int xmin=min(p[i].x,p[j].x) ;
        int xmax=max(p[i].x,p[j].x) ;

        int ymin=min(p[i].y,p[j].y) ;
        int ymax =max(p[i].y,p[j].y) ;

        if(xmin<=sample.x && sample.x<=xmax && ymin<=sample.y && sample.y<=ymax){
            if(crossproduct(p[i],p[j],sample)==0)return true ;
        }
        if( crossproduct(p[i], p[j], sample)<0){
            f=1 ;
        }

        if(!f && p[i].y>=sample.y && p[j].y<sample.y)cnt=!cnt ;
        else if(f && p[j].y>=sample.y && p[i].y<sample.y){cnt=!cnt;}
    }
    return cnt ;
}
int main(){
    int T,n;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,q;
        cin>>n;
        vector<point>points;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            point pt;
            pt.x=x;
            pt.y=y;
            points.push_back(pt);
        }
        cin>>q;
        cout<<"Case "<<t<<":"<<endl;
        while(q--){
            int x,y;
            cin>>x>>y;
            point pt;
            pt.x=x;
            pt.y=y;
            if(PIP(points,pt,n)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }
}
