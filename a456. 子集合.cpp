#include <bits/stdc++.h>
using namespace std;
vector<int> vc,ans;
void dfs(int d,int s,int stop){
    if(d==stop){
        cout<<'{';
        for(int i=0;i<stop;i++){
            if(i)cout<<",";
            cout<<ans[i];
        }
        cout<<'}'<<endl;
        return;
    }
    
    for(int i=s;i<vc.size();i++){
        ans[d] = vc[i];
        dfs(d+1,i+1,stop);
    }
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)vc.push_back(j);
        cout<<'{'<<0<<'}'<<endl;
        for(int j=1;j<=n;j++){
            ans.resize(j);
            dfs(0,0,j);
        }
        cout<<endl;
        vc.clear();
        ans.clear();
    }
    return 0;
}