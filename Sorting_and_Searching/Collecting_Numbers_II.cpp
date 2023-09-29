#include<bits/stdc++.h>
using namespace std;
int x[200004],y[200004];
int judge(int a,int b)
{
    int sum = 0;
    if(x[a - 1] > x[a])
    {
        sum++;
    }
    if(x[a + 1] < x[a])
    {
        sum++;
    }
    if(x[b - 1] > x[b])
    {
        sum++;
    }
    if(x[b + 1] < x[b])
    {
        sum++;
    }
    if(a - b == 1 && x[a] < x[b])
    {
        sum--;
    }
    if(b - a == 1 && x[b] < x[a])
    {
        sum--;
    } 
    return sum;
}
int main()
{
    int n,m,temp,ans = 1,a,b;
    cin >> n >> m;
    x[n + 1] = n + 1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> temp;
        x[temp] = i;
        y[i] = temp;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ans += x[i] < x[i - 1];
    }
    for(int j = 0 ; j < m ; j++)
    {
        cin >> a >> b;
        swap(y[a],y[b]);
        a = y[a];
        b = y[b];
        ans -= judge(a,b);
        swap(x[a],x[b]);
        ans += judge(a,b);
        cout << ans << "\n";
    }
    
}
