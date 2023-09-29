#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,x,k,p[200005][20] = {0};
    cin >> n >> q;
    for(int i = 2 ; i <= n ; i++)
    {
        cin >> p[i][0];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> x >> k;
        for(int i = 0 ; i < 20 ; i++)
        {
            if(k & (1<<i))
            {
                x = p[x][i];
            }
        }
        if(!x)
        {
            cout << "-1" << "\n";
        }
        else
        {
            cout << x << "\n";
        }
    }
}
