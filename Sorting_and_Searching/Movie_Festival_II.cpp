#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}
int main()
{
    int n,k,a,b,ans = 0,now;
    vector<pair<int,int>> time;
    multiset<int> q;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        time.push_back(make_pair(a,b));
    }
    sort(time.begin(),time.end(),cmp);
    for(int i = 0 ; i < k ; i++)
    {
        q.insert(0);
    }
    for(int i = 0 ; i < n ; i++)
    {
        auto it = q.upper_bound(time[i].first);
        if(it == q.begin())
        {
            continue;
        }
        q.erase(--it);
        q.insert(time[i].second);
        ans++;
    }
    cout << ans << endl;
}
