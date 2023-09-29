#include<iostream>
using namespace std;
int main()
{
    long long int n,count = 0;
    cin >> n;
    long long int x[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> x[i];
        if(i > 0)
        {
            if(x[i] < x[i-1])
            {
                count += x[i-1] - x[i];
                x[i] = x[i-1];
            }
        }
    }
    cout << count << endl;
}