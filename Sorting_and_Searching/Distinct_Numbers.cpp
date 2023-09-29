#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,temp,value = 0;
    cin >> n;
    map<long long int ,long long int> x;
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        if( x[temp] == 0)
        {
            value++;
            x[temp]++;
        }
        else
        {
            x[temp]++;
        }
    }
    cout << value << endl;
}
