#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b)
{
    return (a < b);
}
int main()
{
    string a,b;
    int ans[5001][5001];
    cin >> a >> b;
    for(int i = 0 ; i <= a.size() ; i++)
    {
        ans[i][0] = i;
    }
    for(int i = 0 ; i <= b.size() ; i++)
    {
        ans[0][i] = i;
    }
    for(int i = 1 ; i <= a.size() ; i++)
    {
        for(int j = 1 ; j <= b.size() ; j++)
        {
            ans[i][j] = 10000000;
            ans[i][j] = min({ans[i - 1][j - 1] + (a[i - 1] != b[j - 1]) , ans[i - 1][j] + 1 , ans[i][j - 1] + 1},comp);
        }
    }
    cout << ans[a.size()][b.size()];
}
