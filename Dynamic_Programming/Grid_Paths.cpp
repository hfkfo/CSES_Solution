#include<bits/stdc++.h>
#define int long long
using namespace std;
int visit1[2000][2000] = {0};
signed main()
{
    int n,mod = 1000000007;
    cin >> n;
    char m[n+2][n+2];
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> m[i][j];
            if(m[i][j] == '*')
            {
                visit1[i][j] = -1;
            }
        }
    }
    if(visit1[1][1] == -1 || visit1[n][n] == -1)
    {
        cout << "0";
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == 1 && j ==1)
            {
                visit1[1][1] = 1;
            }
            else if(visit1[i][j] != -1)
            {
                if( i - 1 > 0 && visit1[i - 1][j] >= 0)
                {
                    visit1[i][j] = (visit1[i][j] + visit1[i - 1][j]) % mod;
                }
                if( j - 1 > 0 && visit1[i][j - 1] >= 0)
                {
                    visit1[i][j] = (visit1[i][j] + visit1[i][j - 1]) % mod;
                }
            }
        }
    }
    cout << visit1[n][n];
}
