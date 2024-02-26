#include <iostream>
#include <set>
using namespace std;

static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();

int main() {
    int n; cin >> n;
    while(n--) {
        int a, b, k, t; cin >> a >> b >> k;
        set<int> A,B,C;
        for(int i = 0; i < a; ++i) { cin >> t; if(t <= k) A.insert(t), C.insert(t); }
        for(int i = 0; i < b; ++i) { cin >> t; if(t <= k) B.insert(t), C.insert(t); }
        if(A.size()*2 >= k && B.size()*2 >= k && C.size() == k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}