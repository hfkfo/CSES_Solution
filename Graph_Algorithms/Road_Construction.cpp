#include<bits/stdc++.h>
using namespace std;
int n,m,p[100005],mx,gp,a,b;
int c(int x)
{
    if(p[x] < 0)
    {
        return x;
    }
    else
    {
        return p[x] = c(p[x]);
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(p,-1,sizeof(p));
    mx = 1;
    gp = n;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> a >> b;
        a = c(a);
        b = c(b);
        if(a != b)
        {
            p[a] += p[b];
            mx = max(mx,-p[a]);
            p[b] = a;
            gp--;
        }
        cout << gp << " " << mx << "\n";
    }
}
