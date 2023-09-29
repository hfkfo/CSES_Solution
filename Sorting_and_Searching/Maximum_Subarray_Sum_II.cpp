#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,a,b,temp,ans = -10000000000000000;
    cin >> n >> a >> b;
    deque<pair<int,int>> Q;
    array<int, 200004> S;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> temp;
        S[i] = temp + S[i - 1];
        if(!Q.empty() && Q.front().second < i - b)
        {
            Q.pop_front();
        }
        while(i >= a && !Q.empty() && S[i - a] < Q.back().first)
        {
            Q.pop_back();
        }
        if(i >= a)
        {
            Q.push_back({S[i - a], i - a});
        }
        if(!Q.empty())
        {
            ans = max(ans, S[i] - Q.front().first);
        }
    }
    cout << ans;
}
