#include<iostream>
using namespace std;
int main()
{
    int n,temp;
    cin >> n;
    if(n < 4 && n!=1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if(n == 1)
    {
        cout << n << endl;
    }
    else
    {
        if( n % 2 == 1)
        {
            temp = n - 1;
            while(temp != 2)
            {
                cout << temp << " ";
                temp = temp - 2;
            }
            cout << temp << " ";
            while (n != 1)
            {
                cout << n << " ";
                n = n - 2;
            }
            cout << n << endl;
        }
        else
        {
            temp = 2;
            while (temp != n)
            {
                cout << temp << " ";
                temp+=2;
            }
            cout << temp << " ";
            temp = 1;
            while(temp != n - 1)
            {
                cout << temp << " ";
                temp += 2;
            }
            cout << temp << endl;
        }
    }
}
