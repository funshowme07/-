#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vc(m+2,0);
    int k = n;
    //註解
    while(k--){
        int Ai,Li,Ri;
        cin>>Ai>>Li>>Ri;
        vc[Li]+=Ai;
        vc[Ri+1]-=Ai;
    }
    //
    
    //註解
    int s = 0,save = 0,ans = -1e7;
    for(int i=0;i<=m;i++){
        s+=vc[i];
        vc[i] = s;
        if(ans<vc[i]){
            ans = vc[i];
            save = i;
        }
    }
    //
    cout<<save<<" "<<ans;
    return 0;
}