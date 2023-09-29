#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,sum = 0,ans = 0,last = 0;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        sum += p[i];
        while(sum > x)
        {
            sum -= p[last];
            last++;
        }
        if(sum == x)
        {
            ans++;
        }
    }
    cout << ans;
}
