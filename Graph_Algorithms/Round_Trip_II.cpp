#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, p[100005],vis[100005];
vector <int> v[100005], ans;
  
void dfs(int x)
{
    vis[x] = 1;
    for (int i:v[x])
    {
        if (vis[i] == 1)
        {
            ans.push_back(x);
            while (ans.back() != i)
            {
                ans.push_back(p[ans.back()]);
            }
            ans.push_back(x);
            cout << ans.size() << "\n";
            reverse(ans.begin(), ans.end());
            for (int i:ans)
            {
                cout << i << " ";
            }
            exit(0);
        }
        if(vis[i] == 0)
        {
            p[i] = x;
            dfs(i);
        }
        
    }
    vis[x] = 2;
}
  
int main() 
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n ; i++)
    {
        if (!vis[i])
        {
            p[i] = i;
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
}