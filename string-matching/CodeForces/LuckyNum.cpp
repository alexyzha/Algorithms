#include <iostream>
#include <string>
using namespace std;

#ifndef N
#define N
const short L[12] = {4,7,47,74,444,447,474,744,477,747,774,777};
#endif

string solve(short n) {
    for(short i = 0; i < 12; i++) {
        if(n % L[i] == 0) return "YES"; 
    }
    return "NO";
}

int main() {
    short in;
    cin >> in;
    cout << solve(in) << endl;
    return 0;
}