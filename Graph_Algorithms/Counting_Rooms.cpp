#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
char room[1001][1001];
void dfs(int x ,int y)
{
    room[x][y] = '#';
    if(room[x + 1][y] == '.' && x + 1 < n)
    {
        dfs(x + 1,y);
    }
    if(room[x - 1][y] == '.' && x - 1 >= 0)
    {
        dfs(x - 1,y);
    }
    if(room[x][y + 1] == '.' && y + 1 < m)
    {
        dfs(x,y + 1);
    }
    if(room[x][y - 1] == '.' && y - 1 >= 0)
    {
        dfs(x,y - 1);
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> room[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(room[i][j] == '.')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
}
