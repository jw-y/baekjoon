#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[26][26];
int n;
vector<int> house;
typedef pair<int, int> pii;
int main(){
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j]-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                int num=0;
                vector<pii> st;
                st.push_back({i,j});
                while(!st.empty()){
                    pii u = st.back();
                    st.pop_back();
                    if(a[u.first][u.second]==0)
                        continue;
                    num++;
                    a[u.first][u.second] = 0;
                    int p = u.first;
                    int q = u.second;
                    if(p-1>=0 && a[p-1][q]==1)
                        st.push_back({p-1, q});
                    if(q-1>=0 && a[p][q-1]==1)
                        st.push_back({p, q-1});
                    if(p+1<n && a[p+1][q]==1)
                        st.push_back({p+1, q});
                    if(q+1<n && a[p][q+1]==1)
                        st.push_back({p, q+1});
                }
                house.push_back(num);
            }
        }
    }

    sort(house.begin(), house.end());
    cout << house.size()<<"\n";
    for(size_t i=0;i<house.size(); i++){
        cout << house[i]<<"\n";
    }

}
