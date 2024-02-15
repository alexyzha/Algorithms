#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solve(string s1, string s2) {
    for(int i = 0; i < s1.size(); i++) {
        if(toupper(s1[i]) == toupper(s2[i])) continue;
        else if(toupper(s1[i]) > toupper(s2[i])) return 1;
        else if(toupper(s1[i]) < toupper(s2[i])) return -1;
    }
    return 0;
}
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1,s2) << endl;
    return 0;
}