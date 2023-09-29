#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b;
    cin >> t;
    for(int i = 0 ; i < t ; i++)
    {
        int dif;
        cin >> a >> b;
        if( a > b)
        {
            dif = a - b;
            a = a - 2*dif;
            b = b - dif;
        }
        else if( a < b )
        {
            dif = b - a;
            b = b - 2*dif;
            a = a - dif;
        }
        if( a >= 0 && b >= 0)
        {
            if( a % 3 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
