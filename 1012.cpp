#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int T;
int n, m, k;
int a[51][51];
typedef pair<int, int> pii;
int main(){
    cin >> T;
    while(T){
        cin>> m >> n >> k;
        memset(a, 0, sizeof(a));
        int x, y; 
        for(int i=0;i<k;i++){
            cin >> y >> x;
            a[x][y] = 1;
        }
        int num=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]){
                    vector<pii> st;
                    st.push_back({i, j});
                    num++;
                    while(!st.empty()){
                        pii u = st.back();
                        st.pop_back();
                        int x=u.first;
                        int y=u.second;
                        if(a[x][y]==0)
                            continue;
                        a[x][y]=0;
                        if(x-1>=0 && a[x-1][y]==1)
                            st.push_back({x-1, y});
                        if(y-1>=0 && a[x][y-1]==1)
                            st.push_back({x, y-1});
                        if(x+1<n && a[x+1][y]==1)
                            st.push_back({x+1, y});
                        if(y+1<m && a[x][y+1]==1)
                            st.push_back({x, y+1});
                    }
                }
            }
        }
        cout << num<<"\n";

        T--;
    }
}
