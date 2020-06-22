#include <iostream>

int c[501];
int v[501];
int a[501];

using namespace std;

int n;
int main(){
    cin >> n;
    cin >> v[1];
    a[1] = v[1];
    for(int l=2; l<=n; l++){
        for(int i=1; i<=l; i++){
            cin >> c[i]; 
        }
        if(l%2 ==0){
            for(int i=1; i<=l-1; i++){
                v[i] = max(v[i], a[i] + c[i]);
                v[i+1] = max(v[i+1], a[i]+ c[i+1]);
            }
        } else {
            for(int i=1; i<=l-1; i++){
                a[i] = max(a[i],v[i] + c[i]);
                a[i+1] = max(a[i+1], v[i]+c[i+1]);
            }
        }
    }
    int MAX = n % 2==0 ? v[n] : a[n];
    if(n%2==0){
        for(int i=1; i<=n; i++)
            MAX = max(MAX, v[i]);
    }else {
        for(int i=1; i<=n; i++)
            MAX = max(MAX, a[i]);
    }
    cout << MAX<<endl;
}
