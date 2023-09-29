#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    multiset<int> S;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        if(S.upper_bound(temp) != S.end())
        {
            S.erase(S.upper_bound(temp));
            S.insert(temp);
        }
        else
        {
            S.insert(temp);
        }
    }
    cout << S.size() << endl;
}
