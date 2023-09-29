#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,max = 505;
    cin >> a >> b;
    int ans[max][max];
    for(int i = 1 ; i <= a ; i++)
    {
        for(int j = 1 ; j <= b ; j++)
        {
            ans[i][j] = 250000;
        }
    }
    for(int i = 1 ; i < max ; i++)
    {
        ans[i][i] = 0;
    }
    for(int i = 1 ; i <= a ; i++)
    {
        for(int  j = 1 ; j <= b ; j++)
        {
            for(int k = 1 ; k < i ; k++)
            {
                if(ans[i][j] > ans[k][j] + ans[i - k][j] + 1)
                {
                    ans[i][j] = ans[k][j] + ans[i - k][j] + 1;
                }
            }
            for(int k = 1 ; k < j ; k++)
            {
                if(ans[i][j] > ans[i][k] + ans[i][j - k] + 1)
                {
                    ans[i][j] = ans[i][k] + ans[i][j - k] + 1;
                }
            }
        }
    }
    cout << ans[a][b];
}
