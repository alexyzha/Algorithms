#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string n1,n2,p,r="YES\n";
    cin >> n1 >> n2 >> p;
    int m[26]{0};
    for(auto& c : n1) m[c-'A']++;
    for(auto& c : n2) m[c-'A']++;
    for(auto& c : p) m[c-'A']--;
    for(int i = 0; i < 26; i++) if(m[i]) r = "NO\n";
    cout << r;
    return 0;
}