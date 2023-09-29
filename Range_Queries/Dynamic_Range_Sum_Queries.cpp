#include<bits/stdc++.h>
using namespace std;
long long int n,q;
array<long long int,200005> x,b;
long long int query(long long int x)
{
    // query prefix sum in BIT
    long long int ret = 0;
    while (x)
    {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void update(long long int x, long long int d)
{
    // update prefix sum in BIT
    while(x <= 200004)
    {
        b[x] += d;
        x += x & (-x);
    }
}
int main()
{
    long long int a,b,c;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
        update(i,x[i]);
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            update(b, c - x[b]);
            x[b] = c;
        }
        else
        {
            cout << query(c) - query(b-1) << "\n";
        }
    }
}
