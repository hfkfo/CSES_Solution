#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans = 0,vis[200001];
vector<int> v[200001];
void dfs(int x, int pre)
{
    for (auto i:v[x])
    {
        if (i == pre)
        {
            continue;
        } 
        dfs(i, x);
        if (!vis[i] && !vis[x]){
            vis[i] = vis[x] = 1;
            ans++;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout << ans;
}
