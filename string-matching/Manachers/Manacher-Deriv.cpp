#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    using str = string;
    str c, s = "$";
    cin >> s;
    for(const char& z : c) s.push_back(z), s.push_back('$');
    cout << s << endl;
    int n = s.size(), it = 1;
    vector<int> M(n+1,1);
    //main loop
    while(it < n) {
        bool c = 1;
        while(s[it+M[it]] == s[it-M[it]]) M[it]++;
        if(M[it] > 1) for(int i = 1; i < M[it]; i++) {
            if(M[it-i] + i <= M[it]) {
                M[it+i] = M[it-i];
                it += i;
                c = 0;
                break;
            } else M[it+i] = min(M[it-i],M[it]-i);
        }
        if(c) it += M[it];
        if(it + M[it] == n) break;
    }
    //print
    for(int i = 1; i < it-1; i++) cout << M[i] << " ";
    cout << endl;
    return 0;
}