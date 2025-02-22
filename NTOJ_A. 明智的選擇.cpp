/*
題目:
https://toj.tfcis.org/oj/pro/432/
*/
#include <bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n,vector<int>(m,0));
    int px,py,bdx,bdy; // 1:信長 -1:fire 0:empty 1000:back door
    cin>>px>>py;
    cin>>bdx>>bdy;
    px--;
    py--;
    bdx--;
    bdy--;
    pair<int,int> p = {px,py};
    int fire;
    cin>>fire;
    vector<vector<int>> vc(fire,vector<int>(2));
    for(int i=0;i<fire;i++){
        cin>>vc[i][0]>>vc[i][1];
        vc[i][0]--;
        vc[i][1]--;
        mp[vc[i][0]][vc[i][1]]=-1;
    }
    mp[px][py]=1;
    mp[bdx][bdy]=1000;
    
    // for(int i=0;i<fire;i++){
    //     cout<<vc[i][0]<<" "<<vc[i][1]<<endl;
    // }
    
    queue<pair<int,int>> q;
    q.push({px,py});
    int flag=0;
    while(!q.empty()){
        pair<int,int> now;
        now = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = now.first+dir[i][0];
            int y = now.second+dir[i][1];
            if( (x>=0 && x<=n-1)&&(y>=0 && y<=m-1) ){
                if(mp[x][y]==0){
                    q.push({x,y});
                    mp[x][y] = mp[now.first][now.second]+1;
                }
                else if(mp[x][y]==1000){ //2147483648
                    flag=1;
                    //cout<<"ewofnewoi"<<endl;
                    break;
                }
            }
        }
        if(flag){
            cout<<"Cool!"<<endl;
            break;
        }
    }
    if(flag==0)cout<<"Harakiri!"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
