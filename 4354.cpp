#include <iostream>
using namespace std;

int ff[1000001];
void failure(string P){
    size_t q=2;
    size_t k=0;
    ff[1] = 0;
    while(q<=P.size()){
        while(k>0 && P[k]!=P[q-1])
            k = ff[k];
        if(P[k]==P[q-1])
            k++;
        ff[q] = k;
        q++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string T;
    while(getline(cin, T)){
        if(T.size()==1 &&T[0]=='.')
            break;
        failure(T);
        int k = T.size() - ff[T.size()];
        if(T.size()%k ==0)
            cout << T.size()/k<<"\n";
        else
            cout << 1<<"\n";
    }
}
