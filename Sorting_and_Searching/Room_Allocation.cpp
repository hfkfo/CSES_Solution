#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
struct Qus
{
    int arrive;
    int leave;
    int order;
};
bool cmp(const Qus a,const Qus b)
{
    if(a.arrive != b.arrive)
    {
        return a.arrive < b.arrive;
    }
    else
    {
        return a.leave < b.leave;
    }
}
int main()
{
    int n,time = 0;
    cin >> n;
    vector<Qus> p(n);
    vector<int> ans(n);
    oset<pair<int,int>> allocate;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i].arrive >> p[i].leave;
        p[i].order = i;
    }
    sort(p.begin(),p.end(),cmp);
    for(int i = 0 ; i < n ; i++)
    {
        auto it = allocate.order_of_key({p[i].arrive,-1});
        if(it == 0)
        {
            time++;
            ans[p[i].order] = time;
            allocate.insert({p[i].leave,time});
        }
        else
        {
            auto place = allocate.find_by_order(it - 1);
            ans[p[i].order] = (*place).second;
            allocate.insert({p[i].leave,(*place).second});
            allocate.erase(*place);
        }
    }
    cout << time << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << ans[i] << " ";
    }
}