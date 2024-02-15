#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    string s;
    int a;
    cin >> s >> a;
    vector<int> V(26,0);
    int m = INT_MIN;
    for(int i = 0; i < 26; i++) {
        cin >> V[i];
        m = max(V[i],m);
    }
    int ret = 0, n = s.size();
    for(int i = 0; i < n; i++) ret += (i+1) * V[s[i]-'a'];
    for(int i = 1; i <= a; i++) ret += m * (n+i);
    cout << ret << endl;
    return 0;
}