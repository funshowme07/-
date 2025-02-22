#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n;
//direction
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//

bool in(int x,int y){
    return ((x>=0 && x<n) && (y>=0 && y<n));
}

int main(){
    cin>>n;
    //land
    vector<vector<int>> mp(n,vector<int>(n));
    vector<vector<int>> mp_n(n,vector<int>(n));
    //
    int s1,s2;
    cin>>s1>>s2;
    pair<int,int> start;
    start = { s1 , s2 } ;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mp[i][j];
    mp_n = mp;
    int ans = 1;
    //bfs
    queue<pair<int,int>> q;
    q.push(start);
    mp[start.f][start.s] = -1;
    while(!q.empty()){
        pair<int,int> now;
        now = q.front();
        q.pop();
        int now_v = mp_n[now.f][now.s];
        for(int i=0;i<4;i++){
            int x = now.f+dir[i][0];
            int y = now.s+dir[i][1];
            if( in(x,y) ){
                int move_v = mp[x][y];
                if(  mp[x][y]!=-1 && abs( now_v-move_v )<=2 ){
                    q.push( { x , y } );
                    mp[x][y] = -1;
                    ans++;
                }
            }
        }
        // cout<<endl;
        // cout<<ans<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<mp[i][j]<<" ";   
        //     }
        //     cout<<endl;
        // }
    }
    //
    cout<<ans;
    return 0;
}
