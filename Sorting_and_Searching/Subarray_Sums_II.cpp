#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,sum = 0,ans = 0,last = 0;
    cin >> n >> x;
    vector<long long int> p(n);
    map<long long int,long long int> q;
    q[0] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        sum += p[i];
        ans += q[sum - x];
        q[sum]++;
    }
    cout << ans;
}
