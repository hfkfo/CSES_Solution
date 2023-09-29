#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
array<int, 100004> x;
array<array<int, 104>, 100004> dp;
signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
    }
    if(x[1])
    {
        dp[1][x[1]] = 1;
    }
    else
    {
        for(int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(x[i]){
            for(int k = -1; k <= 1; k++){
                dp[i][x[i]] += dp[i - 1][x[i] + k];
                dp[i][x[i]] %= mod;
            }
        }else{
            for(int j = 1; j <= m; j++){
                for(int k = -1; k <= 1; k++){
                    dp[i][j] += dp[i - 1][j + k];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}
