#include<bits/stdc++.h>
using namespace std;
int c[200005],ans[200005];
vector<int> link[200005];
set<int> dfs(int x , int pre)
{
    set<int> S,temp;
    S.insert(c[x]);
    for(int i : link[x])
    {
        if(i == pre)
        {
            continue;
        }
        temp = dfs(i,x);
        if(temp.size() > S.size())
        {
            swap(temp,S);
        }
        for(int j : temp)
        {
            S.insert(j);
        }
    }
    ans[x] = S.size();
    return S;
}
int main()
{
    int n,a,b;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> c[i];
    }
    for(int i = 1 ; i <= n - 1 ; i++)
    {
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1 ; i <= n ; i++)
    {
        cout << ans[i] << " ";
    }
}
