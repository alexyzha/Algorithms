#include <string>
#include <iostream>
using namespace std;
typedef uint32_t mediumpp;

int main() {
    string s; cin >> s;
    mediumpp mask = 0;
    for(const auto& c : s) mask |= (1U << (c-'a'));
    if(__builtin_popcount(mask)%2) cout << "IGNORE HIM!\n";
    else cout << "CHAT WITH HER!\n";
    return 0;
}