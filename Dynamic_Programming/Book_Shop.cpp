#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,k,true_ans = 0;
    cin >> n >> k;
    vector<pair<int,int>> book(n);
    vector<int> ans(k + 1,0),ans1(k + 1,0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> book[i].first;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin >> book[i].second;
    }
    for(int j = 0 ; j < n ; j++)
    {
        ans1 = ans;
        for(int i = 1 ; i <= k ; i++)
        {
            if(i - book[j].first == 0 )
            {
                if(ans[i] < book[j].second)
                {
                    ans1[i] = book[j].second;
                }
                if(true_ans < ans1[i])
                {
                    true_ans = ans1[i];
                }
            }
            else if(i - book[j].first > 0 && ans[i - book[j].first] > 0)
            {
                if(ans[i] < ans[i - book[j].first] + book[j].second)
                {
                    ans1[i] = ans[i - book[j].first] + book[j].second;
                }
                if(true_ans < ans1[i])
                {
                    true_ans = ans1[i];
                }
            }
        }
        ans = ans1;
    }
    cout << true_ans;
}
