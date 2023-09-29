#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,k;
    cin >> n >> k;
    vector<int> ans(k + 1,1000000000);
    vector<int> coin(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> coin[i];
    }
    ans[0] = 0;
    for(int i = 1 ; i <= k ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i - coin[j] >= 0)
            {
                if(ans[i] > ans[i - coin[j]] + 1)
                {
                    ans[i] = ans[i - coin[j]] + 1;
                }
            }
        }
    }
    if(ans[k] != 1000000000)
        cout << ans[k];
    else
        cout << "-1";
}
