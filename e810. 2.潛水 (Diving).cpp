#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
    int n,m,a,b,w;
    cin>>n>>m;
    //vector<vector<int>> vc(m,vector<int>(3));
    //for(int i=0;im;i++)cin>>vc[i][0]>>vc[i][1]>>vc[i][2];
    vector<pair<int ,int>> vc[505];

    int dis[505];
    memset(dis, -1, sizeof(dis));
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        vc[a].push_back({b,w});
        vc[b].push_back({a,w});
    }
    cin>>a>>b;
   
        
    //bfs
    queue<int> q;
    q.push(a);
    dis[a] = 0;
    while(q.size()){
        int now = q.front();
        q.pop();
        for(auto nxt: vc[now]){
            int tmp= max( dis[now] , nxt.s );
            if(dis[nxt.f]==-1 || tmp<dis[nxt.f]) {
                dis[nxt.f] = tmp;
                q.push(nxt.f);
            }
        }
    }
    cout<<dis[b]<<endl;
    return 0;
}