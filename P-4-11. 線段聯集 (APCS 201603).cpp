#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vc;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vc.push_back({a,b});
    }
    sort(vc.begin(),vc.end());
    pair<int,int> now = vc[0];
    int total = 0;
    for(auto s : vc){
        if(s.f>now.s){
            total+=now.s-now.f;
            now = s;
            continue;
        }
        now.s = max(s.s,now.s);
    }
    total+=now.s-now.f;
    cout<<total;
    return 0;
}