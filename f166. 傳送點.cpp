#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,P,L,R;
    cin>>n>>P>>L>>R;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int arrr[n];
    memset(arrr,-1,sizeof(arrr));
    queue<int> q;
    q.push(0);
    arrr[0] = 0;
    while(q.size()){
        int now = q.front();
        if(now == P)break;
        q.pop();
        int x = now - L;
        int y = now + R;
        if( (x>=0 && x<n) && (arr[x]>=0 && arr[x]<n) ){
            x = arr[x];
            if((x>=0 && x<n) && arrr[x]==-1){
                arrr[x] = arrr[now]+1;
                q.push(x);
            }
        }
        if( (y>=0 && y<n) && (arr[y]>=0 && arr[y]<n)  ){
            y = arr[y];
            if((y>=0 && y<n) && arrr[y]==-1){
                arrr[y] = arrr[now]+1;
                q.push(y);
            }
        }
    }
    cout<<arrr[P];
    return 0;
}