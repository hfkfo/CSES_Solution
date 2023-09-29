#include<bits/stdc++.h>
#define SZ 200005
using namespace std;
vector<int> edge[SZ];
int depth[SZ] = {0},pre[21][SZ] = {0};
void dfs(int n , int p , int d)
{
    depth[n] = d;
    pre[0][n] = p;
    for(int i : edge[n])
    {
        if(i != p)
        {
            dfs(i,n,d+1);
        }
    }
}
int slove(int p ,int q)
{
    if(depth[p] < depth[q])
    {
        swap(p,q);
    }
    int diff = depth[p] - depth[q];
    for(int i = 0 ; i <= 20 ; i++)
    {
        if(diff & (1<<i))
        {
            p = pre[i][p];
        }
    }
    if(p == q)
    {
        return p;
    }
    for(int i = 20 ; i >= 0 ; i--)
    {
        if(pre[i][q] != pre[i][p])
        {
            p = pre[i][p];
            q = pre[i][q];
        }
    }
    return pre[0][p];
}
int main()
{
    int n,q,a,b;
    cin >> n >> q;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,-1,0);
    for(int i = 1 ; 1<<i <= n ; i++)
    {
        for(int j = 0 ; j <= n ; j++)
        {
            pre[i][j] = pre[i-1][pre[i-1][j]];
        }
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b;
        int c = slove(a,b);
        cout << depth[a] + depth[b] - 2*depth[c] << endl;
    }
}