#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

//dir
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//

int main() {
	int n;
    cin>>n;
    vector<vector<int>> vc(n,vector<int>(n));
    int min_v = 9999999;
    int max_v = -111111111;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vc[i][j];
            min_v = min(min_v,vc[i][j]);
            max_v = max(max_v,vc[i][j]);
        }
    }

    int l = min_v , r = max_v;
    
    int ans;
    while(r>l+1){
        vector<vector<int>> dis(n,vector<int>(n,-1));
        int mid = l+((r-l)/2);
        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0] = 0;
        while(q.size()){
            pair<int,int> now;
            now = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = now.f + dir[i][0];
                int y = now.s + dir[i][1];
                if( (x>=0 && x<n) && (y>=0 && y<n) && dis[x][y]==-1 ){
                    if(abs(vc[now.f][now.s]-vc[x][y])<=mid){
                        dis[x][y] = dis[now.f][now.s]+1;
                        q.push({x,y});
                    }
                }
            }
       }
       if(dis[n-1][n-1]==-1){
           l = mid;
       }
       else {
           r = mid;
           ans = dis[n-1][n-1];
       }
    }
    cout<<r<<endl<<ans;
	return 0;
}