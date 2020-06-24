#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,m;
    cin >> T;
    cin >> m;
    cout << m<<"\n";
    T--;
    while(T--){
        int k;
        cin >> k;
        if(k < m){
            l.push(k);
            if(l.size()-1 == r.size()){
                int tmp = m;
                m = l.top();
                l.pop();
                r.push(tmp);
            }
        }else if(k>m){
            r.push(k);
            if(l.size() != r.size()-1){
                int tmp = m;
                m = r.top();
                r.pop();
                l.push(tmp);
            }
        }else{
            if(l.size()==r.size()){
                r.push(k);
            }else {
                l.push(k);
            }
        }
        cout << m <<"\n";
    }
}
