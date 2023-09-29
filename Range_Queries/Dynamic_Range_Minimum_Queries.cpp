#include<bits/stdc++.h>
using namespace std;
int n,q,mn[200005*4];
void update(int x , int left ,int right , int now , int u)
{
    if(left == right)
    {
        mn[x] = u;
        return;
    }
    int mid = (left + right) / 2;
    if(now <= mid)
    {
        update(2*x,left,mid,now,u);
    }
    else
    {
        update(2*x+1,mid+1,right,now,u);
    }
    mn[x] = min(mn[2*x],mn[2*x+1]);
}
int query(int x ,int left ,int right ,int a ,int b)
{
    if(a <= left && b >= right)
    {
        return mn[x];
    }
    int mid = (left + right) / 2;
    int ret = 1000000000;
    if(a <= mid)
    {
        ret = min(ret,query(2*x,left,mid,a,b));
    }
    if(mid < b)
    {
        ret = min(ret,query(2*x+1,mid+1,right,a,b));
    }
    return ret;
}
int main()
{
    cin >> n >> q;
    int x,type,a,b;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        update(1,1,n,i,x);
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> type >> a >> b;
        if(type == 1)
        {
            update(1,1,n,a,b);
        }
        else
        {
            cout << query(1,1,n,a,b) << "\n";
        }
    }
}
