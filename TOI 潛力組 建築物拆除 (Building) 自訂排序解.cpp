#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
double c1,c2;
bool cmp(vector<double> a,vector<double> b){
    c1 = a[0]/a[1];
    c2 = b[0]/b[1];
    return c1>c2;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<double>> vc(N,vector<double>(2));
    long long days = 0,money = 0;
    for(int i=0;i<N;i++){
        double a,b;
        cin>>a>>b;
        vc[i][0] = a;
        vc[i][1] = b;
        days+=b;
        money+=a;
        //cout<<"edf"<<a<<" "<<b<<endl;
    }
    sort(vc.begin(),vc.end(),cmp);
    long long ans = 0;
    for(int i=0;i<N;i++){
        ans+=money*((int)vc[i][1]);
        money-=(int)vc[i][0];
    }
    cout<<ans;
    return 0;
}