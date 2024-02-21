#include <cstdio>
#include <limits.h>
using namespace std;

int main() {
    int n,k,t[2]{-1},mj=INT_MIN;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf("%d%d",&t[0],&t[1]);
        int tj=t[1]>k?t[0]-(t[1]-k):t[0];
        if(tj>mj) mj=tj;
    }
    printf("%d\n",mj);
    return 0;
}