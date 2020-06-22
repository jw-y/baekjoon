#include <iostream>
using namespace std;
int n, a;
int d[101][10];
int main(){
    cin >> n;
    d[1][0] = 1;
    for(int i=1;i<10;i++)
        d[1][i] = 1;
    for(int i=2; i<=n;i++){
        d[i][0] = d[i-1][1];
        for(int j=1; j<9; j++)
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%1000000000;
        d[i][9] = d[i-1][8];
    }
    for(int i=1; i<10; i++)
        a= (a + d[n][i])%1000000000;
    cout << a;
}
