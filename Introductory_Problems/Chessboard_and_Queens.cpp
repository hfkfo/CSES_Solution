#include <bits/stdc++.h>
using namespace std;
array<array<int, 12>, 12> C;
void update(int x, int y, int v){
    for(int i = 1; i <= 8; i++)
    {
        C[x][i] += v;
        C[i][y] += v;
    }
    for(int i = 1; i < 8; i++)
    {
        if(x + i > 8 || y + i > 8) break;
        C[x + i][y + i] += v;
    }
    for(int i = 1; i < 8; i++)
    {
        if(x + i > 8 || y - i < 1) break;
        C[x + i][y - i] += v;
    }
    for(int i = 1; i < 8; i++)
    {
        if(x - i < 1 || y + i > 8) break;
        C[x - i][y + i] += v;
    }
    for(int i = 1; i < 8; i++)
    {
        if(x - i < 1 || y - i < 1) break;
        C[x - i][y - i] += v;
    }
}
int dfs(int n){
    int ans = 0;
    if(!n)
    {
        return 1;
    } 
    for(int i = 1; i <= 8; i++)
    {
        if(C[n][i]) 
        {
            continue;
        }
        update(n, i, 1);
        ans += dfs(n - 1);
        update(n, i, -1);
    }
    return ans;
}
int main()
{
    char c;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cin >> c;
            if(c == '*') 
            {
                C[i][j]++;
            }
        }
    }
    cout << dfs(8);
    return 0;
}
