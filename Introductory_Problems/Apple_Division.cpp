#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n ,temp,a,b;
    long long int ans = 2e10;
    vector<int> p;
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    for(long long int i = 0 ; i < 1<<n ; i++)
    {
        a = b = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) a += p[j];
            else b += p[j];
        }
        if(ans > abs(a-b))
        {
            ans = abs(a-b);
        }
    }
    cout << ans << endl;
}
