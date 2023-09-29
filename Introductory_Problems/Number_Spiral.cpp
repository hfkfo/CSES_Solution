#include<iostream>
using namespace std;
int main()
{
    long long int t,y,x,temp,ans = 0;
    cin >> t;
    for(int i = 0; i < t ; i++)
    {
        cin >> x >> y;
        if(y > x)
        {
            if (y % 2 == 1)
            {
                ans  = y * y;
                cout << ans - x + 1 << endl;
            }
            else
            {
                ans = (y - 1) * (y - 1) + 1;
                cout << ans + x - 1 << endl;
            }
 
        }
        else
        {
           if (x % 2 == 0)
            {
                ans  = x * x;
                cout << ans - y + 1 << endl;
            }
            else
            {
                ans = (x - 1) * (x - 1) + 1;
                cout << ans + y - 1 << endl;
            }
        }
    }
}