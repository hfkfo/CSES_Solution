#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int>p;
    for(int i = 1 ; i <= n ; i++)
    {
        p.insert(i);
    }
    auto now = ++p.begin();
    while (p.size() > 1)
    {
        cout << *now <<" ";
        p.erase(*now);
        now = p.upper_bound(*now);
        if(now == p.end())
        {
            now = ++p.begin();
            continue;
        }
        if(now == --p.end())
        {
            now = p.begin();
            continue;
        }
        now++;
    }
    cout << *p.begin() << endl;
 
}
