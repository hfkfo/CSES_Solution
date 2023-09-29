#include<bits/stdc++.h>
using namespace std;
long long int n,q,bit[200005] = {0};
void update(long long int x , long long int d)
{
    while (x <= n)
    {
        bit[x] += d;
        x += x & (-x);
    }
}
long long int query(long long int x)
{
    long long ret = 0;
    while (x){
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}
int main()
{
    long long int pre = 0,x,type,a,b,u,k;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        update(i,x - pre);
        pre = x;
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b >> u;
            update(a,u);
            update(b+1,-u);
        }
        else
        {
            cin >> k;
            cout << query(k) << endl;
        }
    }
}
