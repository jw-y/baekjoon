#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, r;
typedef pair<int, int> pii;
vector<pii> v;
int main(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >>v[i].second>> v[i].first;
    }
    sort(v.begin(), v.end());
    pii curr = v[0];
    r++;
    int i= 1;
    while(i<n){
        if(curr.first <= v[i].second){
            curr = v[i];
            r++;
        }
        i++;
    }
    cout <<r;
}
