#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vc,vcc;
    //set<int> s;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vc.push_back(k);
        vcc.push_back(k);
        //s.insert(k);
    }
    sort(vcc.begin(),vcc.end());
    map<int,int> mp;
    int len = vc.size();
    for(auto k : vcc){
        mp[k] = len;
        len--;
    }
    for(int i=0;i<n;i++){
        cout<<mp[vc[i]]<<" ";
    }
    
    return 0;
}