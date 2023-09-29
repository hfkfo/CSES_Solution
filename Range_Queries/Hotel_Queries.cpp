#include<bits/stdc++.h>
using namespace std;
int n,q,mn[200005*4],h[200005];
void update(int x , int left ,int right , int u)
{
    if(left == right)
    {
        mn[x] = h[u];
        return;
    }
    int mid = (left + right) / 2;
    if(u <= mid)
    {
        update(2*x,left,mid,u);
    }
    else
    {
        update(2*x+1,mid+1,right,u);
    }
    mn[x] = max(mn[2*x],mn[2*x+1]);
}
int query(int x ,int left ,int right ,int now)
{
    if(left == right)
    {
        return left;
    }
    int mid = (left + right) / 2;
    if(mn[2*x] >= now)
    {
        return query(2*x,left,mid,now);
    }
    else
    {
        return query(2*x+1,mid+1,right,now);
    }
}
int main()
{
    cin >> n >> q;
    int x,r;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> h[i];
        update(1,1,n,i);
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> r;
        if(r > mn[1])
        {
            cout << "0" << " ";
        }
        else
        {
            int index = query(1,1,n,r);
            cout << index << " ";
            h[index] -= r;
            update(1,1,n,index);
        }
    }
}
