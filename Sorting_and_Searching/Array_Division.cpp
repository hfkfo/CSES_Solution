#include<bits/stdc++.h>
using namespace std;
vector<long long int> p;
long long int cost(long long int n,long long int max)
{
    long long int k = 1 , sum = 0;
    for(long long int i = 0 ; i < n ; i++)
    {
        if(p[i] > max)
        {
            return 1000000000;
        }
        if(sum + p[i] > max)
        {
            k++;
            sum = 0;
        }
        sum += p[i];
    }
    return k;
}
int main()
{
    long long int n,k,temp,left = 0,right = 200000000000000,mid;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    while(left != right)
    {
        mid = (left + right) / 2;
        if(cost(n,mid) > k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    cout << left;
}
