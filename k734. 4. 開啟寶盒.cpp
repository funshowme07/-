#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k; // 寶盒數/總鑰匙數/開啟寶盒的鑰匙數
    int t;
    cin>>t; //現在有的鑰匙數
    unordered_set<int> keys; //現在有哪些鑰匙
    int key;
    for(int i=0;i<t;i++){
        cin>>key;
        keys.insert(key);
    }
    vector<vector<int>> box_keys(n,vector<int>(k)),keys_box(n,vector<int>(k)); //需要用哪種鑰匙開啟哪個寶盒/開完後會獲得的鑰匙
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>box_keys[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>keys_box[i][j];
        }
    }
    vector<bool> seen(m,false); //哪種鑰匙被用過了
    vector<int> box_nums(n,k); //每個寶盒需要幾隻鑰匙才能開
    vector<int> graph[m]; //每個鑰匙對應的寶盒
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            graph[ box_keys[i][j] ].push_back(i);
        }
    }
    //bfs
    queue<int> q;
    for(auto K:keys)q.push(K);
    while(q.size()){
        int now = q.front();
        q.pop();
        if(!seen[now]){
            for(auto KK:graph[now]){ //KK:對應寶盒
                box_nums[KK]-=1;
                if(box_nums[KK]==0)for(auto l:keys_box[KK])q.push(l);
            }
            seen[now] = true; //true代表被用過了
        }
    }
    //
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(box_nums[i]==0){
            cnt+=1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}