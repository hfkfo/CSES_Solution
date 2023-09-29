#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin >> n;
    vector<int> ans;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x;
        if(ans.empty() || ans.back() < x)
        {
            ans.push_back(x);
        }
        else
        {
            *lower_bound(ans.begin(), ans.end(), x) = x;
        }
    }
    cout << ans.size();
}
