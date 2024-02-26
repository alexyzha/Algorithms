#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> let(3);
int sz;

int dp(const int& n, int cur, int s, int ct, vector<vector<int> >& d) {
    if(s > n) return 0;
    if(s == n) return ct;
    if(d[s][cur]) return d[s][cur];
    int r = 0;
    for(int i = cur; i < sz; i++) r = max(r,dp(n,i,s+let[i],ct+1,d));
    return d[s][cur] = r;
}

int main() {
    int n, s, ct=0; cin >> n >> let[0] >> let[1] >> let[2];
    sort(begin(let),end(let));
    if(let[2] == let[1]) let.pop_back();
    if(let[0] == let[1]) let.erase(let.begin());
    sz = let.size();
    vector<vector<int> > d(n+1,vector<int>(sz,0));
    int c = dp(n,0,0,0,d);
    cout << c << endl;
    return 0;
}