#include <iostream>
#include <string>
using namespace std;

string solve(string s) {
    const string c = "hello";
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != c[j]) continue;
        j++;
        if(j == 5) return "YES";
    }
    return "NO";
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}