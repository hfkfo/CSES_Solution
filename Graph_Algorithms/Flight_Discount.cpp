#include<bits/stdc++.h>
using namespace std;
struct road
{
    vector<pair<long long int,long long int>> q;
};
int main()
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<road> connect(n + 1);
    long long int ans[2][n+1];
    set<pair<long long int,pair<long long int,int>>> p;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        connect[a].q.push_back({c,b});
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ans[0][i] = 1e18;
        ans[1][i] = 1e18;
    }
    p.insert({0,{1,0}});
    while(!p.empty())
    {
        //cout << "1";
        auto now = p.begin();
        if ((*now).first > ans[(*now).second.second][(*now).second.first])
        {
            p.erase({(*now).first,{(*now).second.first,(*now).second.second}});
            continue;
        }
        for(auto i : connect[(*now).second.first].q)
        {
            if (ans[(*now).second.second][i.second] > (*now).first + i.first)
            {
                ans[(*now).second.second][i.second] = (*now).first + i.first;
                p.insert({ans[(*now).second.second][i.second], {i.second, (*now).second.second}});
            }
            if ((*now).second.second == 0){
                if (ans[1][i.second] > (*now).first + i.first/2){
                    ans[1][i.second] = (*now).first + i.first/2;
                    p.insert({ans[1][i.second], {i.second, 1}});
                }
            }
        }
        p.erase({(*now).first,{(*now).second.first,(*now).second.second}});
    }
     cout << ans[1][n];
}
