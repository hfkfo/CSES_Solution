#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    long long int n,m,a,b;
    cin >> n >> m;
    vector<long long int> v[n];
    long long int in[n+1] = {0},ans[n+1] = {0};
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    queue<long long int>q;
    ans[1] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!in[i])
        {
            q.push(i);
        }
    }
    while (q.front() != n)
    {
        int now = q.front();
        q.pop();
        for(int i : v[now])
        {
            if(in[i])
            {
                ans[i] += ans[now];
                ans[i] %= mod;
                in[i]--;
                if(!in[i])
                {
                    q.push(i);
                }
            }
        }
 
    }
    cout << ans[n];
}
