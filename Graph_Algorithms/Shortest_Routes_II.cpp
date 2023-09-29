#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int n,m,q,a,b,c;
    cin >> n >> m >> q;
    int ans[n+1][n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            ans[i][j] = 1e18;
        }
        ans[i][i] = 0;
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b],c);
        ans[b][a] = ans[a][b];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == k) continue;
            for (int j = i+1; j <= n; j++)
            {
                if (j == k) continue;
                if (ans[i][j] > ans[i][k] + ans[k][j])
                {
                    ans[i][j] = ans[i][k] + ans[k][j];
                    ans[j][i] = ans[i][j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (ans[a][b] == 1e18) cout << -1 << "\n";
        else cout << ans[a][b] << "\n";
    }
}
