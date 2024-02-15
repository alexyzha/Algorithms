#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string solve(string t) {
    string r = "";
    int it = 0;
    while(it < t.size()) {
        if(t[it] == '.') {
            r.push_back('0');
            it++;
        } else {
            r.push_back(t[it+1] == '.' ? '1' : '2');
            it+=2;
        }
    }
    return r;
}

int main() {
    string t;
    cin >> t;
    cout << solve(t) << endl;
    return 0;
}