#include <bits/stdc++.h>
using namespace std;
// 1 代表有水管， 0 則代表沒有。
int dir_1[4][2]={ { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } }; // 下、右、上、左
int main(){
    int s;
    int cnt = 1;
    while(cin>>s){ //若 S = 2  代表水不能往上流， S = 1  代表水可以往上流。
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vc(n,vector<int>(m)); //地圖
        pair<int,int> start; //起點
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>vc[i][j];
                if(i==0 && vc[i][j]==1) start = {i,j}; //找起點
            }
        }
        //BFS
        queue< pair<int,int> > q;
        q.push(start);
        while(!q.empty()){
            // 現在位置
            pair<int,int> now;
            now = q.front();
            //
            q.pop();
            if(s==1){ //可往上
                for(int i=0;i<4;i++){
                    // 層層擴展後的位置
                    int x = now.first+dir_1[i][0];
                    int y = now.second+dir_1[i][1];
                    //
                    pair<int,int> bfs_now = {x,y};
                    if( bfs_now!=start && ( x>=0 && x<=n-1 ) && ( y>=0 && y<=m-1 ) && vc[x][y]==1 ){ //在地圖內且有水管的
                        q.push( {x,y} ); //紀錄層層擴展後可流水的位置
                        vc[x][y] = vc[now.first][now.second]+1; //賦值
                    }
                }
            }
            else{ //不往上
                for(int i=0;i<4;i++){
                    // 層層擴展後的位置
                    int x = now.first+dir_1[i][0];
                    int y = now.second+dir_1[i][1];
                    //
                    pair<int,int> bfs_now = {x,y};
                    if( bfs_now!=start && ( x>=0 && x<=n-1 ) && ( y>=0 && y<=m-1 ) && vc[x][y]==1){
                        if( (dir_1[i][0]==-1 && dir_1[i][1]==0)   ){ //水流不到的地方先不算
                 
                        }
                        else{ //在地圖內且有水管的
                            q.push( {x,y} ); //紀錄層層擴展後可流水的位置
                            vc[x][y] = vc[now.first][now.second]+1; //賦值
                        }
                    }
                }
            }
        }
        //水流不到的地方輸出0
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(vc[i][j]==1)vc[i][j]=0;
            }
        }
        //
        
        //輸出
        cout<<"Case "<<cnt++<<":"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<vc[i][j]<<" ";
            }
            cout<<endl;
        }
        //
    }
    return 0;
}