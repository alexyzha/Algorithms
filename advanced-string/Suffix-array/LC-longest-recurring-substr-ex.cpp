#include <string>
#include <vector>
#include <iostream>
using namespace std;

#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

template <typename charT> struct SuffixArray {
    int n;
    vector<int> sa, rank, lcp;

    SuffixArray(const basic_string<charT> &s) : n(s.length() + 1), sa(n), rank(n), lcp(n) {
        vector<int> _sa(n), bucket(n);
        iota(sa.rbegin(), sa.rend(), 0);
        sort(next(sa.begin()), sa.end(), [&](int i, int j) { return s[i] < s[j]; });
        for (int i = 1, j = 0; i < n; ++i) {
        rank[sa[i]] = rank[sa[i - 1]] + (i == 1 || s[sa[i - 1]] < s[sa[i]]);
        if(rank[sa[i]] != rank[sa[i - 1]]) bucket[++j] = i; }
        for(int len = 1; len <= n; len += len) {
            for(int i = 0, j; i < n; ++i) {
                if ((j = sa[i] - len) < 0)
                j += n;
                _sa[bucket[rank[j]]++] = j;
            }
            sa[_sa[bucket[0] = 0]] = 0;
            for(int i = 1, j = 0; i < n; ++i) {
                if (rank[_sa[i]] != rank[_sa[i - 1]] || rank[_sa[i] + len] != rank[_sa[i - 1] + len])
                    bucket[++j] = i;
                    sa[_sa[i]] = j;
            }
            copy(sa.begin(), sa.end(), rank.begin());
            sa.swap(_sa);
            if(rank[sa[n - 1]] == n - 1) break;
        }
        for(int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
        while(k >= 0 && s[i] != s[sa[j - 1] + k]) lcp[j] = k--, j = rank[sa[j] + 1];
    }
};

class Solution {
public:
    string longestDupSubstring(const string& s) {
        SuffixArray<char> SA(s);
        int l = 0, p = 0;
        for(int i = 1; i < SA.n; i++) {
            if(SA.lcp[i] && SA.lcp[i] > l) l = SA.lcp[i], p = SA.sa[i];
        }
        return s.substr(p,l);
    }
};


//suffix array ew

//using biny search and RK rolling hash below:

#pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    using schlong = unsigned long long;
    const schlong base = 131;
    string longestDupSubstring(const string& s) {
        unordered_map<schlong,vector<int>> M;
        string ret;
        int l = 1, r = s.size();
        while(l != r) {
            int m = l + (r-l)/2, g = rk(s,m,M);
            if(g != -1) {
                ret = s.substr(g,m);
                l = m+1;
            } else r = m;
            M.clear();
        }
        return ret;
    }

    int rk(const string& s, const int& size, unordered_map<schlong,vector<int>> M) {
        schlong hash = 0, pow = 1;
        //prep hash
        for(int i = 0; i < size; i++) {
            hash = (hash*base)+s[i];
            if(i) pow *= base;
        }
        M[hash].push_back(0);
        int n = s.size()-size;
        for(int i = 0; i < n; i++) {
            hash = (hash-s[i]*pow)*base + s[i+size];
            M[hash].push_back(i+1);
        }
        for(auto& p : M) if(p.second.size() >= 2) return p.second[0];
        return -1;
    }
};

//biny search + RK hash