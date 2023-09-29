#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,temp,max,min = -1;
    vector<int> a,b;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    b = a;
    max = n - 1;
    sort(b.begin(),b.end());
    for(int i = 0 ; i <= max ; i++)
    {
        while( b[i] + b[max] > x)
        {
            max--;
        }
        if(b[i] + b[max] == x && i != max && max > 0)
        {
            min = i;
            break;
        }
    }
    if(min != -1)
    {
        auto max_place = find(a.begin(),a.end(),b[max]);
        *max_place = 0;
        auto min_place = find(a.begin(),a.end(),b[min]);
        cout << distance(a.begin(), min_place) + 1 << " " << distance(a.begin(), max_place) + 1 << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
