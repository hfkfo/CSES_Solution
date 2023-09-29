#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp,ans = 1;
    cin >> n;
    map<int,int>x;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        x[temp] = i;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ans += x[i] < x[i - 1];
    }
    cout << ans << endl;
}