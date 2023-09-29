#include<bits/stdc++.h>
using namespace std;
  
int n, q, a[200005], t, b, c, in[200005], idx, out[200005];
long long bit[200005];
vector <int> v[200005];
  
void dfs(int x, int pre){
    idx++;
    in[x] = idx;
    for (auto i:v[x]){
        if (i == pre) continue;
        dfs(i, x);
    }
    out[x] = idx;
}
long long query(int x){
    long long ret = 0;
    while (x){
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}
void update(int x, int d){
    while (x <= n){
        bit[x] += d;
        x += x & (-x);
    }
}
  
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++){
        cin >> b >> c;
        v[b].push_back(c);
        v[c].push_back(b);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++){
        update(in[i], a[i]);
    }
    while (q--){
        cin >> t;
        if (t == 1){
            cin >> b >> c;
            update(in[b], c-a[b]);
            a[b] = c;
        }
        else{
            cin >> b;
            cout << query(out[b])-query(in[b]-1) << "\n";
        }
    }
}
