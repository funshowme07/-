#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> mp;
int main(){
    string order,str;
    cin>>order>>str;
    for(auto k:order)mp[k]=0;
    for(auto K:str)mp[K]+=1;
    string ans = "";
    for(auto k:order)for(int i=0;i<mp[k];i++)ans+=k;
    //cout<<ans<<endl;
    int Q;
    cin>>Q;
    while(Q--){
        int a;
        cin>>a;
        cout<<ans[a-1]<<endl;
    }
    return 0;
}