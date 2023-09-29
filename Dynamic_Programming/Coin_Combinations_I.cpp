#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,mod = 1000000007,k;
    cin >> n >> k;
    vector<int> coin(n);
    vector<int> ans(k + 1);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> coin[i];
    }
    ans[0] = 1;
    for(int i = 1 ; i <= k ; i++)
    {
        for(int j = 0 ; j <n ; j++)
        {
            if(i - coin[j] >= 0)
            {
                ans[i] = (ans[i] + ans[i - coin[j]]) % mod;
            }
        }
    }
    cout << ans[k];
}
