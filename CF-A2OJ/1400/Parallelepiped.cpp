#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    cout << 4*(sqrt(x*z/y) + sqrt(y*x/z) + sqrt(z*y/x)) << endl;
    return 0;
}