#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int main()
{
    int n,k,now = 0,mid;
    cin >> n >> k;
    vector<int> p(n);
    map<int,int> num;
    oset<pair<int,int>>q;
    mid = (k+1) / 2;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        q.insert({p[i],i});
        if(q.size() == k)
        {
            cout << (*q.find_by_order(mid - 1)).first << " ";
            q.erase({p[now],now});
            now++;
        }
    }
}
