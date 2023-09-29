#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q;
int val[200005];
struct Node
{
    int sum;
    int prefix;
}node[200005*4];
void build(int x,int left,int right)
{
    if(left == right)
    {
        node[x].sum = val[left];
        node[x].prefix = val[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2*x,left,mid);
    build(2*x+1,mid+1,right);
    node[x].sum = node[2*x].sum + node[2*x+1].sum;
    node[x].prefix = max(node[2*x].prefix,node[2*x].sum + node[2*x+1].prefix);
}
void update(int i , int k , int x ,int left ,int right)
{
    if(left == right)
    {
        node[x].sum = k;
        node[x].prefix = k;
        return;
    }
    int mid = (left + right) / 2;
    if(i <= mid)
    {
        update(i,k,2*x,left,mid);
    }
    else
    {
        update(i,k,2*x+1,mid+1,right);
    }
    node[x].sum = node[2*x].sum + node[2*x+1].sum;
    node[x].prefix = max(node[2*x].prefix,node[2*x].sum + node[2*x+1].prefix);
}
Node query(int ql,int qr,int x,int left,int right)
{
    Node ans;
    ans.prefix = ans.sum = 0;
    if(qr < left || ql > right)
    {
        return ans;
    }
    if(ql <= left && qr >= right)
    {
        return node[x];
    }
    int mid = (left + right) / 2;
    Node p = query(ql,qr,2*x,left,mid);
    Node q = query(ql,qr,2*x+1,mid+1,right);
    ans.sum = p.sum + q.sum;
    ans.prefix = max(p.prefix,p.sum + q.prefix);
    return ans;
}
signed main()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> val[i];
    }
    build(1,1,n);
    int type,a,b;
    while(q--)
    {
        cin >> type >> a >> b;
        if(type == 1)
        {
            update(a,b,1,1,n);
        }
        else
        {
            int ans = query(a,b,1,1,n).prefix;
            if(ans >= 0)
            {
                cout << ans << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }
}
