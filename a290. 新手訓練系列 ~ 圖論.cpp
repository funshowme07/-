#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        unordered_map<int,vector<int>> mp;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(a!=b)mp[a].push_back(b);
        }
        int A,B;
        cin>>A>>B;
        int dis[800+1];
        memset(dis,-1,sizeof(dis));
        dis[A] = 0;
        //bfs
        queue<int> q;
        q.push(A);
        int flag = 0;
        while(q.size()){
            int now = q.front();
            q.pop();
            for(int i:mp[now]){
                if(i==B){
                    cout<<"Yes!!!"<<endl;
                    flag = 1;
                    break;
                }
                if(dis[i]==-1){
                    q.push(i);
                    dis[i]=0;
                }
            }
            if(flag)break;
        }
        if(!flag)cout<<"No!!!"<<endl;
    }
    return 0;
}