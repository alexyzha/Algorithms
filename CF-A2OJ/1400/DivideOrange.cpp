#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k,t,m,it=1,v[905]{0};
    vector<int> s[31];
    cin>>n>>k;
    m=n*k;
    for(int i=1;i<=k;i++) {
        cin>>t;
        s[i].push_back(t); 
        v[t]=1;
    }
    for(int i=1;i<=m;i++) {
        if(v[i]) continue;
        s[it++].push_back(i);
        if(it > k) it = 1;
    }
    for(int i=1;i<=k;i++) {
        for(const auto& i : s[i]) cout << i << " ";
        cout << endl;
    }
    return 0;
}