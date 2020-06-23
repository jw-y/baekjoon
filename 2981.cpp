#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[101];
vector<int> res;
int gcd(int a, int b){
    if(a % b==0)
        return b;
    else
        return gcd(b, a %b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int gg= abs(a[1]-a[0]);
    for(int i=0;i <n-2;i++)
        gg = gcd(gg, abs(a[i+2]-a[i+1]));
    for(int i=1; i*i<=gg; i++){
        if(gg % i==0){
            res.push_back(i);
            if(i!=gg/i) res.push_back(gg/i);
        }
    }
    sort(res.begin(), res.end());
    for(int i=1;i<res.size(); i++)
        cout << res[i]<< " ";
}

