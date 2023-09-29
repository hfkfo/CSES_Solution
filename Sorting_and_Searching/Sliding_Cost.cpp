#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
oset<pair<long long int,long long int>> p;
long long int judge(long long int mid)
{
    long long int ans = 0;
    for(int i = 0 ; i < p.size() ; i++)
    {
        ans += abs((*p.find_by_order(i)).first - mid);
    }
    return ans;
}
int main()
{
    long long int n,k,now = 0,ans = 0,mid = 0,temp,temp1,fst = 0,mid1,temp2;
    cin >> n >> k;
    vector<long long int> q(n);
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> q[i];
        p.insert({q[i],i});
        if(p.size() == k)
        {
            if(k % 2 == 0)
            {
                mid = (*p.find_by_order((k / 2) - 1)).first + (*p.find_by_order((k / 2) )).first;
                mid /= 2;
                if(fst == 0)
                    ans = judge(mid);
                else
                {
                    p.erase({q[i],i});
                    if(mid > mid1)
                    {
                        temp = p.order_of_key({mid1,n});
                        temp1 = p.size() - p.order_of_key({mid,-1});
                        ans = ans + temp*(mid - mid1) - temp1*(mid - mid1);
                        for(long long int j = temp  ; j < p.order_of_key({mid,-1}) ; j++)
                        {
                            ans = ans - abs((*p.find_by_order(j)).first - mid1) + abs((*p.find_by_order(j)).first - mid);
                        }
                    }
                    else if(mid < mid1)
                    {
                        temp = p.order_of_key({mid,n});
                        temp1 = p.size() - p.order_of_key({mid1,-1});
                        ans = ans - temp*(mid1 - mid) + temp1*(mid1 - mid);
                        for(long long int j = temp  ; j < p.order_of_key({mid1,-1}) ; j++)
                        {
                            ans = ans - abs((*p.find_by_order(j)).first - mid1) + abs((*p.find_by_order(j)).first - mid);
                        }
                    }
                    ans = ans - abs(q[now - 1] - mid1) + abs(q[i] - mid);
                    p.insert({q[i],i});
                }
            }
            else
            {
                mid = (*p.find_by_order(k / 2)).first;
                ans = judge(mid);
            }
            cout << ans << " ";
            p.erase({q[now],now});
            now++;
            fst = 1;
            mid1 = mid;
        }
    }
}
