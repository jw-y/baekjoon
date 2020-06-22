#include <iostream>
using namespace std;
int d[10001];
int n, a, b,c;
int main(){
    cin >> n;
    cin >> d[1];
    if(n>=2)cin >> b;
    d[2] = b + d[1];
    for(int i=3;i<=n;i++){
        cin >> c;
        d[i] = max(max(d[i-3]+b+c, d[i-2]+c), d[i-1]);
        a = b; 
        b = c;
    }
    cout << d[n];
}
