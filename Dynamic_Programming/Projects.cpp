#include<bits/stdc++.h>
#define int long long
using namespace std;
struct project
{
    int start;
    int fin;
    int reward;
};
bool cmp(const project &a, const project &b)
{
    if(a.fin != b.fin)
    {
        return a.fin < b.fin;
    }
    else if(a.start != b.start)
    {
        return a.start < b.start;
    }
    else
    {
        return a.reward < b.reward;
    }
}
signed main()
{
    int n,ans = 0;
    cin >> n;
    vector<project> p(n);
    set<pair<int,int>>q;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i].start >> p[i].fin >> p[i].reward;
    }
    sort(p.begin(),p.end(),cmp);
    vector<int> dp(n);
    for(int i = 0 ; i < n ; i++)
    {
        dp[i] = p[i].reward;
        if(!q.empty())
        {
            auto it = q.lower_bound({p[i].start,0});
            it--;
            while((*it).first >= p[i].start && it != q.begin())
            {
                it--;
                //cout<< i << (*it).first << " ";
            }
            //cout << endl;
            if((*it).first < p[i].start)
            {
                dp[i] = (*it).second + p[i].reward;
            }
            //cout << i << " " << (*it).first << endl;
        }
        ans = max(ans,dp[i]);
        q.insert({p[i].fin , ans});
        //cout << q.size() << " ";
    }
    cout << ans;
}
