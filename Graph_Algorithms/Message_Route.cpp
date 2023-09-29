#include<bits/stdc++.h>
using namespace std;
struct connect
{
    vector<int> p;
};
int main()
{
    int n,m,a,b,temp;
    cin >> n >> m;
    vector<connect> net(n+1);
    vector<int> ans;
    int num[n+1] = {0},pre[n+1] = {0},visit[n+1] = {0};
    queue<int> q;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        net[a].p.push_back(b);
        net[b].p.push_back(a);
    }
 
    q.push(1);
    visit[1] = 1;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int k = 0; k < net[now].p.size() ; k++)
        {
            if (!visit[net[now].p[k]])
            {
                visit[net[now].p[k]] = 1;
                pre[net[now].p[k]] = now;
                q.push(net[now].p[k]);
            }
        }
 
    }
    if(!pre[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    temp = n;
    while(temp != 1)
    {
        ans.push_back(temp);
        temp = pre[temp];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto i : ans)
    {
        cout << i << " ";
    }
}
