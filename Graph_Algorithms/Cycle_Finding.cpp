#include<bits/stdc++.h>
#define int long long
using namespace std;
array<int,2600> val,pre;
struct V
{
    int start;
    int fin;
    int val;
};
signed main()
{
    int n,m,a,b,c,v;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        val[i] = 1e18;
    }
    vector<V> q(m + 1);
    vector<int> ans;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        q[i].start = a;
        q[i].fin = b;
        q[i].val = c;
    }
    for(int i = 0 ; i <= n ; i++)
    {
        c = 0;
        for(auto j : q)
        {
            if(val[j.fin] > val[j.start] + j.val)
            {
                val[j.fin] = val[j.start] + j.val;
                pre[j.fin] = j.start;
                c = j.fin;
            }
        }
    }
    if(c)
    {
        cout << "YES\n";
        while(n--)
        {
            c = pre[c];
        }
        ans.push_back(c);
        v = pre[c];
        while(v != c)
        {
            ans.push_back(v);
            v = pre[v];
        }
        ans.push_back(c);
        reverse(ans.begin(),ans.end());
        for(auto i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
