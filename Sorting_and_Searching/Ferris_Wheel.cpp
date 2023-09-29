#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,temp,ans = 0,end;
    vector<int>p;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }
    sort(p.begin(),p.end());
    end = n - 1;
    for(int i = 0 ; i <= end ; i++)
    {
        while( end > i )
        {
            if( p[i] + p[end] <= x )
            {
                end--;
                break;
            }
            end--;
            ans++;
        }
        ans++;
    }
    cout << ans << endl;
}
