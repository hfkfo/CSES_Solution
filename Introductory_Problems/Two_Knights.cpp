#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int power,all,del;
    cin >> n ; 
    for(int i = 1 ; i <= n ; i++)
    {
        power = i*i;
        all = power * (power - 1) / 2;
        del = 4 * (i - 1) * (i - 2);
        cout << all -del << endl;
    }
}
