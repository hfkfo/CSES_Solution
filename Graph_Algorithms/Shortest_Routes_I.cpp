#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct road
{
    vector<pair<int,int>> q;
};
signed main()
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<road> connect(n + 1);
    int ans[n+1] = {0};
    set<pair<int,int>> p;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        connect[a].q.push_back({b,c});
        //connect[b].q.push_back({a,c});
    }
    p.insert({0,1});
    while(!p.empty())
    {
        auto it = p.begin();
        //cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
        for(int i = 0 ; i < connect[(*it).second].q.size() ; i++)
        {
            if(ans[connect[(*it).second].q[i].first] != 0
            && ans[connect[(*it).second].q[i].first] > (*it).first + connect[(*it).second].q[i].second)
            {
                p.erase({ans[connect[(*it).second].q[i].first],connect[(*it).second].q[i].first});
                ans[connect[(*it).second].q[i].first] = (*it).first + connect[(*it).second].q[i].second;
                p.insert({ans[connect[(*it).second].q[i].first],connect[(*it).second].q[i].first});
            }
            else if(ans[connect[(*it).second].q[i].first] == 0 && connect[(*it).second].q[i].first != 1)
            {
                //cout << connect[(*it).second].q[i].first << " " << connect[(*it).second].q[i].second << " " << (*it).first << "\n";
                ans[connect[(*it).second].q[i].first] = (*it).first + connect[(*it).second].q[i].second;
                p.insert({ans[connect[(*it).second].q[i].first],connect[(*it).second].q[i].first});
            }
        }
        p.erase({(*it).first,(*it).second});
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cout << ans[i] << " ";
    }
}
