#include <iostream>
#include <vector>
using namespace std;

int ff[1000001];
vector<int> match;

void failure(string P){
    size_t q = 2;
    int k = 0;
    while(q<=P.size()){
        while(k!=0 && P[k]!=P[q-1]){
            k = ff[k];
        }
        if(P[k]==P[q-1])
            k++;
        ff[q] = k;
        q++;
    }
}
int main(){
    string T, P;
    getline(cin, T);
    getline(cin, P);
    
    failure(P);

    size_t q = 0;
    for(size_t i=0;i<T.size();i++){
        while(q!=0 && P[q]!=T[i])
            q = ff[q];
        if(P[q]==T[i])
            q++;
        if(q==P.size()){
            match.push_back(i+1-P.size()+1);        
            q = ff[q];
        }
    }
    cout << match.size()<<"\n";
    for(size_t i=0;i<match.size();i++){
        cout << match[i]<<"\n";
    }
}
