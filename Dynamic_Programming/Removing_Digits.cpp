#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,temp;
    cin >> n;
    vector<int> ans(n + 1,1000000000);
    ans[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        temp = i;
        while (temp != 0)
        {
            if(ans[i] > ans[i - temp % 10] + 1)
            {
                ans[i] = ans[i - temp % 10] + 1;
            }
            temp /= 10;
        }
    }
    cout << ans[n];
}
