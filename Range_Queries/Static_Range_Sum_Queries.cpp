#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
    int n,q,a,b,x;
    cin >> n >> q;
    vector<int> sum(n+1);
    sum[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        sum[i] = sum[i-1] + x;
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
}
