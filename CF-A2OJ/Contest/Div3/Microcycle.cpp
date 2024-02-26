#pragma GCC optimize("03")
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int M = 1000005;

struct onion {
    vector<int> h,p;
    onion(const int& n) {
        h.resize(n,0),p.resize(n,0);
        iota(begin(p),end(p),0);
    }

    int find(const int& n) {
        if(p[n] == n) return n;
        return p[n] = find(p[n]);
    }

    bool join(const int& x, const int& y) {
        int px = find(x), py = find(y);
        if(px == py) return 0;
        if(h[px] < h[py]) swap(px,py);
        if(h[px] == h[py]) h[px]++;
        p[py] = px;
        return 1;
    }
};

vector<int> r, path;
bool f;

void dfs(int curr, int prev, const int end, vector<vector<int>>& g) {
    path.push_back(curr);
    if(curr == end) {
        f = 1;
        r = path;
        return;
    }
    for(auto& i : g[curr]) {
        if(i != prev) dfs(i,curr,end,g);
        if(f) return;
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    int t, n, m, u, v, w; cin >> t;
    while(t--) {
        cin >> n >> m;
        onion O(n+1);
        set<int> cyc;
        while(m--) {
            cin >> u >> v >> w;


            if(u > v) swap(u,v);
            if(!O.con(u,v)) { //if con then closed cyc
                O.h[v] = min(w,O.h[v]);
                O.join(u,v);
            } else {
                int r = O.find(u);
                cyc.insert(r);
                O.h[r] = min(O.h[r],w);
            }



        }
        int rw = M, ri = 0, rn = 0;
        for(auto& i : cyc) if(O.h[i] < rw) ri = i, rw = O.h[i];
    }
    return 0;
}