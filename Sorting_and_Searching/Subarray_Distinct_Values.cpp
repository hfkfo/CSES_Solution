#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,fst = 0,ans = 0;
    cin >> n >> k;
    vector<long long int> p(n);
    map<long long int,long long int> q;
    map<long long int,long long int>::iterator it;
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> p[i];
    }
    for(long long int i = 0 ; i < n ; i++)
    {
        while( fst < n && (q.size() < k || q.count(p[fst]) > 0))
        {
            q[p[fst]]++;
            fst++;
        }
        ans += fst - i;
        q[p[i]]--;
        if(q[p[i]] == 0)
        {
            q.erase(p[i]);
        }
    }
    cout << ans ;
}
