#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int in[200005] = {-1}, dif[200005] = {-1,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int c; cin >> c; cin >> in[1];
        for(int i = 2; i <= c; ++i) {
            cin >> in[i];
            if(in[i-1] == in[i]) dif[i] = dif[i-1];
            else dif[i] = i-1;
        }
        int q; cin >> q;
        while(q--) {
            int x, y; cin >> x >> y;
            if(dif[y] < x) cout << "-1 -1\n";
            else cout << dif[y] << " " << y << endl;
        }
    }
    return 0;
}