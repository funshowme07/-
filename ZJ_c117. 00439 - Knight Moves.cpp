#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
string trans(string s){  //Convert the coordinate of the chessboard to the coordinate of the vector
    for(int i=0;i<8;i++){
        if(s[0]==('a'+i)){
            s[0]=i+48;
        }
    }
    return s;
}

bool in(int x,int y){ //check the bounds
    return ((x>=0 && x<=8-1)&&(y>=0 && y<=8-1));
}

// direciton
int dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,-2},{-1,-2},{1,2},{-1,2}};
//
int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        // board
        vector<vector<int>> board(8,vector<int>(8,0));
        //
        string c1,c2;
        c1=s1;
        c2=s2;
        if(s1==s2)cout<<"To get from "<< c1 <<" to "<< c2 <<" takes 0 knight moves."<<endl; //Case:the same
        else{
            s1 = trans(s1);
            s2 = trans(s2);
            pair<int,int> start = {s1[0]-48,s1[1]-48-1};
            pair<int,int> target = {s2[0]-48,s2[1]-48-1};
            board[start.f][start.s] = 1; // where ur knight start
            board[target.f][target.s] = 1000;// our target
            //BFS
            queue<pair<int,int>> q;
            q.push(start);
            while(!q.empty()){
                pair<int,int> now;
                now = q.front();
                q.pop();
                int flag = 0;
                for(int i=0;i<8;i++){
                    int x = now.f+dir[i][0];
                    int y = now.s+dir[i][1];
                    if(in(x,y)){
                        if(board[x][y]==0){
                            q.push({x,y});
                            board[x][y] = board[now.f][now.s]+1;
                        }
                        else if (board[x][y]==1000){
                            flag = 1;
                            board[x][y] = board[now.f][now.s]+1;
                            cout<<"To get from "<< c1 <<" to "<< c2 <<" takes "<< board[x][y]-1 <<" knight moves."<<endl;
                            break;
                        }
                    }
                }
                if(flag)break;
            }
            //
        }
    }
    return 0;
}
