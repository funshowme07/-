#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    // scanf("%d",&n);
    cin>>n;
    vector<long long> building_size(n);
    vector<long long> building_height(n);
    int mh = -1;
    for(int i=0;i<n;i++){
        cin>>building_size[i];
        int h = -1;
        for(int j=0;j<building_size[i];j++){
            int s;
            cin>>s;
            h = max(h,s);
        }
        building_height[i] = h;
        if(h>mh)mh = h;
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += (mh-building_height[i])*building_size[i];
    }
    cout<<ans;
    return 0;
}