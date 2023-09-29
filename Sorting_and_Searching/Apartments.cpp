#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,k,temp,ans = 0,p = 0;
    cin >> n >> m >> k;
    vector<long long int> apartment;
    vector<long long int> applicants;
    map<long long int,long long int> choose;
    for(long long int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        applicants.push_back(temp);
    }
    for(long long int i = 0 ; i < m ; i++)
    {
        cin >> temp;
        apartment.push_back(temp);
    }
    sort(apartment.begin(),apartment.end());
    sort(applicants.begin(),applicants.end());
    for(int i = 0; i < n; i++){
        while(p < m && abs(apartment[p] - applicants[i]) > k && apartment[p] < applicants[i] + k) p++;
        if(p < m && abs(apartment[p] - applicants[i]) <= k){
            ans++;
            p++;
        }
    }
    cout << ans << endl;
}
