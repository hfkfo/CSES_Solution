#include<bits/stdc++.h>
using namespace std;
int n,cen;
vector<int>link[200005];
int dfs(int x , int pre)
{
    int s = 1 , mux = 0 , temp;
    for(int i : link[x])
    {
        if(i == pre)
        {
            continue;
        }
        temp = dfs(i,x);
        s += temp;
        mux = max(mux,temp);
    }
    if(mux <= n / 2 && n - s <= n / 2)
    {
        cen = x;
    }
    return s;
}
int main()
{
    int a,b;
    cin >> n;
    for(int i = 1 ; i <= n - 1; i++)
    {
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    dfs(1,0);
    cout << cen;
}
