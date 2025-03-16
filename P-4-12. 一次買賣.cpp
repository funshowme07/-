#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,min_v=1e9,ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        ans = max(ans,a-min_v);
        min_v = min(min_v,a);
    }
    cout<<ans;
    return 0;
}