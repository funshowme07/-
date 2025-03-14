#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vc;
    int n;
    while(cin>>n)vc.push_back(n);
    int size = vc.size();
    int ss = 0;
    int flag = 1;
    for(int i=1;i<size-1;i++){
        if(vc[i]>vc[i-1]){
            if(vc[i]==vc[i+1]){
                ss = i;
                while(i<size-1 && vc[i]==vc[i+1]){
                    i++;
                }
                if(vc[ss-1]<vc[i] && vc[i]>vc[i+1] ){
                    cout<<ss+1<<" "<<i+1<<" "<<vc[i]<<endl;
                    flag = 0;
                }
            }
            else if(vc[i]>vc[i+1]){
                flag = 0;
                cout<<i+1<<" "<<vc[i]<<endl;
            }
        }
    }
    if(flag)cout<<"0 0";
    return 0;
}