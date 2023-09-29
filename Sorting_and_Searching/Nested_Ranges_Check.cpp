#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
struct Qus{
    int fst;
    int fin;
    int order;
};
 
bool cmp( Qus a, Qus b)
{
    if(a.fst != b.fst)
    {
        return a.fst < b.fst;
    }
    else
    {
        return a.fin > b.fin;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<struct Qus> x(n);
    oset<array<int,2>> a,b;
    vector<int> A(n),B(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i].fst >> x[i].fin ;
        x[i].order = i;
    }
    sort(x.begin(),x.end(),cmp);
    for(int i = 0 , j = n -1 ; i < n ; i++ , j--)
    {
        A[x[j].order] = a.order_of_key({x[j].fin,n});
        B[x[i].order] = i - b.order_of_key({x[i].fin,-1});
        a.insert({x[j].fin,j});
        b.insert({x[i].fin,i});
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << !!A[i] << " ";
    }
    cout << "\n";
    for(int i = 0 ; i < n ; i++)
    {
        cout << !!B[i] << " ";
    }
}