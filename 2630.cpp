#include <iostream>
using namespace std;
int a[128][128];
int n;
int w, b;
void rec(int r0, int r1, int c0, int c1){
    int k = a[r0][c0];
    bool br = false;
    for(int i=0; i<r1-r0+1; i++)
        for(int j=0; j<c1-c0+1;j++){
            if(a[r0+i][c0+j] != k)
                br = true;
        }
    if(br){
        rec(r0, (r1+r0)/2, c0, (c1+c0)/2);
        rec(r0, (r1+r0)/2, (c1+c0)/2+1, c1);
        rec((r1+r0)/2+1, r1, c0, (c1+c0)/2);
        rec((r1+r0)/2+1, r1, (c1+c0)/2+1, c1);
    }else {
        if(k==0)    w++;
        else        b++;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n;i++)
        for (int j=0;j<n;j++)
            cin >> a[i][j];
    rec(0, n-1, 0, n-1);
    cout << w<<"\n";
    cout << b <<"\n";
}
