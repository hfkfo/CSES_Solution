#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp,ans = 0,now = 0;
    vector<int> k;
    set<int> S;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        k.push_back(temp);
        while ( S.find(k[i]) != S.end())
        {
            S.erase(k[now++]);
        }
        S.insert(k[i]);
        if(S.size() > ans)
        {
            ans =S.size();
        }
    }
    cout << ans << endl;
}
