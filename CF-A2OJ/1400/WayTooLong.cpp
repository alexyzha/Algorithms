#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[101];
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s[i];
        int c=s[i].size();
        if(c>10) cout << s[i][0] << c-2 << s[i][c-1] << endl;
        else cout << s[i] << endl;
    }
    return 0;
}