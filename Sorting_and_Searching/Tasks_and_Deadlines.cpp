#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b,now = 0,ans = 0;
    cin >> n;
    vector<pair<long long int,long long int>> p;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        p.push_back(make_pair(a,b));
    }
    sort(p.begin(),p.end());
    for(int i = 0 ; i < n ; i++)
    {
        now += p[i].first;
        ans += (p[i].second - now);
    }
    cout << ans;
}
