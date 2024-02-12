/*
    Example cases: 
    aaaaa -> [0,4,3,2,1]
    aaabaab -> [0,2,1,0,2,1,0]
    abacaba -> [0,0,1,0,3,0,1]
*/

/*
    Algorithm:
    To find z[i], if we are within the bounds of [L,R), this means that we've alreacdy checked this part of the string
    This measnt that, if R was able to make it this far, there must've been a match all the way up to R.
    If we are below R, we are at a smaller match in R. Therefore, we can use the value of R to determine Z[i]
    
    therefore:
    if(i < R) z[i] = min(r-i,z[i-l]);
    REMEMBER THIS LINE
    NEED TO COOK ON THIS
*/

#include <vector>
#include <string>
using namespace std;

class Template {

    vector<int> Z_FUNCTION(string s) { 
        int L = 0, R = 0, n = s.size();
        vector<int> Z(n,0);
        for(int i = 1; i < n; i++) {
            if(i < R) Z[i] = min(R-i,Z[i-L]);
            while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) Z[i]++;
            if(i + Z[i] > R) {
                L = i;
                R = i + Z[i];
            }
        }
        return Z;
    }

};

/*
    EXPLANATION:
––––––––––––––––––––––––––––––––
    Example:
    aabx gfda aabx
    0100 0001 4100
                ^
    the second aabx perfectly matches the first 4 letters of the string
    Therefore, z[8] = 4

    Now, L = 8 and R = 12.

    When we go to calculate z[9], we see that it's within the current window [L,R)

    Therefore, z[9] can be estimated to start as: min(r-i, z[i-l]). z[i-1] indicates the z-value  of the
    **matching letter in the prefix** which means:
    **the length prefix matching with the suffix starting from i-l**

    r-i is the right bound, and since these are all the letters we have explored so far, we should not increase past R.

    Therefore, if i is within the searched-already bound:
    preliminary z[i] = min(r-i, Z[i-l]);

    Then, we can continue to check after index (i + z[i])
    - when n = string.size()
    while(i+z[i] < n && s[z[i]] == s[z[i]+i]) z[i]++;

    - z[i] is the length of the longest matching suffix starting from index i
    - z[i] + i is the index of either the new R (farthest reach) or a non-match within R
    - z[i] will therefore equal the corresponding letter in the prefix

    Then, we push the bounds of R
    if(i + z[i] > R) {
        R = i + z[i];
        L = i;
    }

*/