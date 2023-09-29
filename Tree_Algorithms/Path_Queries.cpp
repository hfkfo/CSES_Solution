#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>link[200005];
int in[200005] = {0},out[200005] = {0},bit[200005] = {0};
int idx = 0,n;
void dfs(int i , int pre)
{
    idx++;
    in[i] = idx;
    for(int k : link[i])
    {
        if(k != pre)
        {
            dfs(k,i);
        }
    }
    out[i] = idx;
}
void update(int x,int val)
{
    for(int i = x ; i <= n ; i += i & (-i))
    {
        bit[i] += val;
    }
}
int query(int x)
{
    int ret = 0;
    for(int i = x ; i >= 1 ; i -= i & (-i))
    {
        ret += bit[i];
    }
    return ret;
}
signed main()
{
    int q,a,b,type;
    cin >> n >> q;
    int val[n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> val[i];
    }
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1 ; i <= n ; i++)
    {
        update(in[i],val[i]);
        update(out[i]+1,-val[i]);
    }
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b;
            update(in[a],b-val[a]);
            update(out[a]+1,val[a] - b);
            val[a] = b;
        }
        else
        {
            cin >> a;
            cout << query(in[a]) << "\n";
        }
    }
}
