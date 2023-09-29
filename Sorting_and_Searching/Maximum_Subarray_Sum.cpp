#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans = -10000000000,sum = 0,x;
    cin >> n;
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> x;
        sum+= x;
        if(ans < sum)
        {
            ans = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    cout << ans << endl;
}
