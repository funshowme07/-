#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
//direction
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//

bool cmp(pair<char,int> a,pair<char,int> b){
    if(a.s==b.s){
        return a.f<b.f;
    }
    return a.s>b.s;
}

int main() {
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int h,w;
        cin>>h>>w;
        vector<string> vc(h);
        for(int j=0;j<h;j++){
            cin>>vc[j];
        }
        //bfs
        queue<pair<int,int>> q;
        unordered_map<char,int> mp;
        vector< pair<char,int> > abc;
        char c;
        for(int p=0;p<h;p++){
            for(int l=0;l<w;l++){
                if(vc[p][l]!='@'){
                    q.push({p,l});
                    c = vc[p][l];
                    mp[c]++;
                    vc[p][l] = '@';
                }
                while(! q.empty()){
                    
                    pair<int,int> now;
                    now = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int x = now.f + dir[k][0];
                        int y = now.s + dir[k][1];
                        if( (x>=0 && x<h) && (y>=0 && y<w) && vc[x][y]==c ){
                                q.push({x,y});
                                vc[x][y]='@';
                        }
                    }
                }
            }
        }
        //
        cout<<"World #"<<i+1<<endl;
        for(auto h : mp){
            abc.push_back({h.f,h.s});
        }
        sort(abc.begin(),abc.end(),cmp);
        for(auto k:abc ){
            cout<<k.f<<": "<<k.s<<endl;
        }
    }
	return 0;
}