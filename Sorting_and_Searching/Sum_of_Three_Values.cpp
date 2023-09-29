#include <bits/stdc++.h>
using namespace std;
array<int, 5004> A;
map<int, int> M;
signed main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(M.find(x - A[i] - A[j]) != M.end())
            {
                cout << M[x - A[i] - A[j]] << " " << i << " " << j;
                return 0;
            }
        }
        M[A[i]] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
