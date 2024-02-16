#include <limits.h>
#include <string>
#include <iostream>
using namespace std;

#pragma GCC optimize("03")
typedef uint64_t SCHLONG;
static int __star = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    string minWindow(string s, string t) {
        //s in t
        int ss = s.size(), tt = t.size();
        if(ss < tt) return "";
        if(ss == 1) return s == t ? s : "";
        int T[60] = {0}; int S[60] = {0};
        for(int i = 0; i < tt; i++) T[t[i]-'A']++;
        int left = 0, right = 0, minsize = INT_MAX, rl = 0, rr = 0;
        SCHLONG STRD = 0, RLG = 0;
        for(int i = 0; i < 60; i++) { if(T[i] > 0) STRD |= (1ULL << i); }
        while(left < ss && right < ss) {
            int r = s[right]-'A';
            if(T[r]) {
                S[r]++;
                if(S[r] == T[r]) RLG |= (1ULL << r);
            }
            while(STRD == RLG) {
                if(right-left+1 < minsize) minsize = right-left+1, rl = left, rr = right;
                int l = s[left]-'A';
                if(T[l]) {
                    S[l]--;
                    if(S[l] < T[l]) RLG &= ~(1ULL << l);
                }
                left++;
            }
            right++;
        }
        return minsize == INT_MAX ? "" : s.substr(rl,rr-rl+1);
    }
};