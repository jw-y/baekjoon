#include <iostream>
using namespace std;
int n;
int a[2187][2187];
int c_, c00, c11;
void rec(int r0, int r1, int c0, int c1){
    int k=a[r0][c0];
    bool next = false;
    for(int i=0;i<(r1-r0+1);i++)
        for(int j=0;j<(c1-c0+1);j++){
            if(k!=a[r0+i][c0+j]){
                next =true;
                break;
            }
        }

    if(next){
        int rs = (r1-r0+1)/3; 
        int cs = (c1-c0+1)/3;
        rec(r0, r0+rs-1, c0, c0+cs-1);
        rec(r0, r0+rs-1, c0+cs, c0+cs*2-1);
        rec(r0, r0+rs-1, c0+cs*2, c1);

        rec(r0+rs, r0+rs*2-1, c0, c0+cs-1);
        rec(r0+rs, r0+rs*2-1, c0+cs, c0+cs*2-1);
        rec(r0+rs, r0+rs*2-1, c0+cs*2, c1);

        rec(r0+rs*2, r1, c0, c0+cs-1);
        rec(r0+rs*2, r1, c0+cs, c0+cs*2-1);
        rec(r0+rs*2, r1, c0+cs*2, c1);
    }else{
        if(k==-1)
            c_++;
        else if(k==0)
            c00++;
        else if(k==1)
            c11++;
    }
}
int main(){
    cin >>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    rec(0, n-1, 0, n-1);
    cout << c_<<"\n";
    cout << c00<<"\n";
    cout << c11<<"\n";
}
