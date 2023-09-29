#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,ans = 0,now = 0;
    map<int,int> time;
    vector<int> order;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        time[a]++;
        time[b]--;
        order.push_back(a);
        order.push_back(b);
    }
    sort(order.begin(),order.end());
    auto min = order.begin();
    while(min < order.end())
    {
        now+=time[*min];
        if( ans < now )
        {
            ans = now;
        }
        min++;
    }
    cout << ans << endl;
    
}
