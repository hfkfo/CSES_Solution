#include<bits/stdc++.h>
using namespace std;
array<char,48> S;
array<array<bool, 9>, 9> visit;
int ans = 0;
void dfs(int x,int y ,int s)
{
    if(x < 1 || x > 7 || y < 1 || y > 7 || visit[x][y])
    {
        return;
    }
    if(x == 1 && y == 7){
        if(s == 48) 
        {
            ans++;
        }
        return;
    }
    if(!visit[x - 1][y] && !visit[x + 1][y] && visit[x][y - 1] && visit[x][y + 1]) 
    {
        return;
    }
    if(visit[x - 1][y] && visit[x + 1][y] && !visit[x][y - 1] && !visit[x][y + 1]) 
    {
        return;
    }
    visit[x][y] = 1;
    if(S[s] == '?' || S[s] == 'L') 
    {
        dfs(x - 1, y, s + 1);
    }
    if(S[s] == '?' || S[s] == 'R')
    {
        dfs(x + 1, y, s + 1);
    } 
    if(S[s] == '?' || S[s] == 'U') 
    {
        dfs(x, y - 1, s + 1);
    }
    if(S[s] == '?' || S[s] == 'D') 
    {
        dfs(x, y + 1, s + 1);
    }
    visit[x][y] = 0;
}
int main()
{
    for(int i = 0; i < 48; i++){
        cin >> S[i];
    }
    for(int i = 1; i <= 7; i++){
        visit[0][i] = 1;
        visit[i][0] = 1;
        visit[8][i] = 1;
        visit[i][8] = 1;
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}