#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
signed main()
{
    int n,q;
    cin >> n >> q;
    int p[n+1];
    oset<pair<int,int>> ans;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
        ans.insert({p[i],i});
    }
    char a;
    int b,c;
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b >> c;
        if(a == '!')
        {
            ans.erase({p[b],b});
            p[b] = c;
            ans.insert({p[b],b});
        }
        else if(a == '?')
        {
            int k = ans.order_of_key({c,n+1});
            int j = ans.order_of_key({b,0});
            cout << k - j << "\n";
        }
    }
}
