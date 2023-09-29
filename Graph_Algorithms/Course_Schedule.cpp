#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    int pre[n + 1] = {0};
    vector<int> v[n + 1],ans;
    queue<int>q;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        pre[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == 0) 
        {
            q.push(i);
        }
        //cout << pre[i] << endl;
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for (int i:v[now])
        {
            pre[i]--;
            if (pre[i] == 0)
            {
                q.push(i);
            } 
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
    } 
    else
    {
        for (int i:ans)
        {
            cout << i << " ";
        }
    }
}
