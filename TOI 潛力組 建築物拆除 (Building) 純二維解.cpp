#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<double>> vc(N,vector<double>(3));
    long long days = 0,money = 0;
    for(int i=0;i<N;i++){
        double c,a,b;
        cin>>a>>b;
        c = a/b;
        vc[i][0] = c;
        vc[i][1] = a;
        vc[i][2] = b;
        days+=b;
        money+=a;
    }
    sort(vc.begin(),vc.end());
    long long ans = 0;
    for(int i=N-1;i>=0;i--){
        ans+=money*((int)vc[i][2]);
        money-=(int)vc[i][1];
    }
    cout<<ans;
    return 0;
}