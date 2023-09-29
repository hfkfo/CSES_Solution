#include<bits/stdc++.h>
using namespace std;
int X[200005],bit[200005];
map<int,int> P;
struct qus_range
{
    int num;
    int fst;
    int fin;
};
vector<qus_range> qus;
bool cmp(qus_range &a , qus_range &b)
{
    return a.fin < b.fin;
}
void update(int x , int val)
{
    for(int i = x ; i <= 200005 ; i += i & (-i))
    {
        bit[i] += val;
    }
}
int query(int x)
{
    int sum = 0;
    for(int i = x ; i > 0 ; i -= i & (-i))
    {
        sum += bit[i];
    }
    return sum;
}
int main()
{
    int n,q,a,b,p = 0;
    cin >> n >> q;
    int ans[n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> X[i];
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b;
        qus.push_back({i,a,b});
    }
    sort(qus.begin(),qus.end(),cmp);
    for(int i = 1 ; i <= n ; i++)
    {
        if(P[X[i]])
        {
            update(P[X[i]],-1);
        }
        P[X[i]] = i;
        update(i,1);
        while (p <= qus.size() && i == qus[p].fin)
        {
            ans[qus[p].num] = query(qus[p].fin) - query(qus[p].fst - 1);
            p++;
        }
    }
    for(int i = 0 ; i < q ; i++)
    {
        cout << ans[i] << " ";
    }
}
