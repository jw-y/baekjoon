#include <iostream>
using namespace std;
typedef long long int ll;
ll a,b,c;
ll pow(ll a, ll b){
    if(b==1)
        return a%c;
    ll d = pow(a, b/2);
    return ((d*d)%c*(b%2==0?1:a))%c;
}
int main(){
    cin>>a>>b>>c;
    cout << pow(a%c, b);
}
