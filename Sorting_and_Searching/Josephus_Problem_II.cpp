#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int main()
{
    int n,k;
    cin >> n >> k;
    int p =k % n ;
    oset<int> a ;
    for(int i = 1 ; i <= n ; i++)
    {
        a.insert(i) ;
    }
    while(a.size())
    {
        int r = *a.find_by_order(p) ;
        a.erase(r) ;
        if(a.size())
        {
            p = ( p + k ) % a.size() ;
        }
        cout << r << " " ;
    }
}