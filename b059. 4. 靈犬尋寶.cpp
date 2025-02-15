#include <bits/stdc++.h>
using namespace std;

bool in(int x,int y){ //計算有無超出邊界
    return ((x>=0 && x<=99)&&(y>=0 && y<=99));
}
                    //0     1      2       3      4     5      6      7
int m[8][2]={ {3,1},{3,-1},{-3,1},{-3,-1},{-1,3},{1,3},{-1,-3},{1,-3}};
int check[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
int main(){
    int n; //障礙物數量
    while(cin>>n){
        //格網
        vector<vector<int>> mp(100,vector<int>(100,0));
        //
        //障礙物:-1
        int obs[n][2];
        for(int i=0;i<n;i++){
            cin>>obs[i][0]>>obs[i][1];
            mp[obs[i][0]][obs[i][1]] = -1;
        }
        //

        //靈犬:1
        int dx,dy;
        cin>>dx>>dy;
        mp[dx][dy] = 1;
        //

        //寶物:1000
        int tx,ty;
        cin>>tx>>ty;
        mp[tx][ty] = 1000;
        //

        
        
        //BFS
        queue< pair<int,int> > q;
        q.push({dx,dy});
        int flag = 0;
        while(!q.empty()){
            pair<int,int> now;
            now = q.front();
            q.pop();
            int index = 0;
            for(int i=0;i<4;i++){
                int x = now.first+check[i][0];
                int y = now.second+check[i][1];
                int cnt = 2;
                if( in(x,y) && mp[x][y]==0 ){ //now前無障礙物
                    while(cnt!=0){
                        int c = now.first+m[index][0];
                        int d = now.second+m[index][1];
                        if(in(c,d)){
                            if(mp[c][d]==0){
                                q.push({c,d});
                                mp[c][d] = mp[now.first][now.second]+1;
                            }
                            else if (mp[c][d]==1000){
                                flag=1;
                                mp[c][d] = mp[now.first][now.second]+1;
                                cout<<mp[c][d]-1<<endl;
                                break;
                            }
                        }
                        index++;
                        cnt--;
                    }
                    
                    if(flag)break;
                }
                else{
                    index+=2;
                }
            }
            if(flag)break;
        }
        if(!flag)cout<<"impossible"<<endl;
        //
        // for(int i=0;i<101;i++){
        //     for(int j=0;j<101;j++){
        //         cout<<mp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}