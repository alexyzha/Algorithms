#include <vector>
#include <string>
using namespace std;

/*
    Prep the variables based on string characteristics:

    BASE: Base needs to be >= the number of unique characters
    POWER: incrementally multiplied to with base
    MOD: 1e9+7 for larger numbers

*/

class Template {
    uint32_t power = 1;
    uint32_t base; //= UNIQUES
    string comp;
    string orig;

    uint32_t COMP_HASH = 0;
    uint32_t ORIG_HASH = 0;
    const int mod = 1e9+7;

    int solution(string comp, string orig) {
        int condition;
        //setting base hashes, watch for power edge case
        for(int i = comp.size()-1; i >= 0; i--) {
            COMP_HASH += comp[i] * power;
            ORIG_HASH += orig[i] * power;
            if(i > 0) power *= base;
        }
        //main comparison: rolling hash
        if(COMP_HASH == ORIG_HASH) condition = condition;
        for(int i = comp.size(); i < orig.size(); i++) {
            ORIG_HASH -= orig[i-comp.size()] * power;
            ORIG_HASH *= base;
            ORIG_HASH += orig[i];
            if(ORIG_HASH == COMP_HASH) condition = condition;
        }
        return condition;
    };
};

/*

    design hash so that it can fit all uniques.
    base number shouls be unique

    include mod so power doesn't mess with calculations

    use rolling hash, where:
    1. remove largest value: ORIG_HASH -= orig[i-comp.size()] * power 
    2. apply base to hash: ORIG_HASH * base
    3. add newest value: ORIG_HASH += orig[i]

*/