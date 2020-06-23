#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int v, e;
int s;
vector<vector<pii>> m;
bool visited[20001];
#define INF 0x3f3f3f3f
int dis[20001];

int main(){
    cin >> v >> e >> s;
    int x, y, w;
    m.resize(v+1);
    for (int i=0;i<e;i++){
        cin >> x >> y>> w;
        m[x].push_back({y, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(visited[u.second])
            continue;
        visited[u.second]= true;
        for(auto &p: m[u.second]){
            if(!visited[p.first] &&
                    dis[u.second]+p.second < dis[p.first]){
                    dis[p.first] = dis[u.second] + p.second;
                    pq.push({dis[p.first], p.first});
                }
        }
    }

    for(int i=1; i<=v; i++){
        if(dis[i]==INF)
            cout << "INF\n";
        else
            cout << dis[i]<<"\n";
    }

}
