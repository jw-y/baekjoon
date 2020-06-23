#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int n,m;
int a[101][101];
pii pi[101][101];
bool visited[101];

int main(){
    cin >> n >> m;
    string s;
    for(int i=0;i<n;i++){
        cin >>s;
        for(int j=0;j<m;j++){
            a[i][j] = s[j]-'0';
        }
    }
    queue<pii> q;
    q.push({0,0});
    pi[0][0] = {0,0};
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        if(a[x][y]==0)
            continue;
        a[x][y] = 0;

        if(x-1>=0 && a[x-1][y]==1){
            pi[x-1][y] = u; 
            q.push({x-1, y});
        }
        if(y-1>=0 && a[x][y-1]==1){
            pi[x][y-1] = u; 
            q.push({x, y-1});
        }
        if(x+1<n && a[x+1][y]==1){
            pi[x+1][y] = u; 
            q.push({x+1, y});
        }
        if(y+1<m && a[x][y+1]==1){
            pi[x][y+1] = u; 
            q.push({x, y+1});
        }
            
    }
    int num= 2;
    pii u = pi[n-1][m-1];
    while(u != make_pair(0,0)){
        num++;
        u = pi[u.first][u.second];
    }
    cout << num;
}
