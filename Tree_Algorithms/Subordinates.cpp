#include<bits/stdc++.h>
using namespace std;
int n,p,ans[200005] = {0};
vector<int> v[200005];
void dfs(int n)
{
    for(auto i : v[n])
    {
        dfs(i);
        ans[n] += ans[i] + 1;
    }
}
int main()
{
    cin >> n;
    for(int i = 2 ; i <= n ; i++)
    {
        cin >> p;
        v[p].push_back(i);
    }
    dfs(1);
    for(int i = 1 ; i <= n ; i++)
    {
        cout << ans[i] << " ";
    }
}
