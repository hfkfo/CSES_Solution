#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,temp,sum = 0;
    vector<long long int>x;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        x.push_back(temp);
    }
    sort(x.begin(),x.end());
    for(int i = 0; i < n; i++){
        if(x[i] > sum + 1){
            cout << sum + 1;
            return 0;
        }
        sum += x[i];
    }
    cout << sum + 1;
    return 0;
}