#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
// direction
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
//
int n,m;
vector<vector<int>> vc; // the matrix
vector<vector<int>> vc_n; // visited or never visited

// checking bounds
bool in(int x,int y){
    return ((x>=0 && x<n) && (y>=0 && y<m));
}
//

// bfs
int bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    vc_n[x][y] = -1;
    int sum = 0;
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        sum += vc[now.f][now.s];
        for(int i=0; i<4; i++){
            int c = now.f + dir[i][0];
            int d = now.s + dir[i][1];
            if( in(c,d) && abs(x-c) + abs(y-d) <= vc[x][y] && vc_n[c][d] != -1 ){
                q.push({c,d});
                vc_n[c][d] = -1;
            }
        }
    }
    return sum % 10;
}
//

int main(){
    scanf("%d %d", &n, &m);
    vc.resize(n, vector<int>(m));
    vc_n.resize(n, vector<int>(m));
    for(int i=0; i<n; i++)for(int j=0; j<m; j++)scanf("%d", &vc[i][j]);
    vc_n = vc;
    set<pair<int,int>> S; // sort
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int b = bfs(i,j);
            if(b == vc[i][j]){
                S.insert({i,j});    
            }
            vc_n = vc; // reset the matrix to never visit
        }
    }
    printf("%d\n", (int)S.size());
    for(auto w : S){
        printf("%d %d\n", w.f, w.s);
    }
    return 0;
}
