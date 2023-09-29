#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,judge,temp,except;
    cin >> n;
    judge = n*(n+1)/2;
    if(judge % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES" << endl;
        judge = judge / 2;
        for(long long int i = 1 ; i <= n ; i++)
        {
            if( i*(i+1)/2 >= judge)
            {
                temp = i;
                break;
            }
        }
        except = temp*(temp + 1)/2 - judge;
        if(except == 0)
        {
            cout << temp << endl;
            for(long long int i = 1 ; i <= temp ; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            cout << n - temp << endl;
            for(long long int i = temp + 1 ; i <= n ; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << temp - 1 << endl;
            for(long long int i = 1 ; i <= temp ; i++)
            {
                if( i != except)
                {
                    cout << i << " ";
                }
            }
            cout << endl;
            cout << n - temp + 1 << endl;
            cout << except << " ";
            for(long long int i = temp + 1 ; i <= n ; i++)
            {
                cout << i << " ";  
            }
            cout << endl;
        }
    }
}
