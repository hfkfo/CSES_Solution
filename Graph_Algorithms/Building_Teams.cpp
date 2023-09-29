#include <bits/stdc++.h>
using namespace std;
array<vector<int>, 100004> G;
array<int, 100004> team;
bool dfs(int u, int t){
    team[u] = t;
    bool ok = 1;
    for(int v : G[u]){
        if(team[v]){
            if(team[v] == t) return 0;
            continue;
        }
        ok &= dfs(v, 3 - t);
    }
    return ok;
}
signed main(){
    int n, m, a, b;
    bool ans = 1;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!team[i]) ans &= dfs(i, 1);
    }
    if(ans){
        for(int i = 1; i <= n; i++){
            cout << team[i] << " ";
        }
    }else cout << "IMPOSSIBLE";
    return 0;
}
