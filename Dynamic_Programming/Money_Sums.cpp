#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,num = 0;
    cin >> n;
    vector<int> p(n);
    vector<int> ans(150000,0),ans1(150000);
    set<int> true_ans;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i];
    }
    ans[0] = 1;
    num = 0;
    for(int i = 0 ; i < n ; i++)
    {
        num += p[i];
        ans1 = ans;
        for(int j = 1 ; j <= num; j++)
        {
            if(j - p[i] >= 0 && ans[j - p[i]] > 0)
            {
                ans1[j] = ans[j] + ans[j - p[i]];
                true_ans.insert(j);
            }
        }
        ans = ans1;
    }
    cout << true_ans.size() << endl;
    for(auto i = true_ans.begin() ; i != true_ans.end() ; i++)
    {
        cout << *i << " ";
    }
}
