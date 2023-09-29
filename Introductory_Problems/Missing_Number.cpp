#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n,number;
    map<int,int>list;
    cin >> n;
    for(int i = 1 ; i <= n -1 ; i++)
    {
        cin >> number;
        list[number] = 1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(list[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }
}