#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans = 0,now_num;
    cin >> n;
    now_num = n;
    while(now_num / 5 != 0)
    {
        now_num = now_num / 5;
        ans += now_num;
    }
    cout << ans << endl;
}