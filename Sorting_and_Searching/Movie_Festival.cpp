#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int n,a,b,ans = 0,now;
    vector<pair<int,int>> time;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        time.push_back(make_pair(a,b));
    }
    sort(time.begin(),time.end(),cmp);
    now = time.at(0).second;
    ans++;
    for(int i = 1 ; i < n ; i++)
    {
        if(time.at(i).first >= now)
        {
            now = time.at(i).second;
            ans++;
        }
    }
    cout << ans << endl;
}
