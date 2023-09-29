#include <iostream>
using namespace std;
  
int n, x[200005], p, bit[200005];
  
void update(int x, int d){
    while (x <= n){
        bit[x] += d;
        x += x & (-x);
    }
}
int query(int x){
    int ret = 0;
    for (int i = 17; i >= 0; i--){
        if (ret+(1<<i) <= n && bit[ret+(1<<i)] < x){
            ret += (1<<i);
            x -= bit[ret];
        }
    }
    return ret+1;
}
  
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        update(i, 1);
    }
    for (int i = 1; i <= n; i++){
        cin >> p;
        int ret = query(p);
        cout << x[ret] << " ";
        update(ret, -1);
    }
    cout << "\n";
}
