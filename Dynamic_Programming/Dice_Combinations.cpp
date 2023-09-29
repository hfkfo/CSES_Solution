#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,mod = 1000000007;
    cin >> n;
    vector<int> ans(n + 1);
    ans[0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= 6 ; j++)
        {
            if(i - j >= 0)
            {
                ans[i] = (ans[i] + ans[i - j]) % mod;
            }
        }
    }
    cout << ans[n];
}
