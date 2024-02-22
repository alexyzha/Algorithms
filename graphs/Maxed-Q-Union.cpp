#include <vector>
using namespace std;

struct qunion {
public:
    vector<int> h;
    vector<int> p;
    qunion(int n) {
        h.resize(n,1);
        p.resize(n,0);
        for(int i = 0; i < n; i++) p[i] = i;
    }

    int find(const int& i) {
        if(p[i] == i) return i;
        return p[i] = find(p[i]);
    }

    void join(const int& x, const int& y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(h[px] > h[py]) p[py] = px;
        else if(h[px] < h[py]) p[px] = py;
        else p[py] = px, h[px]++;
    }

    bool con(const int& x, const int& y) { return find(x) == find(y); }
};