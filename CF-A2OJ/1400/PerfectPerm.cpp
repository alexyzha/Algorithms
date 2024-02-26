#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    if(n&1) cout << -1 << endl;
    else {
        vector<int> r(n,0);
        iota(begin(r),end(r),1);
        for(int i = 0; i < n; i+=2) { swap(r[i],r[i+1]); cout << r[i] << " " << r[i+1] << " "; }
        cout << endl;
    }
    return 0;
}