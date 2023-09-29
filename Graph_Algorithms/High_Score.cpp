#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int n,m,a,b,c,val;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> connect;
    vector<int> ans(n+1);
    fill(ans.begin(),ans.end(),-1e18);
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        connect.push_back({c,{a,b}});
    }
    ans[1] = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            val = ans[connect[j].second.first] + connect[j].first;
            if(ans[connect[j].second.first] == -1e18)
            {
                val = -1e18;
            }
            if(val > ans[connect[j].second.second])
            {
                ans[connect[j].second.second] = val;
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            val = ans[connect[j].second.first] + connect[j].first;
            if(ans[connect[j].second.first] == -1e18)
            {
                val = -1e18;
            }
            if(val > ans[connect[j].second.second])
            {
                ans[connect[j].second.second] = 1e18;
            }
        }
    }
    if(ans[n] == 1e18)
    {
        cout << "-1";
    }
    else
    {
        cout << ans[n];
    }
}
