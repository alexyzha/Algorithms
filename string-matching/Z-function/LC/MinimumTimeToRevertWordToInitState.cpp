#pragma GCC optimize("03")
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int r = 1, n = word.size();
        vector<int> z = z_function(word);
        for(;k*r < n; r++) { if(z[k*r]+k*r >= n) return r; }
        return r;
    }

    vector<int> z_function(const string& s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i < r) z[i] = min(r-i,z[i-l]);
            while(i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
};
