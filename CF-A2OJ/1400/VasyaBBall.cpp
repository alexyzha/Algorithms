#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    int n,m,t,r1,r2,i,j,d,r[2];
    cin >> n; i = n-1;
    vector<int> one, two;
    while(n--) { cin >> t; one.push_back(t); }
    cin >> m; j = m-1;
    while(m--) { cin >> t; two.push_back(t); }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    d = max(one.back()+1,two.back()+1), r1 = 2*(i+1), r2 = 2*(j+1), r[0] = 0, r[1] = INT_MAX;
    while(d--) {
        while(d < one[i] && i >= 0) r1++, i--;
        while(d < two[j] && j >= 0) r2++, j--;
        if(r1-r2 >= r[0]-r[1]) r[0] = r1, r[1] = r2;
    }
    cout << r[0] << ":" << r[1] << endl;
    return 0;
}