#include <iostream>
#include <vector>
using namespace std;
int n,m;
typedef pair<int, int> pii;
vector<vector<int>> v;
vector<bool> visited;
vector<int> ss;
void dfs(int u){
    visited[u] = true;
    for(int k: v[u])
        if(!visited[k])
            dfs(k);
    ss.push_back(u);
}
int main(){
    cin >> n >> m;
    v.resize(n+1);
    visited.resize(n+1, false);
    while(m--){
        int a,b;
        cin >> a >>b;
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i])
            continue;
        dfs(i);
    }
    for(int i=0;i<n;i++){
        cout << ss[i]<<" ";
    }
}


