//https://codeforces.com/problemset/problem/126/B SOLVED WITH MAP + P_QUEUE + Z FUNCTION

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
using namespace std;


unordered_map<int,vector<int>> CHAD_Z(string s) {
    int n = s.size(), L = 0, R = 0;
    vector<int> Z(n,0);
    unordered_map<int,vector<int>> RET;
    for(int i = 1; i < n; i++) {
        if(i < R) Z[i] = min(R-i,Z[i-L]);
        while(i + Z[i] < n && s[Z[i]] == s[Z[i]+i]) {
            RET[Z[i]].push_back(i);
            Z[i]++;
        }
        if(i + Z[i] > R) {
            R = i + Z[i];
            L = i;
        }
        if(Z[i]) RET[Z[i]].push_back(i);
    }
    return RET;
}


string solve(string in) {
    unordered_map<int,vector<int>> Z = CHAD_Z(in);
    auto comp = [](const pair<int,vector<int>>& a, const pair<int,vector<int>>& b) { return a.first < b.first; };
    priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, decltype(comp)> Q(comp);
    for(auto& p : Z) Q.push(p);

    int n = in.size();
    while(Q.size()) {
        if(Q.top().second.size() < 2) {
            Q.pop();
            continue;
        }
        int first = Q.top().first, last = Q.top().second[Q.top().second.size()-1];
        if(last + first < n) {
            Q.pop();
            continue;
        }
        return in.substr(0,first);
    }
    return "Just a legend";
}


int main() {
    string in;
    cin >> in;
    cout << solve(in) << endl;
    return 0;
}