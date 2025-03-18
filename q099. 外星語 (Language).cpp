#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<string> vc(n);
    unordered_set<char> s; //出現過的字元
    unordered_map< char,vector<char> > mp; //有向圖
    unordered_map<char,int> in_degree; //in_degree
    for(int i=0;i<n;i++){
        cin>>vc[i];
        for(auto l : vc[i])s.insert(l);
    }
    for(auto k:s)in_degree[k]=0;
    for(int i=0;i<n-1;i++){
        int len = min(vc[i].size(),vc[i+1].size());
        string a = vc[i];
        string b = vc[i+1];
        //找相異字元
        for(int j=0;j<len;j++){
            if(a[j]!=b[j]){
                if( find(mp[a[j]].begin(),mp[a[j]].end(),b[j])==mp[a[j]].end() ){ //不存在在mp裡
                    mp[a[j]].push_back(b[j]);
                    in_degree[b[j]]+=1;
                }
                break;
            }
        }
        //
    }
    queue<char> q;
    for(auto k:s)if(in_degree[k]==0)q.push(k);
    while(q.size()){
        char c = q.front();
        q.pop();
        cout<<c;
        for(auto p:mp[c]){
            in_degree[p]-=1;
            if(in_degree[p]==0)q.push(p);
        }
    }
    return 0;
}