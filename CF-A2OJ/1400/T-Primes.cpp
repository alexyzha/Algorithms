#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using schlong = unsigned long long;

bool p(const schlong& n) {
    int m = sqrt(n), p = ceil(sqrt(n));
    if(m != p) return 0;
    if(m <= 2) return m-1;
    int o = ceil(sqrt(m));
    for(int i = 2; i <= o; ++i) { if(!(m%i)) return 0; }
    return 1;
}

int main() {
    int n; cin >> n;
    schlong t;
    bool r;
    while(n--) {
        cin >> t;
        cout << (p(t) ? "YES\n" : "NO\n");
    }
    return 0;
}