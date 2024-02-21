#include <iostream>
#include <string>
using namespace std;

string r(const string& s) {
    int d=0;
    for(const auto& c : s) if(c == '7' || c == '4') d++;
    return d==7||d==4 ? "YES\n" : "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    std::cin.tie(NULL), std::cout.tie(NULL);
    string s;
    cin >> s;
    cout << r(s);
    return 0;
}