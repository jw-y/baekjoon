#include <iostream>
#include <cstring>
using namespace std;
int n;
int dp[1000001];
int MAX = 0x4f4f4f4f;
int main(){
    memset(dp, 0x4f, sizeof(dp));
    cin >> n;
    dp[1] = 0;
    for(int k=1; k<n; k++){
        if(3*k <=n) dp[3*k] = dp[k]+1;
        if(2*k <=n) dp[2*k] = min(dp[k]+1, dp[2*k]);
        dp[k+1] = min(dp[k]+1, dp[k+1]);
    }
    cout << dp[n]<<endl;
}
