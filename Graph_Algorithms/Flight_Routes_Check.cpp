#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[200005] = {0};
vector<int> edge[200005][2];
void dfs(int x , int u)
{
    vis[x] = 1;
    for(int i : edge[x][u])
    {
        if(!vis[i])
        {
            dfs(i,u);
        }
    }
}
int main()
{
    int a,b;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        edge[a][0].push_back(b);
        edge[b][1].push_back(a);
    }
    dfs(1,0);
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            cout << "NO\n";
            cout << "1" << " " << i;
            return 0;
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(1,1);
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            cout << "NO\n";
            cout << i << " " << "1";
            return 0;
        }
    }
    cout << "YES";
}
