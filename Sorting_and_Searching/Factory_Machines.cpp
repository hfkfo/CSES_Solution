#include<bits/stdc++.h>
using namespace std;
vector<long long int> p;
long long int BS(long long int n,long long int k)
{
    long long int left = 0,right = 1000000000000000000/n,mid,sum;
    right += right / n;
    while(left != right)
    {
        mid = (right + left)/2;
        sum = 0;
        for(long long int i = 0 ; i < n ; i++)
        {
            sum += mid/p[i];
        }
        if(sum >= k)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    long long int n,t,temp;
    cin >> n >> t;
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    cout << BS(n,t);
}
