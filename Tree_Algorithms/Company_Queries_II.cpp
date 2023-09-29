#include<bits/stdc++.h>
using namespace std;
int deep[200005] = {0};
vector<int> link[200005];
void dfs(int i,int d)
{
    deep[i] = d;
    for(int u : link[i])
    {
        dfs(u,d+1);
    }
}
int main()
{
    int n,q,a,b;
    cin >> n >> q;
    int ans[n+1][21] = {0};
    for(int i = 2 ; i <= n ; i++)
    {
        cin >> ans[i][0];
        link[ans[i][0]].push_back(i);
    }
    dfs(1,0);
    for(int i = 1 ; i <= 20 ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            ans[j][i] = ans[ans[j][i-1]][i-1];
        }
    }
    while(q--)
    {
        cin >> a >> b;
        if(deep[a] < deep[b])
        {
            swap(a,b);
        }
        int dif = deep[a] - deep[b];
        for(int i = 0 ; i <= 20 ; i++)
        {
            if(dif & (1<<i))
            {
                a = ans[a][i];
            }
        }
        if(a == b)
        {
            cout << a << "\n";
            continue;
        }
        //cout << a << " " << b << "\n";
        for(int i = 20 ; i >= 0 ; i--)
        {
            if(ans[a][i] != ans[b][i])
            {
                a = ans[a][i];
                b = ans[b][i];
            }
        }
        cout << ans[a][0] << "\n";
    }
}
