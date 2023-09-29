#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<int>road[n+1],ans;
    int pre[n+1]={0},in[n+1]={0},dis[n+1]={0};
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        road[a].push_back(b);
        in[b]++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        dis[i] = -1e9;
    }
    dis[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i:road[now])
        {
            if (dis[i] < dis[now]+1)
            {
                pre[i] = now;
                dis[i] = dis[now]+1;
            }
            in[i]--;
            if (in[i] == 0)
            {
                q.push(i);
            } 
        }
    }
    if(dis[n] < 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        ans.push_back(n);
        while (ans.back() != 1)
        {
            ans.push_back(pre[ans.back()]);
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(int i : ans)
        {
            cout << i << " ";
        }
    }
}
