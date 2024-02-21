/*
i:
2 3 4 1
2 got from 1
3 got from 2
4 got from 3
1 got from 4

o:
4 1 2 3
*/

#include <cstdio>
using namespace std;

int main() {
    int n,r[101]{0},t;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) {
        scanf("%d",&t);
        r[t]=i;
    }
    for(int i=1;i<=n;i++) printf("%d ",r[i]);
    return 0;
}