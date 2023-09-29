#include<bits/stdc++.h>
using namespace std;
array<array<long long int,10>,1500000> dp;
int main()
{
    long long int mod = 1000000007;
    for(int i = 1 ; i <= 8 ; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2 ; i <= 1000000 ; i++)
    {
        for(int j = 1 ; j <= 8 ; j++)
        {
            if(j == 1 || j == 3 || j == 4 || j == 5 || j == 6)
            {
                dp[i][j] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][6]) % mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][8]) % mod;
            }
        }
    }
    long long int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (dp[n][3] + dp[n][7]) % mod <<"\n";
    }
 
}
