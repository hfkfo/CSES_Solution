#include<bits/stdc++.h>
using namespace std;
vector<long long int>p;
long long int judge(long long int n,long long int mid)
{
    long long int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans += abs(p[i] - mid);
    }
    return ans;
}
int main()
{
    long long int n,temp,sum = 0,ans = 0,mid,right,left;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        p.push_back(temp);
        sum += temp;
    }
    left = 1;
    right = sum;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(judge(n,mid) < judge(n,mid + 1))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << judge(n,left) << endl;
}
