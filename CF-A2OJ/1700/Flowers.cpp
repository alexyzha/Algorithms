#include <iostream>
#include <algorithm>
using namespace std;
using schlong = unsigned long long;
static schlong mod = 1000000007;
schlong d[100005], s[100005]{0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    int n,k,bm=1; cin>>n>>k;
    while(n--) {
        int a,b; cin>>a>>b;
        schlong r = 0; d[0] = 1;
        if(b > bm) {
            for(int i = bm; i <= b; ++i) {
                d[i] = (d[i-1] + (i >= k ? d[i-k] : 0)) % mod;
                s[i] = (d[i]+s[i-1])%mod;
            }
            bm = b;
        }
        cout << (s[b]+mod-s[a-1]+mod)%mod << endl;
        bm = max(b,bm);
    }
    return 0;
}

/*
3 2 n,k
1 3 length min length max
2 3
4 4

for k = 2, need 2 W, so WW. Could be R

1: 1 ------------> R
- R: 1
- W: 0

2: 3 ------------> WW, RR
- R: from 1, +1
- W: from 0, +1

3: 3 ------------> RWW, WWR, RRR
- R: from 3-1 = 2, +2
- W: from 3-k = 1, +1

Therefore total is just the sum from 1-3, since you can eat any amount in between those numbers

*/