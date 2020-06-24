#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
int V, E;
int v1, v2;
int m[801][801];

typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
int dis[801];
bool visited[801];
int dijkstra(int s, int t){
    for(int i=0;i<801;i++)
        visited[i] = false;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        
        if(visited[u.second])
            continue;
        visited[u.second] = true;
        
        if(u.second == t){
            return dis[t];
        }

        for(int i=1;i<=V;i++){
            if(!visited[i] && m[u.second][i] >0 &&
                    dis[u.second]+ m[u.second][i] < dis[i]){
                        dis[i] = dis[u.second] + m[u.second][i];
                        pq.push({dis[i], i});
                    }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V>>E;
    int x, y, w;
    for(int i=0;i<E; i++){
        cin >> x >> y >> w;
        m[y][x] = m[x][y] = w;
    }
    cin >> v1 >>v2;

    int ans0, ans1;
    int p0= dijkstra(1, v1);
    int p1 = dijkstra(v1, v2);
    int p2 = dijkstra(v2, V);
    if(p0>=0 && p1>=0 && p2>=0){
        ans0 = p0+p1+p2;
    }else {
        ans0 = INF;
    }

    p0 = dijkstra(1, v2);
    p1 = dijkstra(v2, v1);
    p2 = dijkstra(v1, V);
    if(p0>=0 && p1>=0 && p2>=0){
        ans1 = p0+p1+p2;
    }else {
        ans1 = INF;
    }

    if(ans0 == INF && ans1 == INF)
        cout <<-1;
    else
        cout << min(ans0, ans1);
}
