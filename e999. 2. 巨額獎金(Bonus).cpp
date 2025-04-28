#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,E;
    cin>>N>>E;
    unordered_map<int,vector<int>> mp;
    vector<int> in_degree(N,0);
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        in_degree[b]++;
    }
    int ans[N]={0};
    queue<int> q;
    q.push(0);
    ans[0]=1;
    while(q.size()){
        int now = q.front();
        q.pop();
        for(auto k:mp[now]){
            ans[k]+=ans[now];
            in_degree[k]--;
            if(in_degree[k]==0)q.push(k);
        }
    }
    cout<<ans[N-1];
    return 0;
}