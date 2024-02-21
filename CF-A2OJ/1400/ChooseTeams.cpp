#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n,k,in,ct=0,t[3],it=0;
    scanf("%d%d",&n,&k);
    auto comp = [](const int& a, const int& b) { return a > b; };
    priority_queue<int,vector<int>,decltype(comp)> q(comp);
    while(n--) { scanf("%d",&in); q.push(in); }
    while(!q.empty()) {
        t[it%3] = q.top()+k; q.pop();
        if(it%3 == 2) { if(t[0] <= 5 && t[1] <= 5 && t[2] <= 5) ct++; }
        it++;
    }
    printf("%d\n",ct);
    return 0;
}

// im actually dumb and this didnt need a queue at all