#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t,temp;
    multiset<int>h;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        h.insert(temp);
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> t;
        if( h.upper_bound(t) == h.begin())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << *(--h.upper_bound(t)) << endl;
            h.erase(--h.upper_bound(t));
        }
    }
}
