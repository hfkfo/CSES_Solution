#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,a,b;
    cin >> n >> q;
    int x[n+1] = {0},ans[n+1] = {0};
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> x[i];
    }
    ans[1] = x[1];
    for(int i = 2 ; i<= n ;i++)
    {
        ans[i] = ans[i-1]^x[i];
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b;
        cout << (ans[b]^ans[a-1]) << endl;
    }
}
