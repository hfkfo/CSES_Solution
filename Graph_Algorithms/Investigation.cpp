#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
signed main()
{
    int n,m,a,b,c;
    cin >> n >> m;
    vector<pair<int,int>> v[n+1];
    int max1[n+1] = {0} ,min1[n+1] ={0},val[n+1] = {0},time[n+1] = {0};
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    for(int i = 2; i <= n; i++)
	{
		val[i] = 1e18;
	}
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    q.push({0,1});
    val[1] = 0;
    time[1] = 1;
    while(!q.empty())
    {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(d > val[u])
        {
            continue;
        }
        for(auto i : v[u])
        {
            int v = i.first;
            int c = i.second;
            if(val[v] < c+d)
            {
                continue;
            }
            if(val[v] == c+d)
            {
                min1[v] = min(min1[v],min1[u] + 1);
                max1[v] = max(max1[v],max1[u] + 1);
                time[v] += time[u];
                time[v] %= mod;
            }
            if(val[v] > c+d)
            {
                val[v] = c+d;
                min1[v] = min1[u] + 1;
                max1[v] = max1[u] + 1;
                time[v] = time[u];
                q.push({val[v],v});
            }
        }
    }
    cout << val[n] << " " << time[n] << " " << min1[n] << " " << max1[n];
}
