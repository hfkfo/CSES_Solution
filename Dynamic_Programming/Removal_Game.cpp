#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int n,sum = 0;
    cin >> n;
    vector<int> x(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<int>> dp(n,vector<int> (n));
    for(int left = n - 1 ; left >= 0 ; left--)
    {
        for (int right = left; right < n; right++)
        {
            if(left == right)
            {
                dp[left][right] = x[left];
            }
            else
            {
                dp[left][right] = max(x[left] - dp[left + 1][right] , x[right] - dp[left][right - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2;
}
