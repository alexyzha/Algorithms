// leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/description

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        //converting everything to strings
        string cmp = "", og = "";
        auto c = [](int i) -> char {return i > 0 ? '+' : i < 0 ? '-' : '0'; };
        for(auto i : pattern) cmp.push_back(c(i));
        for(int i = 1; i < nums.size(); i++) og.push_back(c(nums[i]-nums[i-1]));
        vector<int> ptable(pattern.size(),0);
        //setting table
        int j = 0;
        for(int i = 1; i < cmp.size(); i++) {
            while(j > 0 && cmp[i] != cmp[j]) j = ptable[j-1];
            if(cmp[i] == cmp[j]) j++;
            ptable[i] = j;
        }
        int ct = 0;
        j = 0;
        //calculations
        for(int i = 0; i < og.size(); i++) {
            while(j > 0 && og[i] != cmp[j]) j = ptable[j-1];
            if(og[i] == cmp[j]) j++;
            if(j == cmp.size()) {
                ct++;
                j = ptable[j-1];
            }
        }
        return ct;
    }
};