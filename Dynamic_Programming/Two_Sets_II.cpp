#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
array<int, 150004> dp;
int DP(int n, int x)
{
    dp[0] = 1;
    for(int j = 1; j <= n; j++)
    {
        for(int i = x; i >= j; i--)
        {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    return (dp[x] * (int)(5e8 + 4)) % mod;
}
signed main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    if(sum & 1)
    {
        cout << 0;
    } 
    else
    {
        cout << DP(n, sum / 2);
    } 
    return 0;
}
