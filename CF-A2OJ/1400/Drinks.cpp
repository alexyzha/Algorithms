#include <cstdio>
using namespace std;
using db = double;

int main() {
    int n,t;
    scanf("%d",&n);
    db r=0.0,d=n;
    while(n--) { scanf("%d",&t); r+=t; }
    r/=d;
    printf("%lf",r);
    return 0;
}