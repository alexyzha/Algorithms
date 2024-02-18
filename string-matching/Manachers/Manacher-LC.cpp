#pragma GCC optimize("03")
#include <iostream>
using namespace std;
static int __star = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestPalindrome(const string& c) {
        string s = "$";
        for(const char& z : c) s.push_back(z), s.push_back('$');
        int n = s.size(), it = 1, r = 0;
        vector<int> M(n,1);
        while(it < n) {
            bool c = 1;
            while((it+M[it] < n && it-M[it] >= 0) && s[it+M[it]] == s[it-M[it]]) M[it]++;
            if(M[r] < M[it]) r = it;
            if(M[it] > 1) for(int i = 1; i < M[it]; i++) {
                if(M[it-i] + i <= M[it]) {
                    M[it+i] = M[it-i];
                    it += i;
                    c = 0;
                    break;
                } else M[it+i] = min(M[it-i],M[it]-i);
            }
            if(c) it += M[it];
            if(it + M[it] == n) break;
        }
        string tmp = s.substr(r-M[r]+1,M[r]*2-1);
        string ret = "";
        for(const char& c : tmp) if(c != '$') ret.push_back(c);
        return ret;
    }
};