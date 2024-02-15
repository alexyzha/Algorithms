#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef M
#define M 
const int MAP[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0};
#endif

string solve(string s) {
    string r = "";
    for(int i = 0; i < s.size(); i++) {
        char c = tolower(s[i]);
        if(MAP[c-'a']) continue;
        else r.push_back('.'), r.push_back(c);
    }
    return r;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}