#include <iostream>
using namespace std;
string a,b;
int n;
int v[1001][1001];
int main(){
    cin >> a >> b;
    for(int i=1; i<=a.size();i++)
        for(int j=1; j<=b.size(); j++)
            v[i][j] = max(max(v[i][j-1], v[i-1][j]) , 
                    v[i-1][j-1]+ (a[i-1] == b[j-1] ? 1 :0));
    cout << v[a.size()][b.size()];
}
