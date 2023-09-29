#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,m,ans;
    cin>>n;
    a = 1;
    ans = 1;
    m = pow(10,9) + 7;
    a %= m;
    while (n > 0) {
        a = 2 * a % m;
        if (n == 1)
        {
            ans = ans * a % m;
        }
        n--;
    }
    cout<<ans<<endl;
    return 0;
}
