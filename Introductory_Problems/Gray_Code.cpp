#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < pow(2,n) ; i++)
    {
        int binary[20]= {0};
        int first = n - 1;
        int now = i;
        while( now != 0)
        {
            binary[first] = now % 2;
            now = now / 2;
            first--;
        }
        for(int j = 0 ; j < n ; j++)
        {
            if( j == 0)
            {
                if(binary[j] == 0)
                {
                    cout << "0";
                }
                else if(binary[j] == 1)
                {
                    cout << "1";
                }
            }
            else
            {
                if(binary[j] == binary[j - 1])
                {
                    cout << "0";
                }
                else
                {
                    cout << "1";
                }
            }
        }
        cout << endl;
    }
}
