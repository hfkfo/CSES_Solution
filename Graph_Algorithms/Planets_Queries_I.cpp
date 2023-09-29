#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    int n,q,x,k,p[200005][31];
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p[i][0];
    }
    for(int i = 1 ; i < 30 ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> x >> k;
        for(int i = 0 ; i < 30 ; i++)
        {
            if(k & (1<<i))
            {
                x = p[x][i];
            }
        }
        cout << x << "\n";
    }
}
