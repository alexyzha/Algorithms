#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n; 
    string s; cin >> n >> t >> s;
    auto awk = [&s,&n]() { for(int i = 0; i < n-1; i++) { if(s[i] == 'B' && s[i+1] == 'G') { swap(s[i],s[i+1]); i++; } } };
    while(t--) awk();
    cout << s << endl;
    return 0;
}