#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[1000005];
ll s[1000005];

int main(){
    cin >> n >> m;
    ll k;
    for(int i=1;i<=n;i++){
        cin >> k;
        a[i] = k;
    }
    sort(a+1, a+1+n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum += (i)*(a[n-i+1]-a[n-i]);
        s[n-i+1] = sum;
    }
    int low=1, high=n;
    while(low<=high){
        int mid = (low+high)/2;
        if(s[mid]>m){
            low = mid+1;
        }else if(s[mid]< m){
            high = mid-1;
        }else {
            cout << a[mid-1];
            return 0;
        }
    }
    ll diff= m-s[low];
    ll add = ceil((double)diff/(n-high+1));
    cout << a[high]-add;
}
