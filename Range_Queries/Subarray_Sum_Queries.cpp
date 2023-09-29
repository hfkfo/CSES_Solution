#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q;
int val[200005];
struct Node
{
    int sum;
    int prefix;
    int suffix;
    int max1;
}node[200005*4];
void build(int x,int left,int right)
{
    if(left == right)
    {
        node[x].sum = val[left];
        node[x].prefix = val[left];
        node[x].max1 = val[left];
        node[x].suffix = val[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2*x,left,mid);
    build(2*x+1,mid+1,right);
    node[x].sum = node[2*x].sum + node[2*x+1].sum;
    node[x].prefix = max(node[2*x].prefix,node[2*x].sum + node[2*x+1].prefix);
    node[x].suffix = max(node[2*x+1].suffix,node[2*x+1].sum + node[2*x].suffix);
    node[x].max1 = max(node[2*x].suffix + node[2*x+1].prefix , node[2*x].max1);
    node[x].max1 = max(node[x].max1 , node[2*x+1].max1);
}
void update(int i , int k , int x ,int left ,int right)
{
    if(left == right)
    {
        node[x].sum = k;
        node[x].prefix = k;
        node[x].suffix = k;
        node[x].max1 = k;
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
    node[x].suffix = max(node[2*x+1].suffix,node[2*x+1].sum + node[2*x].suffix);
    node[x].max1 = max(node[2*x].suffix + node[2*x+1].prefix , node[2*x].max1);
    node[x].max1 = max(node[x].max1 , node[2*x+1].max1);
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
        cin >> a >> b;
        update(a,b,1,1,n);
        val[a] = b;
        if(node[1].max1 > 0)
        {
            cout << node[1].max1 << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}
