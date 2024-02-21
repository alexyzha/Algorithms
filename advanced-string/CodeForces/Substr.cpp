#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[300005], dp[300005];
char s[300005] = {'#'};
int n,m,ret,r[300005],CT,x,y;

int main() {
    scanf("%d%d%c",&n,&m,s+1);
    while(--m) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    queue<int> q;
    for(int i = 1; i <= n; dp[i++].resize(26,0)) if(!r[i]) q.push(i);
    for(;q.size();++CT) {
        int p = q.front();
        ++dp[p][s[p]-'a'];
        q.pop();
        ret = max(ret,*max_element(dp[p].begin(),dp[p].end()));
        for(auto& i : v[p]) {
            for(int j = 0; j < 26; ++j) dp[i][j] = max(dp[i][j],dp[p][j]);
            if(!--r[i]) q.push(i);
        }
    }
    if(CT != n) printf("%d",ret);
    else printf("-1\n");
}
