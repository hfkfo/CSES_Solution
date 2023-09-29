#include<bits/stdc++.h>
using namespace std;
struct two_sum
{
    int sum;
    int one;
    int two;
};
bool cmp(const two_sum &a , const two_sum &b)
{
    if(a.sum != b.sum)
    {
        return a.sum < b.sum;
    }
    else if(a.one != b.one)
    {
        return a.one < b.one;
    }
    else
    {
        return a.two < b.two;
    }
}
int main()
{
    int n,x,time = 0;
    cin >> n >> x;
    vector<int> p(n + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
    }
    vector<two_sum> q;
    two_sum a;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i + 1 ; j <= n ; j++)
        {
            a.sum = p[i] + p[j];
            a.one = i;
            a.two = j;
            q.push_back(a);
            time++;
        }
    }
    sort(q.begin(),q.end(),cmp);
    time--;
    for(int i = 0 ; i <= time ; i++)
    {
        while (q[i].sum + q[time].sum > x && time >= i)
        {
 
            time--;
        }
        if(q[i].sum + q[time].sum == x && q[i].one != q[time].one && q[i].two != q[time].two && q[i].two != q[time].one && q[i].one != q[time].two)
        {
            cout << q[i].one << " " << q[i].two << " " << q[time].one << " " << q[time].two;
            return 0;
        }
        if(i >= time)
        {
            break;
        }
    }
    cout << "IMPOSSIBLE";
}
