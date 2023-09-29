#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,sum = 0,ans = 0,p;
    cin >> n ;
    map<long long int,long long int> q;
    q[0]++;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p;
        sum += p % n;
        sum = (sum + n) % n;
        ans += q[sum];
        q[sum]++;
    }
    cout << ans;
}
