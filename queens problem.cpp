#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> board;
vector<vector<int>> qindex;
vector<vector<vector<int>>> solutions;
int qin_i=0,qin_j=0;
bool is_valid_state(){
board[qin_i][qin_j]=1;
for(int i=0;i<qin_i;++i){
  if(board[i][qin_j]==1){return false;}
}
for(int i=qin_i-1,j=qin_j-1;i>=0 && i<n && j>=0 && j<n; i=i-1, j=j-1){// (diagonal/)
    if(board[i][j]==1){return false;}
}
for(int i=qin_i-1,j=qin_j+1;i>=0 && i<n && j>=0 && j<n; i=i-1, j=j+1){// (diagonal\)
    if(board[i][j]==1){return false;}
}
return true;
}
void get_candidates(){
if(is_valid_state()){
    if(qin_i==n-1){
        solutions.push_back(board);
        board[n-1][qin_j]=0;
        bool possible=false;
        if(qin_j<n-1){qin_j+=1;
        possible=true;}
        else{
        for(int i=qin_i-1;i>=0;--i){
    if(qindex[i][1]<n-1){
        possible=true;
        qin_i=i;
        qin_j=qindex[i][1]+1;
        for(int m=i;m<qindex.size();++m){
            board[qindex[m][0]][qindex[m][1]]=0;
        }
        qindex.erase(qindex.begin()+i,qindex.end());
        break;
        }
    }
        }
    if(!possible){qin_i=0;
              qin_j=n;
        }
}

    else{
        qindex.push_back({qin_i,qin_j});
        qin_i=qin_i+1;
        qin_j=0;
    }
}
else{
    board[qin_i][qin_j]=0;
    bool possible=false;
    if(qin_j<n-1){qin_j=qin_j+1;
    possible=true;}
    else{
    for(int i=qin_i-1;i>=0;--i){
    if(qindex[i][1]<n-1){
        possible=true;
        qin_i=i;
        qin_j=qindex[i][1]+1;
        for(int m=i;m<qindex.size();++m){
            board[qindex[m][0]][qindex[m][1]]=0;
        }
        qindex.erase(qindex.begin()+i,qindex.end());
        break;
        }
    }
}
if(!possible){qin_i=0;
              qin_j=n;
        }
}
}

int main(){
cin>>n;
board=vector<vector<int>> (n,vector<int>(n,0));
while(true){
    get_candidates();
    if(qin_i==0 && qin_j==n){break;}
}
cout<<solutions.size()<<'\n';
if(solutions.size()==0){cout<<"No"<<'\n';}
else{
for(int i=0;i<solutions.size();++i){
    for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
            cout<<solutions[i][j][k]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
}
return 0;}
