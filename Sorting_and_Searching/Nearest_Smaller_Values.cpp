#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin >> n;
    vector<pair<int,int>> p;
    p.push_back(make_pair(0,0));
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> temp;
        while (p[p.size() - 1].first >= temp)
        {
            p.pop_back();
        }
        cout << p[p.size() - 1].second << " ";
        p.push_back(make_pair(temp,i));
    }
}
