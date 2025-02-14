#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
	while(cin>>n && n!=0){
        queue<int> q;
        for(int i=1;i<=n;i++)q.push(i);
        cout<<"Discarded cards: ";
        while(q.size()>=2){
            if(q.size()==2)cout<<q.front();
            else cout<<q.front()<<", ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<"\nRemaining card: "<<q.front()<<endl;
    }
	return 0;
}
