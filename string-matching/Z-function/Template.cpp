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