#include <iostream>
#include <algorithm>
using namespace std;
const int k = 1e7;
int arr[k]={0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[a]+=1;
        arr[b]-=1;
    }
    int ans = 1,now = 0;
    for(int i=0;i<k;i++){
        now+=arr[i];
        ans=max(ans,now);
    }
    cout<<ans;
    return 0;
}