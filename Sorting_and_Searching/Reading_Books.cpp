#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,book,sum = 0,max = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> book;
        sum += book;
        if(max < book)
        {
            max = book;
        }
    }
    if( 2*max < sum)
    {
        cout << sum;
    }
    else
    {
        cout << 2*max;
    }
}
