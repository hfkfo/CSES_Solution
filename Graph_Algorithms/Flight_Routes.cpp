#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,m,k,a,b,c;
    cin >> n >> m >> k;
    vector<pair<int,int>> q[n+1];
    multiset<pair<int,int>> pd;
    vector <int> ans[100005];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        q[a].push_back({b,c});
    }
    pd.insert({0,1});
    while (!pd.empty())
    {
        auto now = pd.begin();
        if(ans[(*now).second].size() == k)
        {
            pd.erase(now);
            continue;
        }
        ans[(*now).second].push_back((*now).first);
        for(auto i : q[(*now).second])
        {
            pd.insert({((*now).first + i.second),i.first});
        }
        pd.erase(now);
    }
    for(int i = 0 ; i < k ; i++)
    {
        cout << ans[n][i] << " ";
    }
    return 0;
}
