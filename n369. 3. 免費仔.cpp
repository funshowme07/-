#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<string> account;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(!account.count(a)){
            cout<<"welcome, "<<b<<endl;
            account.insert(a);
        }
        else{
            cout<<b<<" account has been used"<<endl;
        }
    }
    return 0;
}