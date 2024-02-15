/*
    What i learned:
    - double hashing
    - using scanf instead of iostream for codeforces q's
    - space optimization and also how little space arrays take up
    - "brute force" + hashing method for this type of hashing q

    **Double hashing**
    **Smarter hashing**
*/


#include <utility>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long SCHLONG;

char s[1501];
char b[27];
pair<SCHLONG, SCHLONG> p[2260000];
const SCHLONG B1 = 31;
const SCHLONG B2 = 131;
const SCHLONG S1 = 5381;
const SCHLONG S2 = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    scanf("%s%s",s,b);
    int n = 0, k;
    scanf("%d",&k);
    for(int i=0;s[i];i++) {
        int ct = 0; SCHLONG H1 = S1, H2 = S2;
        for(int j=i;s[j];j++) {
            if(b[s[j]-'a'] == '0') ct++;
            if(ct > k) break;
            H1 = H1 * B1 + s[j];
            H2 = H2 * B2 + s[j];
            p[n++] = make_pair(H1,H2);
        }
    }
    sort(p,p+n);
    printf("%d\n",int(unique(p,p+n)-p));
    return 0;
}


/* Original, failed:
#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector<int> M(26);
const uint64_t MOD = 1e9+7;
const uint BASE = 26;

int solve(string s, const uint extra) {
    set<uint64_t> U;
    uint bad = M[s[0]-'a'] == 1 ? 0 : 1,
         left = 0,
         right = 1,
         S_SIZE = s.size(),
         POWER = 0;
    
    vector<uint64_t> RM(S_SIZE,1);
    for(int i = 1; i < S_SIZE; i++) RM[i] = (RM[i-1] * BASE) % MOD;
    
    uint64_t HASH = s[0]-'`';
    
    while(right < S_SIZE && left < S_SIZE) {
        cout << s.substr(left,right-left) << " : " << HASH << " : " << U.count(HASH) << endl;

        bad += M[s[right]-'a'] == 1 ? 0 : 1;
        
        HASH = (((HASH * BASE) % MOD) + (s[right]-'`')) % MOD;
        
        POWER++;
        
        while(bad > extra && left < right) {
            uint64_t REM = (s[left]-'`' * RM[POWER]) % MOD;
            HASH = (HASH+MOD-REM) % MOD;
            POWER--;
            if(M[s[left]-'a'] == 0) bad--;
            left++;
        }
        right++;
        U.insert(HASH);
    }
    return U.size();
}

int main() {
    string s;
    int e;
    cin >> s;
    for(int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        M[i] = c-'0';
    }
    cin >> e;
    cout << solve(s,e) << endl;
    return 0;
}
*/