#include <iostream>
using namespace std;
int a[10001];
int b[10001];
int c;
int main(){
    string aa, bb;
    cin >> aa >> bb;
    for(int i=0; i<aa.size(); i++){
        a[i] = aa[aa.size()-i-1]-'0';
    }
    for(int i=0;i<bb.size();i++){
        b[i] = bb[bb.size()-i-1]-'0';
    }
    for(int i=0;i<max(aa.size(), bb.size())+1; i++){
       a[i] += b[i] +c;
       c = a[i] /10;
       a[i] %=10;
    }
    c = 10001;
    while(!a[--c]){}
    c++;
    while(c-->0){
        cout << a[c];
    }
}
