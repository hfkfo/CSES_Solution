#include<bits/stdc++.h>
using namespace std;
bool visit[200005] = {0};
int next_planet[200005];
int path_long[200005] = {0};
int step;
queue<int>q;
void dfs(int planet)
{
    q.push(planet);
    if(visit[planet])
    {
        step += path_long[planet];
        return;
    }
    visit[planet] = true;
    step++;
    dfs(next_planet[planet]);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> next_planet[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visit[i])
        {
            x = 1;
            step = 0;
            dfs(i);
            while (!q.empty())
            {
                if(q.front() == q.back())
                {
                    x = 0;
                }
                path_long[q.front()] = step;
                step -= x;
                q.pop();
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cout << path_long[i] << " ";
    }
}
