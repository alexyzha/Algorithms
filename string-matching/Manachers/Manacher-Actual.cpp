// much more simplified manacher template 
#include <vector>
#include <string>
using namespace std;

// parity-independent 
vector<int> MANA(const string& c) {
    string s = "$";
    for(const char& z : c) s.push_back(z), s.push_back('$');
    s = "#" + s + "%";
    int n = s.size();
    vector<int> p(n);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r-i, p[l+(r-i)]));
        while(s[i-p[i]] == s[i+p[i]]) p[i]++;
        if(i + p[i] > r) l = i-p[i], r = i+p[i];
    }
    return vector<int>(begin(p)+1, end(p)-1);
}


//parity independent fixed:
vector<int> MANA(const string& t) {
    string s;
    for(auto c : t) s += string("#") + c;
    s.push_back('#');
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n+2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) p[i]++;
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}