#include <bits/stdc++.h>
using namespace std;

int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};

int main() {
    int cnt;
    cin>>cnt;
    while(cnt--){
        int N,M,s1,s2,e1,e2;
        cin>>N>>M>>s1>>s2>>e1>>e2;
        s1--;
        s2--;
        e1--;
        e2--;
        int mp[N][M],a[N][M]; 
        memset(a,0, sizeof(a));//mp:地圖, a:紀錄最短距離以及是否走過
        string str;
        for(int i=0;i<N;i++){
            cin>>str; 
            for(int j=0;j<M;j++){
                mp[i][j]= str[j]-'0';
            }
        }
        
        queue<pair<int,int>>q;
        q.push(make_pair(s1,s2)); //q.push({s1,s2});
        a[s1][s2]=1;

        while( !q.empty() ){
            pair<int,int> now;
            now = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = now.first+dx[i];
                int ny = now.second+dy[i];
                if(0<=nx && nx<N && ny>=0 && ny<M){
                    if( mp[nx][ny]!=1 && a[nx][ny]==0 ){//地圖不是障礙物 和 a沒有走過)
                        q.push({nx,ny});
                        a[nx][ny] = a[now.first][now.second]+1;
                    }
                }

            }
        }
        
       cout<<a[e1][e2]<<endl;
    }
	return 0;
}
